//MineSweeping

//dynamic 2D array
//an entry store int > 10 and < 20 means it's revealed
//0,8-means no revealed and how many mines around, 9 means there is a mine
//an entry store int > 19 means it is tagged

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>
using namespace std;


int **  GetMap(int &length, int &width, int ** Map);

bool CheckPlace(int * P, int num, int size);
void SetMines(const int length, const int width, int ** Map);

char PrintEntry(int i, int j, int ** Map);
void PrintMap(const int length, const int width, int ** Map);

void area(int i, int j, int ** Map, int ** Area);
void GetInfo(const int length, const int width, int ** Map);
void Clean0(int ** Map,const int length, const int width );
void Clean1(int i, int j, int ** Map,const int length, const int width );
bool Status(int ** Map, int length, int width);


bool Play(const int length, const int width, int ** Map);
bool Win(const int length, const int width, int ** Map);

bool MineSweep() {
	int length, width;
	int ** Map;
	Map = GetMap(length, width, Map);
	SetMines(length, width, Map);
	GetInfo(length, width, Map);
	PrintMap(length, width, Map);
	
	while ( Play(length, width, Map) ){
		//change the closing
		system("clear");
		PrintMap(length, width, Map);
	}
	
	if ( Win(length, width, Map) )
		return true;
	return false;
}


//                                                Initial part
int ** GetMap(int &length, int &width, int  ** Map){
	cout << "Choose the length( >= 5): " << endl;
	cin >> length;
	cout << "Choose the width:( >= 5): " << endl;
	cin >> width;
	
	while ( length < 5 || width < 5 ){
		cout << "Choose the length( >= 5): " << endl;
		cin >> length;
		cout << "Choose the width:( >= 5): " << endl;
		cin >> width;
	}
	
	//Remove the side incovenience
	Map = new int * [width + 2];
	for ( int i = 0; i < width + 2; i++ ){
		Map[i] = new int [length + 2];
	}
	
	for ( int i = 0; i < width + 2; i++ ){
		for ( int j = 0; j < length + 2; j++ ){
			Map[i][j] = 0;
		}
	}
	return Map;
}


//                     set Mine part
bool CheckPlace(int * P, int num, int size){
	for ( int i = 0; i < size; i++ ){
		if ( P[i] == num )
			return false;
	}
	return true;
}

void SetMines(const int length, const int width, int ** Map){
	int Mines;
	Mines = sqrt(length * width);
	cout << "There are " << Mines << " mines." << endl;
	
	int * MineX = new int [Mines];
	int * MineY = new int [Mines];
	
	for ( int i = 0; i < Mines; i++ )
		MineX[i] = 0;
	for ( int i = 0; i < Mines; i++ )
		MineY[i] = 0;
	
	srand(time(NULL));
	int x , y;
	for ( int i = 0; i < Mines; i++ ){
		x = rand() % length + 1, y = rand() % width + 1;
		
		while ( !CheckPlace(MineX, x, Mines) ){
			x = rand() % length + 1;
		}
		
		while ( !CheckPlace(MineY, y, Mines) ){
			y = rand() % width + 1;
		}
		MineX[i] = x;
		MineY[i] = y;
	}
	
	for ( int i = 0; i < Mines; i++ ){
		Map[MineY[i]][MineX[i]] = 9;
	}

}


//                   Print part
char PrintEntry(int i, int j, int ** Map){
	char output;
	if ( Map[i][j] >= 10 && Map[i][j] < 20){
		output = '0' + ( Map[i][j] % 10 );
	}
		
	else if ( Map[i][j] > 19 ){
		output = '#';
	}
	else
		output = ' ';
	return output;
}

void PrintMap(const int length, const int width, int ** Map){
	cout << "   X";
	for ( int i = 1; i <= length; i++ )
		cout << setw(2) << i << "  ";
	cout << "\n";
	cout << setw(2) << 'Y' << "\n";
	
	
	for ( int i = 1; i <= width; i++ ){
		cout << setw(2) << i << "   ";
		for ( int j = 1; j <= length; j++ )
			cout << PrintEntry(i, j, Map) << "   ";
		cout << "\n\n";
	}
}


void area(int i, int j, int ** Map, int ** Area){
	Area[0] = &Map[i-1][j-1];
	Area[1] = &Map[i-1][j];
	Area[2] = &Map[i-1][j+1];
	Area[3] = &Map[i][j-1];
	Area[4] = &Map[i][j+1];
	Area[5] = &Map[i+1][j-1];
	Area[6] = &Map[i+1][j];
	Area[7] = &Map[i+1][j+1];
}


