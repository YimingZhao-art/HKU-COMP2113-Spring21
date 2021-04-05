#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


bool GUESS() {
	srand(time(NULL));
	int x = rand() % 10;
	int temps = 4;
	int guess;
	while ( temps > 0){
		cout << "Guess a number from 0-9:\n";
		cout << "Your have " << temps << " attempts left." << endl;
		cin >> guess;
		if ( guess == x )
			{
				cout << "Nice!" << endl;
				return true;
			}
	}
	return false;
}

void print(char array[][3]){
	for (int i = 0; i < 3; i ++){
		for (int j =0; j < 3; j++){
			cout << array[i][j] << ' ';
		}
		cout << endl;
	}
}

bool check(char array[][3], char x) {
	//search col
	for ( int i = 0; i < 3; i++ ){
		if ( array[i][0] == x && array[i][1] == x  && array[i][2] == x )
			return true;
	}
	//search row
	for ( int i = 0; i < 3; i++ ){
		if ( array[0][i] == x && array[1][i] == x  && array[2][i] == x )
			return true;
	}
	
	if ( array[0][0] == x && array[1][1] == x  && array[2][2] == x )
		return true;

	
	if ( array[0][2] == x && array[1][1] == x  && array[2][0] == x )
		return true;

	return false;
}


char win(char array[][3]){
	if ( check(array,'X') )
		return 'X';
	else if ( check(array,'O') )
		return 'O';
	
	
	char status ='n';
	for (int i = 0; i < 3; i ++)
		for (int j =0; j < 3; j++)
			if (array[i][j] == 'N')
				status = 'y';
	if ( status == 'n' )
		return 'P';
	return 'N';
}

bool Tic_Tac_Toe() {
	char array[3][3];
	for (int i = 0; i < 3; i ++)
		for (int j =0; j < 3; j++){
			array[i][j] = 'N';
		}
	
	print(array);
	
	int row, col;
	while ( win(array) == 'N' ){
		
		cout << "Choose the row and col you want to: ";
		cin >> row >> col;
		array[row][col] = 'X';
		print(array);
		if ( win(array) == 'X' ) return true;
		
		
		srand(time(NULL));
		row = rand()%3, col = rand()%3;
		while ( array[row][col] != 'N' ){
			srand(time(NULL));
			row = rand()%3, col = rand()%3;
		}
		array[row][col] = 'O';
		print(array);
		if ( win(array) == 'O' )
			return false;
		else if ( win(array) == 'P' )
			return false;
	}
		
	
	
	return false;
}


int main(){
	Tic_Tac_Toe();
}