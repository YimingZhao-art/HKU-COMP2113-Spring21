//This file is used to be the main file of the game
//Following are libraries we need to use.
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<string>
#include<cctype>
//Following are libraries defined by us.
#include "data.h"
#include "initial.h"

using namespace std;

void read(USER user){
    string filename = user.name + ".txt";
    ifstream file(filename.c_str());
    if ( file.fail() )
        cout << "No such file!" << endl;
    
    
    file >> user.name >> user.money >> user.train >> user.number_of_pokeman;
    
    for ( int i = 0; i < user.number_of_pokeman; i++ ){
        file >> user.bag[i].name >> user.bag[i].level >> user.bag[i].hp >>user.bag[i].hpmax >> user.bag[i].magics >> user.bag[i].experience >> user.bag[i].character ;
    }
    
    file.close();
}