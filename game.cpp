#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <string>
#include <cctype>
#include <iomanip>
#include <vector>



using namespace std;

//read nothing, return true if won
bool GUESS() {
	cout << "-------------------------------------------------------------------\n";
	cout << "This is a game to guess a number from 0-9. You will win 10 golds and 5 train.\n";
	srand( time( NULL ) );
	int x = rand() % 10;
	int temps = 4;
	int guess;
	while ( temps > 0){
		cout << "Guess a number from 0-9: \n";
		cout << "Your have " << temps << " attempts left." << endl;
		cin >> guess;
		temps --;
		if ( guess == x )
			{
				cout << "Nice!" << endl;
				return true;
			}
	}
	return false;
}

//read a board and print the board
void print(char array[][3]){
	cout << "-----" << endl;
	for (int i = 0; i < 3; i ++){
		for (int j =0; j < 3; j++){
			cout << array[i][j] << ' ';
		}
		cout << endl;
	}
	cout << "-----" << endl;
}

//read a board and user, return whether the user win
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

//read a board, check whether the game is over. 'X' the player win, 'O' the computer, 'P' means nobody win
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

//read nothing, return wether win
bool Tic_Tac_Toe() {
	cout << "-------------------------------------------------------------------\n";
	cout << "This is a tic-tac-toe game. You will win 10 golds and 5 train.\n";
	cout << "You can only put you X on the N.\n";
	char array[3][3];
	for (int i = 0; i < 3; i ++)
		for (int j =0; j < 3; j++){
			array[i][j] = 'N';
		}
	
	print(array);
	
	int row, col;
	while ( win(array) == 'N' ){
		
		cout << "Choose the row and col you want to(example: 2 1 means row 3 colume 2): ";
		cin >> row >> col;
		
		while ( array[row][col] != 'N' ){
			cout << "Choose the row and col you want to(example: 2 1 means row 3 colume 2): ";
			cin >> row >> col;
		}
		array[row][col] = 'X';
		print(array);
		if ( win(array) == 'X' ) 
			return true;
		
		srand( time( NULL ) );
		row = rand() % 3, col = rand() % 3;
		while ( array[row][col] != 'N' ){
			srand( time( NULL ) );
			row = rand() % 3, col = rand() % 3;
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

//A game: scissors paper rock.
//Output: Whether win or not.
bool scissors_paper_rock()
{
	cout << "-------------------------------------------------------------------\n";
	cout << "This is a scissors-paper-rock game. You will win 10 golds and 5 train.\n";
	cout << "In this 3-round game you need to win at least 2 rounds to win\n";
	int wintime = 0;
	for ( int i = 1; i <= 3; i++)
	{
		cout << "-------------------------------------------------------------------\n";
		cout << "Round: "<<i<<endl;
		cout << "Please input the number of your choice\n";
		cout << "1.Paper\n2.Scissors\n3.Rock\n";
		int c1, c2; //The choice of user and computer;
		cin>>c1;
		while( c1 < 1 || c1 > 3)
		{
			cout<<"Wrong input, try again.\n";
			cin>>c1;
		}
		srand(time(NULL)); 
		c2 = ( rand() % 3 ) + 1;
		cout << "You choose: ";
		if( c1 == 1)
			cout << "Paper ";
		else if( c1 == 2)
			cout << "Scissors ";
		else
			cout << "Rock ";
		cout << "Computer choose: ";
		if( c2 == 1)
			cout << "Paper\n";
		else if( c2 == 2)
			cout << "Scissors\n";
		else
			cout << "Rock\n";
		
		if( c1 == 1)
		{
			if(c2 == 1)
			{
				cout << "It's a draw, this round will not be count\n";
				i--;
			}
			else if( c2 == 2)
			{
				cout << "You lose this round\n";
			}
			else
			{
				cout << "You win this round\n";
				wintime++;
			}
		}

		else if( c1 == 2)
		{
			if(c2 == 2)
			{
				cout << "It's a draw, this round will not be count\n";
				i--;
			}
			else if( c2 == 3)
			{
				cout << "You lose this round\n";
			}
			else
			{
				cout << "You win this round\n";
				wintime++;
			}
		}
		else
		{
			if(c2 == 3)
			{
				cout << "It's a draw, this round will not be count\n";
				i--;
			}
			else if( c2 == 1)
			{
				cout << "You lose this round\n";
			}
			else
			{
				cout << "You win this round\n";
				wintime++;
			}
		}
		if(wintime == 2)
		{
			cout<<"You win the game.\n";
			return 1;
		}
		if(wintime == 0 && i == 2)
		{
			cout<<"You lose the game.\n";
			return 0;
		}
	}
	if(wintime < 2)
	{
		cout<<"You lose the game.\n";
		return 0;
	}
}
