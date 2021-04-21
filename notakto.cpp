//Notakto


#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <iomanip>
using namespace std;

//using string to save board
//string transfer to list in rotate for rotate

//Char to int
int CharToInt(char x){
	int c = x - '0';
	return c;
}


//Initialize
void Initialize(vector<string> &board){
	string Alpha[3] = {"A","B","C"};
	string number = "123456789";
	for ( int i = 0; i < 3; i++ ){
		board.push_back(Alpha[i] + number);
	}
}

//Check whether input is legal
bool CheckInput(vector<string> board, char alpha, int numebr){
	for ( int i = 0; i < board.size(); i++ ){
		if ( board[i][0] == alpha && !isalpha(board[i][numebr]) )
			return true;
	}
	return false;
}

//Random import number
void Randomin(vector<string> &board){
	srand(time(NULL));
	char alpha[3] = {'A','B','C'};
	char al = alpha[rand() % 3];
	int num = rand() % 10;
	while ( !CheckInput(board, al, num) ){
		srand(time(NULL));
		al = alpha[rand() % 3];
		num = rand() % 10;
	}
	
	cout << "Computer chooses: " << al << num << endl;
	
	for ( int i = 0; i < board.size(); i++ ){
		if ( board[i][0] == al ){
			board[i][num] = 'X';
			return;
		}
	}
}

//readin and change the board
void Readin(vector<string> &board){
	string place;
	cout << "Choose the place: ";
	cin >> place;
	char alpha = place[0];
	int number = CharToInt(place[1]);
	while ( !CheckInput(board, alpha, number) ){
		cout << "Choose the place: ";
		cin >> place;
		alpha = place[0];
		number = CharToInt(place[1]);
	}
	
	for ( int i = 0; i < board.size(); i++ ){
		if ( board[i][0] == alpha ){
			board[i][number] = 'X';
			return;
		}
	}
}


//kill dead board
void KillDead(vector<string> &board){
	int searchplace[8][3] = { {1,2,3}, {4,5,6}, {7,8,9}, {1,4,7}, {2,5,8}, {3,6,9}, {1,5,9}, {7,5,3} };
	for (vector<string>::iterator n = board.begin(); n != board.end(); n++ ){
		for ( int i = 0; i < 8; i++ ){
			if ( (*n)[searchplace[i][0]] == 'X' && (*n)[searchplace[i][1]] == 'X' && (*n)[searchplace[i][2]] == 'X' ){
				board.erase(n);
				return;
			}
		}
	}
}


void PrintBoard(vector<string> board){
	
	for ( int i = 0; i < board.size(); i++ )
		cout << board[i][0] << "      ";
	cout << endl;
	for ( int p = 1; p < 9; p+=3 ){
		for ( int i = 0; i < board.size(); i++ ){
			cout << board[i][p] << ' ' << board[i][p+1] << ' ' << board[i][p+2] << "  ";
		}
		cout << endl;
	}
}


int Notakto() {
	vector<string> boards;
	Initialize(boards);
	PrintBoard(boards);
	while ( boards.size() ){
		Readin(boards);
		KillDead(boards);
		PrintBoard(boards);
		if ( !boards.size() )
			return 0;
		
		Randomin(boards);
		KillDead(boards);
		PrintBoard(boards);
		if ( !boards.size() )
			return 1;
	}
	return 0;
}