void GetInfo(const int length, const int width, int ** Map){
	for ( int i = 1; i <= width; i++ ){
		for ( int j = 1; j <= length; j++ ){
			if ( Map[i][j] == 9 )
				continue;
			int ** Area = new int * [8];
			area(i, j, Map, Area);
			for ( int n = 0; n < 8; n++ ){
				if ( *Area[n] == 9 )
					Map[i][j]++;
			}
			delete [] Area;
		}
	}
}

bool Win(const int length, const int width, int ** Map){
	int Mines;
	Mines = sqrt(length * width);
	int count = 0;
	for ( int i = 1; i < width + 1; i++ ){
		for ( int j = 1; j < length + 1; j++ ){
			if ( Map[i][j] == 29 )
				count++;
		}
	}
	if ( count == Mines )
		return true;
	return false;
}

bool Play(const int length, const int width, int ** Map){
	if ( Win(length, width, Map) ){
		cout << "You win!!!\n";
		return false;
	}
	int command;
	cout << "Choose the mode: \n";
	cout << "0. Exit\n";
	cout << "1. Press\n";
	cout << "2. Tag\n";
	cout << "3. Untag\n";
	cin >> command;
	while ( command > 3 || command < 0 ){
		cout << "Choose the mode: \n";
		cout << "0. Exit\n";
		cout << "1. Press\n";
		cout << "2. Tag\n";
		cout << "3. Untag\n";
		cin >> command;
	}
	
	if ( command == 0 )
		return false;
	int x, y;
	cout << "Input x and y: ";
	cin >> x >> y;
	
	if ( command == 1 ){
		while ( Map[y][x] > 9){
			cout << "Input x and y: ";
			cin >> x >> y;
		}
		while ( (x < 0 || x > length) || (y < 0 || y > width) ){
			cout << "Input x and y: ";
			cin >> x >> y;
		}
		
		if ( Map[y][x] == 9 ){
			cout << "You lose!\n";
			return false;}
		
		Map[y][x] += 10;
		Clean1(y, x, Map, length, width);
		
		while ( Status(Map, length, width)){
			Clean0(Map, length, width);
		}
	}
	
	else if ( command == 2 ){
		while ( Map[y][x] > 19 ){
			cout << "Input x and y: ";
			cin >> x >> y;
		}
		while ( (x < 0 || x > length) || (y < 0 || y > width) ){
			cout << "Input x and y: ";
			cin >> x >> y;
		}
		Map[y][x] += 20;
	}
	
	else if ( command == 3){
		while ( Map[y][x] < 20 ){
			cout << "Input x and y: ";
			cin >> x >> y;
		}
		while ( (x < 0 || x > length) || (y < 0 || y > width) ){
			cout << "Input x and y: ";
			cin >> x >> y;
		}
		Map[y][x] -= 20;
	}
	
	return true;
}

bool Status(int ** Map, int length, int width){
	for ( int i = 1; i < width + 1; i++ ){
		for ( int  j = 1; j < length + 1; j++ ){
			if ( Map[i][j] == 10 )
			{
				int X[8] = {i-1, i-1, i-1, i, i, i+1, i+1, i+1};
				int Y[8] = {j-1, j, j+1, j-1, j+1, j-1, j, j+1};
				for ( int n = 0; n < 8; n++ ){
					if ( Map[X[n]][Y[n]] < 9 )
						return true;
				}
			}
		}
	}
	return false;
}

void Clean0(int ** Map,const int length, const int width ){
	for ( int i = 1; i < width + 1; i++ ){
		for ( int j = 1; j < length + 1; j++ ){
			if ( Map[i][j] == 10 ){
				int X[8] = {i-1, i-1, i-1, i, i, i+1, i+1, i+1};
				int Y[8] = {j-1, j, j+1, j-1, j+1, j-1, j, j+1};
				for ( int n = 0; n < 8; n++ ){
					if ( Map[X[n]][Y[n]] < 9 ){
						Map[X[n]][Y[n]] += 10;
					}
				}
			}
		}
	}
}
	
void Clean1(int i, int j, int ** Map,const int length, const int width ){
	if ( Map[i][j] != 10 ){
		int X[8] = {i-1, i-1, i-1, i, i, i+1, i+1, i+1};
		int Y[8] = {j-1, j, j+1, j-1, j+1, j-1, j, j+1};
		
		for ( int n = 0; n < 8; n++ ){
			if ( Map[X[n]][Y[n]] == 0 ){
				Map[X[n]][Y[n]] += 10;
			}
		}
	}
}