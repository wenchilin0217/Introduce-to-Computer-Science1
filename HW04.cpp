#include <iostream>
#include <stdlib.h> //atoi
#include <time.h>   //rand
#include <string>
#define N 10
using namespace std;

int main(){
    int check;
    string input;
    int inputnumber;
    int guess[N];
    int a, b, count;

    cout << "Game Start!\n";

    //generate a 4-digit code
    int numbers[] = {0,1,2,3,4,5,6,7,8,9};
    srand(time(NULL));
    const int ArraySize = sizeof(numbers) / sizeof(numbers[0]);
    for(int n=0; n<ArraySize; n++){//swap all the number in arraySize, the first 4 numbers are the code
        int pos = rand() % ArraySize;
        swap(numbers[n],numbers[pos]);
    }

    for (count=0; count <10 ;count++){
        //Fool proof
        do{
            check = 1;
            for(int x=0; x<4 ;x++){
                guess[x] = 0;
            }
            cout<<"Please enter a 4 digit number: ";
            cin >> input;
            inputnumber = atoi(input.c_str());

            guess[0] = inputnumber / 1000;
            guess[1] = inputnumber / 100 % 10;
            guess[2] = inputnumber / 10 % 10;
            guess[3] = inputnumber % 10;

            if(inputnumber == 0 || inputnumber >= 10000 || guess[0]==guess[1] || guess[0]==guess[2] || guess[0]==guess[3] || guess[1]==guess[2] ||guess[1]==guess[3] ||guess[2]==guess[3]){
                cout<<"Wrong data-type, please try again.";
                check = 0;
            }
        }while(check = 0);

        //count numbers of A, B
        a = b = 0;
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                if(numbers[i] == guess[j]){
                    if(i == j){
                        a++;
                    }else{
                        b++;
                    }
                }
            }
        }
        if(a ==4){
            cout<<"Bingo!\n";
            break;
        }else{
            cout<<": "<< a <<"A"<< b <<"B"<< endl;
        }
    }
    
    if(count == 10){
        cout<<"You lose.  The correct answer is: ";
        for(int i=0; i<4; i++){
            cout << numbers[i];
        }
        cout << endl;        
    }
    system("pause");
    return 0;
}