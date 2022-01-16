#include <iostream>
#include <stack>
#define N 4
using namespace std;

int n, key, steps=0;
stack<int> A,B,C;

void solution(int n, char A, char B, char C){
    if(n > 0){
        solution(n-1, 'A', 'C', 'B'); 
        cout<<"Move disk no."<<n<<"from"<<A<<"to"<<C<<endl;
        solution(n-1, 'B', 'A', 'C');   
    }
}
void printStack(stack<int> s){
    if(s.empty())   return;
    int x = s.top();
        s.pop();
        printStack(s);  //recursive
        if(x != 0)  cout<<x<<" ";
        s.push(x);
}
void printTower(int step){
    cout<<"Step["<<step<<"] show the Tower:"<<endl;

    cout<<"A[ ";
    printStack(A);
    cout<<"]"<<endl;

    cout<<"B[ ";
    printStack(B);
    cout<<"]"<<endl;

    cout<<"C[ ";
    printStack(C);
    cout<<"]"<<endl;
    cout<<"---------------------------------------\n";
    steps++;
}

void move(char from,char des){
    int i, j;

    if(from == 'A'){
        if(des == 'B'){
            i = A.top();
            j = B.top();

            if(B.top() == 0){
                B.pop();    //pop 0
                A.pop();
                B.push(i);
            }else if(i<j){
                A.pop();
                B.push(i);
            }else{
                cout<<"Large discs cannot be placed on top of small discs\n";
            }
        }else if(des == 'C'){
            i = A.top();
            j = C.top();

            if(C.top() == 0){
                C.pop();
                A.pop();
                C.push(i);
            }else if(i<j){
                A.pop();
                C.push(i);
            }else{
                cout<<"Large discs cannot be placed on top of small discs\n";
            }
        }
    }else if(from == 'B'){
        if(des == 'A'){
            i = B.top();
            j = A.top();

            if(A.top() == 0){
                A.pop();
                B.pop();
                A.push(i);
            }else if(i<j){
                B.pop();
                A.push(i);
            }else{
                cout<<"Large discs cannot be placed on top of small discs\n";
            }
        }else if(des =='C'){
            i = B.top();
            j = C.top();

            if(B.top() == 0){
                C.pop();
                B.pop();
                C.push(i);
            }else if(i<j){
                B.pop();
                C.push(i);
            }else{
                cout<<"Large discs cannot be placed on top of small discs\n";
            }
        }
    }else if(from == 'C'){
        if(des == 'A'){
            i = C.top();
            j = A.top();

            if(A.top() == 0){
                A.pop();
                C.pop();
                A.push(i);
            }else if(i<j){
                C.pop();
                A.push(i);
            }else{
                cout<<j<<i<<"Large discs cannot be placed on top of small discs\n";
            }
        }else if(des =='B'){
            i = C.top();
            j = B.top();

            if(B.top() == 0){
                B.pop();
                C.pop();
                B.push(i);
            }else if(i<j){
                C.pop();
                B.push(i);
            }else{
                cout<<j<<i<<"Large discs cannot be placed on top of small discs\n";
            }
        }
    }
    printTower(steps);
}

int main(){
    cout<<"=======================================\n";
    cout<<"Tower of Honoi：\n";
    cout<<"(1)Only one disk may be moved at a time\n";
    cout<<"(2)Large discs cannot be placed on top of small discs\n";
    cout<<"Goal: Move all the discs from A to C\n";
    cout<<"=======================================\n";

    //起始設置
    while(true){
        char arr[N];
        cout<<"Before game start, please enter the number of discs:";
        cin>> arr;
        n = atoi(arr);
        if(n != 0)  break;
    }
    for(int i=n; i>0; i--){
        A.push(i);     
    }
    printTower(steps);

    cout<<"enter 9：print all the steps\n";
    cout<<"enter 8：play by yourself\n";

    while(true){
        cout<<"What do want to do next？：";        
        cin >> key;

        switch (key){
            case 9:
                cout<<"=======================================\n";
                cout<<"Solution：\n";
                solution(n,'A','B','C');
                break;
            case 8:
                cout<<"=======================================\n";
                cout<<"Input type：AB   (Both in capital, move the disc from A to B)"<<endl;
                while(true){
                    char from, des;
                    if(A.empty())   A.push(0);
                    if(B.empty())   B.push(0);
                    if(C.empty())   C.push(0);

                    while(true){
                        char str[N];
                        cout<<"Please move the disc：";
                        cin >> str;
                        if( 'A' <= str[0] && str[0] <= 'C'){
                            from = str[0];
                            if( 'A' <= str[1] && str[1] <= 'C'){
                                des = str[1];     //make sure both capital;
                                break;
                            }
                        }
                        cout<<"Wrong Data-type"<<endl;
                    }

                    move(from, des);
                    if(C.size() == n){
                        break;
                    }
                };
                    cout<<"You win!"<<endl;
                break;
            default:
                cout<<"Wrong Data-type";
            }
    }
    

}