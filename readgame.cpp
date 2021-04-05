//This file is used to load game
//Following are libraries we need to use.
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<string>
#include<cctype>
#include<iomanip>
#include<vector>
//Following are libraries defined by us.
#include "data.h"
#include "initial.h"

using namespace std;

void read(USER &user)
{
    string filename = user.name + ".txt";
    ifstream file(filename.c_str());
    if ( file.fail() )
        cout << "No such file!" << endl;
    
    
    file >> user.name >> user.money >> user.train >> user.number_of_pokeman;
    file >> user.capturestatus[0] >> user.capturestatus[1] >> user.capturestatus[2] >> user.capturestatus[3];
    file >> user.bossstatuse[0] >> user.bossstatuse[1] >> user.capturestatus[2] >> user.bossstatuse[3];
    
    for ( int i = 0; i < user.number_of_pokeman; i++ )
    {
        POKEMON poke;
        file >> poke.name >> poke.level >> poke.hp >>poke.hpmax >> poke.experience >> poke.character;
        user.bag.push_back(poke);
    }
    
    file.close();
    return;
}
