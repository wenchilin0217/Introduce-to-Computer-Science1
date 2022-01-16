#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <vector>
using namespace std;

int main(){
    char map[7][7];
    char dwarf[7][7];

    for(int i=0; i<7; i++){
        for(int j=0; j<7; j++){
            map[i][j] = '0';
        }
    }

    int n, m;
    cout<<"the index starts at (0,0)\n";
    cout<<"enter the first dwarf's position:";
    cin >> n >> m;
    dwarf[n][m] = 'D';

    int next_i = n+2;
    int next_j = m+1;

    for(int num = 0; num<6; num++){
        dwarf[next_i][next_j] = 'D';

        next_i = next_i +2;
        next_j = next_j +1;

        if(next_i >= 7){
            next_i = next_i - 7;
        }
        if(next_j >= 7){
            next_j = next_j - 7;
        }
    }
    

    cout<<"one of the solution is:\n";
    cout<<"  0 1 2 3 4 5 6"<<endl;
    for(int i=0; i<7; i++){
        for(int j=-1; j<7; j++){
            if( j == -1)    cout<< i <<" ";
            else if (dwarf[i][j] == 'D')     cout<<dwarf[i][j]<<" ";
            else            cout<<"  ";
        }
        cout<<endl;
    }

    system("pause");
    return 0;
}