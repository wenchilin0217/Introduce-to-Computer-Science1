#include <iostream>
#define N 24   //字串最大長度為24
using namespace std;

int main(){
    while(1>0){
        char arr[N] = {0};
        int s = 0;

        cout<<"Please enter a number between 0 to 5: ";
        cin>> arr;
        
        int i = 0;
        while(arr[i] != '\0'){
            if(arr[i] >= '0' && arr[i] <= '9'){
                s = s*10 + arr[i] - '0';
            }else{
                s = 9;
                break;
            }   ++i;
        }

        switch(s){
            case 0:
                cout<<"=======================================\n";
                cout<<"|   Name: Rin                         |\n";
                cout<<"|   Birthday: 1998/02/17              |\n";
                cout<<"=======================================\n";                
            break;
            case 1:cout<<"*";break;
            case 2:cout<<"**";break;
            case 3:cout<<"***";break;
            case 4:cout<<"****";break;
            case 5:cout<<"*****";break;
            default:cout<<"Wrong data type, please try again.";break;
        }
        cout<<endl;
    }
}