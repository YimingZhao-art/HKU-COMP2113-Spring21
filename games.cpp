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


