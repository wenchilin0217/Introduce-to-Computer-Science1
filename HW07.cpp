#include <iostream>
#include <cstdio>
#include <algorithm>
#include <time.h>
using namespace std;

int main(){
    cout<<"program start!"<<endl;
    srand(time(NULL));
    int cell = 10;
    int floor = -10;
    int m, n;

        cout<<"enter the row and col of the matrix: ";
        cin >> n >> m;

    
    
    
    int ** array;
    array = new int *[n];
    for(int i=0; i<n; i++){
        array[i] = new int [m];
    }

    cout<<"enter 1 to enter the content of the matrix by yourself"<<endl;
    cout<<"enter 2 to enter the content of the matrix automaticly"<<endl;
    int key;
    while(true){
        char arr[4];
        cout<<"please enter 1 or 2: ";
        cin >> arr;
        key = atoi(arr);
        if(key == 1 || key == 2) break;      
    }

    if (key == 1){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> array[i][j];
            }
        }        
    }
    if (key == 2){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int x = rand() % (cell - floor + 1) + floor;
                array[i][j] = x;
            }
        }
    }

    cout<<"the martix is : "<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<array[i][j]<<" ";
        }
        cout<<endl;
    }

    int max = 0;
    for(int size=1; size<=min(n,m); size++){
        for(int top=0; top<(n - size+1); top++){
            for(int left=0; left<(m - size+1); left++){
                int temp = 0;
                for(int p=top; p<(top + size); p++){
                    for(int q=left;q<(left + size);q++){
                        temp = temp + array[p][q];
                    }
                }
                if(temp > max){
                    max = temp;
                }
            }
        }
    }

    cout << "max: " << max <<endl;

    for(int i=0; i<n; i++)
        delete [] array[i];
    delete [] array;
    
    return 0;
}