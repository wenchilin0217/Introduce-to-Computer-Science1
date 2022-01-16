#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <map>

using namespace std;

map<string, int> ItemFrequency;

struct Node{
    string name;
    int count;

    Node *parent;
    map<string, Node*> children;

    Node(string name, Node* parent, int count):name(name),parent(parent),count(count){
        children.clear();
    }
};

struct Rule{
    string target;
    vector<string> rules;
};

vector<Rule> FinalRules;

void InsertNodes(vector<string> Task, Node* current, vector<pair<string, Node*> >& NodeTable){
    for(int i=0; i<Task.size(); i++){
        Node *new_node = new Node(Task.back(), current, 1);
        NodeTable.push_back (make_pair(Task.at(i), new_node));
        current->children.insert (pair<string, Node*>(Task.at(i), new_node));
        current = new_node;
    }
}

void combRule(string * ptr, int n, vector<string> &result){
    if(ptr == NULL){
        return;
    }
    if(n == 0){
        return;
    }
    result.push_back(*ptr);
    combRule(ptr + 1, n-1, result);
    result.pop_back();
    combRule(ptr+1, n, result);
}

void FindRule(double minConfidence, vector<Rule>& FinalRules, vector<pair<string, int> > FrequencyTable , vector<pair<string, Node*> >& NodeTable){
    map<string, int> confidence;
    int count = 0;
    while(!FrequencyTable.empty()){
        string temp = FrequencyTable.back().first;
        for(int i=0; i<NodeTable.size(); i++){
            if(NodeTable.at(i).first == temp){
                Node* temp_node = NodeTable.at(i).second;
                count++;

                while(temp_node->parent != NULL){
                    Node* temp_partent = temp_node->parent;
                    ++ confidence[temp_partent->name];
                    temp_partent = temp_partent->parent;
                }
            }
        }
        for(map<string, int>::iterator it = confidence.begin(); it != confidence.end(); it++){
            double min_count = minConfidence * count;
            vector<string> v;
            if(it->second >= min_count){
                v.push_back(it->first);
            }
        }
        FrequencyTable.pop_back();
    }
}

bool SortRecord(string a, string b){
    int i = ItemFrequency.at(a);
    int j = ItemFrequency.at(b);
    return i > j;
}

bool SortTable_cmp(pair<string, int> a, pair<string, int> b){
    return a.second < b.second;
}

bool SortTable(map<string, int>& M){
    vector<pair<string, int> > A;

    for(auto& it : M){
        A.push_back(it);
    }
    sort(A.begin(), A.end(), SortTable_cmp);
}

int main() {
    vector<pair<string, Node*> > NodeTable;

    /* ******************************** */
    //get data
    ifstream ifs;
    ifs.open("Dataset.txt");
    if(!ifs.is_open()){
        cout<<"Fail to open Dataset file.\n";
        system("pause");
    }

    string buff;
    vector<vector<string>> transactions;
    map<string, int> Item;

    int num = 0;   

    while(getline(ifs,buff)){
        buff.erase(0,6);
        stringstream ss(buff);
        string dir;
        vector<string> temp;
        while(getline(ss, dir, ',')){
            temp.push_back(dir);
            ++Item[dir];
        }
        transactions.push_back(temp);
        num++;
    }
    
    ifs.close();

    /* ******************************** */
    double min_support_ratio;
    cout<<"enter min_support: ";
    cin >> min_support_ratio;
    double minSupport = min_support_ratio * num;

    double min_confidence_ratio;
    cout<<"enter min_confiedence: ";
    cin >> min_confidence_ratio;
    double minConfidence = min_confidence_ratio * num;

    /* ******************************** */
    //Get FrequencyTable
    for(auto i = Item.begin(); i != Item.end(); i++){
        if(i->second >= minSupport){
            ItemFrequency.insert(pair<string, int> (i->first, i->second));
        }
    }

    //Sort FrequencyTable
    vector<pair<string, int> > FrequencyTable;
    for(auto it = ItemFrequency.begin(); it != ItemFrequency.end(); it++){
        FrequencyTable.push_back(make_pair(it->first, it->second));
    }

    sort(FrequencyTable.begin(), FrequencyTable.end(), SortTable_cmp);
    reverse(FrequencyTable.begin(), FrequencyTable.end());

    /* ******************************** */
    //Cut Transactions == Record
    vector<vector<string>> Record;
    for(int i=0; i<transactions.size(); i++){
        vector<string> temp = transactions.at(i);
        vector<string> keep;
        for(int j=0; j<temp.size(); j++){
            string s = temp.at(j);
            if(ItemFrequency.count(s) == 1){keep.push_back(s);}
        }
        //Sort keep
        if(!keep.empty()){
            sort(keep.begin(), keep.end(), SortRecord);
            Record.push_back(keep);
        }
    }
    transactions.clear();

    /* ******************************** */
    //Built FP-Tree
    //BuildTree(Record);
    Node *Root = new Node("", NULL, 1);

    while(!Record.empty()){
        Node *current = Root;
        vector<string> Task = Record.back();

        while(!Task.empty()){
            if(current->children.empty()){
                InsertNodes(Task, current, NodeTable);
                Task.clear();
            }else if(!current->children.count(Task.back())){
                InsertNodes(Task, current, NodeTable);
                Task.clear();
            }else{//current has temp as a children
                Node *next_node = current->children.find(Task.back())->second;
                next_node->count ++;
                current = next_node;
                Task.pop_back();
            }
        }
        Record.pop_back();
    }

    /* ******************************** */
    //Mine Tree
    vector<Rule> FinalRules;
    

    /* ******************************** */
    //Print Rules
    ofstream ofs;
    ofs.open("Dataset_Output.txt");
    if(!ofs.is_open()){
        cout<<"Failed to open Dataset_Output file.\n";
        system("pause");
    }
    ofs<<"num of rules:"<<FinalRules.size()<<endl;    
    
    vector<Rule>::iterator iter = FinalRules.begin();
    for(iter ; iter != FinalRules.end(); iter++){
        for(int i=0; i<iter->rules.size(); i++){
            ofs<<iter->rules.at(i)<<" ";
        }
        ofs<<"=> "<<iter->target<<endl;
    }
    FinalRules.clear();

    ofs.close();
}