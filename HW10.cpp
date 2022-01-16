#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <set>
using namespace std;

vector<vector<int>> table;
set<string> setOfLCS;

int max(int a, int b){
	return (a>b)? a:b;
}

string Reverse(string str){
	int low = 0;
	int high = str.length() - 1;
	while (low < high)
	{
		char temp = str[low];
		str[low] = str[high];
		str[high] = temp;
		++low;
		--high;
	}
	return str;
}

int lcs(int m, int n, string X, string Y){
	table = vector<vector<int>>(m+1,vector<int>(n+1));

	for(int i=0; i<m+1; ++i)
	{
		for(int j=0; j<n+1; ++j)
		{
			if (i == 0 || j == 0)
				table[i][j] = 0;

			else if(X[i-1] == Y[j-1])
				table[i][j] = table[i-1][j-1] + 1;

			else
				table[i][j] = max(table[i-1][j], table[i][j-1]);
		}
	}

	return table[m][n];
}

void traceBack(int i, int j, string lcs_str, string X, string Y){
	while (i>0 && j>0)
	{
		if (X[i-1] == Y[j-1])
		{
			lcs_str.push_back(X[i-1]);
			--i;
			--j;
		}
		else
		{
			if (table[i-1][j] > table[i][j-1])
				--i;
			else if (table[i-1][j] < table[i][j-1])
				--j;
			else
			{
				traceBack(i-1, j, lcs_str, X, Y);
				traceBack(i, j-1, lcs_str, X, Y);
				return;
			}
		}
	}
	
	setOfLCS.insert(Reverse(lcs_str));
}

int main(){
    /* ******************************** */
    //enter input file
    ifstream ifs;
    do{
        string fileName;        
        cout<<"enter file name: ";
        getline(cin, fileName);

        ifs.open(fileName.c_str());
        
        if(!ifs.is_open()){
            cout<<"Fail to open "<< fileName <<", please try again"<<endl;
        }
    }while(!ifs.is_open());
    
    /* ******************************** */
    //get string1 & string2
    string buff;
    vector<string> lines;

    while(getline(ifs, buff)){
        lines.push_back(buff);
    }

    ifs.close();

    /* ******************************** */
    //make lcs table
    string X = lines[0];    int m = X.length();
    string Y = lines[1];    int n = Y.length();
    int length = lcs(m, n, X, Y);
    string str;
    traceBack(m, n, str, X, Y);

    /* ******************************** */
    //Print Rules
    ofstream ofs;
    ofs.open("result_E24089046.txt");
    if(!ofs.is_open()){
        cout<<"Failed to open Dataset_Output file.\n";
        system("pause");
    }
    ofs<<length<<endl;

    set<string>::iterator beg = setOfLCS.begin();
    for(; beg != setOfLCS.end(); beg++){
        ofs<<*beg<<endl;
    }

    ofs.close();
    cout<<"====over====";
    return 0;
}