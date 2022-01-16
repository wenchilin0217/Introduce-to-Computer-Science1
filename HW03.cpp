#include <iostream>
#define N 48
using namespace std;

int fibo(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }

    return (fibo(n-1)+fibo(n-2));
}

int main(){
    while(1>0){
        char arr[N] = {0};
        int s = 0;

        cout<<"Please enter a number: ";
        cin>> arr;
        
        int i = 0;
        while(arr[i] != '\0'){
            if(arr[i] >= '0' && arr[i] <= '9'){
                s = s*10 + arr[i] - '0';
            }else{
                s = -1;
                break;
            }   ++i;
        }

        if(s<0){
            cout<<"Please try again.";
        }else{
            for(int j=0 ;j<=s ;j++){
                cout<<fibo(j)<<" ";
            }
            cout<<endl;
        }
    }
}