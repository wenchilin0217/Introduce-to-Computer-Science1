#include <iostream>
#include <string>
using namespace std;

struct playerInfo {
	string Name;
	char ID;
};

playerInfo playerOne, playerTwo;
int table[6][7];
int again, steps;

void displayBoard(){
    /* ******************** */
	//outline top
	cout<<"  ";
	for(int i=1 ;i<=7; i++){cout<<" "<<i<<" ";}
	cout<<"  "<<endl;

	cout<<"  ";
	for(int i=1 ;i<=7; i++){cout<<"===";}
	cout<<"  "<<endl;

    /* ******************** */
	
	//board data
	for(int i=0; i<6; i++){
		cout<<"||";
		for(int j=0; j<7; j++){
			cout<<" "<<char(table[i][j])<<" ";
		}
		cout<<"||"<<endl;
	}

    /* ******************** */
	//outline bottom
	cout<<"  ";
	for(int i=0; i<7; i++){cout<<"===";}
    cout<<endl;

    cout<<"/ ";
    for(int i=0; i<7; i++){cout<<"---";}
    cout<<" \\"<<endl;
}

int dropChoice(playerInfo activePlater){
	int choice; 
	do{
		cout<<"player "<<activePlater.Name<<", please enter a column number to draw: ";
		cin >> choice;

		while(table[0][choice-1] == 'X' || table[0][choice-1] == 'O'){
			cout<<"The row is full, please enter another row: ";
            cin >> choice;
		}

	}while(choice < 1 || choice > 7);

	return (choice);
}

int checkBelow(int dropchoice, playerInfo activePlater){
	int height = 5;
	bool check = false;
	while(check == false){
		if(table[height][dropchoice-1] == '*'){
			table[height][dropchoice-1] = activePlater.ID;
			check = true;
		}else {
			height--;
		}
	}
	return height;
}

bool checkWin(playerInfo activePlayer){
	bool win = false;
	char Line = activePlayer.ID;

	for(int i=0; i<6; i++){
		for(int j=0; j<7; j++){
			//anchor (i, j)

			/*	
				-- anchor --
				/	  |	  \
			*/

			//left 4 
			if(table[i][j] == Line && table[i][j-1] == Line && table[i][j-2] == Line && table[i][j-3] == Line){
				win = true;
				goto mark;
			}
			//right 4
			if(table[i][j] == Line && table[i][j+1] == Line && table[i][j+2] == Line && table[i][j+3] == Line){
				win = true;
				goto mark;
			}
			//down 4
			if(table[i][j] == Line && table[i+1][j] == Line && table[i+2][j] == Line && table[i+3][j] == Line){
				win = true;
				goto mark;
			}
			//down left
			if(table[i][j] == Line && table[i+1][j-1] == Line && table[i+2][j-2] == Line && table[i+3][j-3] == Line){
				win = true;
				goto mark;
			}
			//down right
			if(table[i][j] == Line && table[i+1][j+1] == Line && table[i+2][j+2] == Line && table[i+3][j+3] == Line){
				win = true;
				goto mark;
			}

		}
	}

	mark: return win;
}

void reset(){
	int option;
	cout<<"Play with computer or Play with friend? Computer(1) Friend(2): ";
	cin >> option;

	cout<<"Enter 1st Player's name: ";
	cin >> playerOne.Name;
	playerOne.ID ='X';

	switch(option){
		case 2:
			cout<<"Enter 2nd Player's name: ";
			cin >> playerTwo.Name;
			playerTwo.ID = 'O';				
			break;
		case 1:
			playerTwo.Name = "Computer";
			playerTwo.ID = 'O';
			break;
	}

	again = 0;
	steps = 0;

	for(int i=0; i<6; i++){
		for(int j=0; j<7; j++){
			table[i][j] = '*';
		}
	}
	cout<<"=======Game start!======="<<endl;
	displayBoard();
}

int restart(){
	int again;
	cout<<"Would you like to restart?  Yes(1) No(2): ";
	cin >> again;

	if(again == 1){
		reset();	//again == 0
	}else {			//again == 2
		cout<<"Good bye."<<endl;
	}

	return again;
}

int computerDrop(){
	int scoretable[7][8] = {0};

	/*	-3   -1   -3
		  \   |   /
		-2--Anchor--2
		  /   |   \
		-1    0   -1
	*/
	for(int i=5; i>=0; i--){
		for(int j=0; j<7; j++){
			if(table[i][j] == 'X'){
				//up
				if(table[i-1][j] == '*'){
					scoretable[i-1][j] = -1;
				}
				//right
				if(table[i][j+1] == '*'){
					scoretable[i][j+1] = scoretable[i+1][j+1]-1;
				}
				//left
				if(table[i][j-1] == '*'){
					scoretable[i][j-1] = scoretable[i+1][j-1]-1;
				}
				//down right
				if(table[i+1][j+1] == '*'){
					scoretable[i+1][j+1] = scoretable[i+2][j+1]-1;
				}
				//down left
				if(table[i+1][j-1] == '*'){
					scoretable[i+1][j-1] = scoretable[i+1][j-1]-1;
				}
				//up right
				if(table[i-1][j+1] == '*'){
					scoretable[i-1][j+1] = scoretable[i][j+1]-1;
				}
				//up left
				if(table[i-1][j-1] == '*'){
					scoretable[i-1][j-1] = scoretable[i][j-1]-1;
				}
			}
		}
	}

    int colscore[7] = {0};
	//count sum of column score
    for(int j=0; j<7; j++){
        int temp = 0;

		
        for(int i=0; i<6; i++){
            temp  += scoretable[i][j];
        }
        if(temp == 0){
            colscore[j] = -10;
        }else{
            colscore[j] = temp;
        }
    }
	//count max of column score
	int bestchoice = 0;
	int maxscore = colscore[0];
	for(int j=1; j<7; j++){
		if(colscore[j] > maxscore){
			maxscore = colscore[j];
			bestchoice = j;
		}
	}
	cout<<"Computer drop column"<<(bestchoice+1)<<endl;

	return bestchoice+1;
}

int main(){
	//init and start
	reset();

	do {
		/* ******************** */
		//playerOne go
		int dropOne = dropChoice(playerOne);
		int heightOne = checkBelow(dropOne,playerOne);
		displayBoard();
			steps++;
		if( checkWin(playerOne) == true ){
			cout<<playerOne.Name<<" Win!"<<endl;

			again = restart();
		}

		/* ******************** */
		//playerTwo go
		int dropTwo;
		if(playerTwo.Name == "Computer"){
			dropTwo = computerDrop();
		} else{
			dropTwo = dropChoice(playerTwo);
		}
		checkBelow(dropTwo, playerTwo);
			displayBoard();
				steps++;
		
		if( checkWin(playerTwo) == true ){
			cout<<playerTwo.Name<<" Win!"<<endl;
			
			again = restart();
		}

		/* ******************** */
		//check full
		if(steps == 42){
			cout<<"The board is full, it is a draw."<<endl;
			
			again = restart();
		}
	}while(again != 2);

	return 0;
}