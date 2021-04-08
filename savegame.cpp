//This file is used to save the game
//Following are libraries we need to use.
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <string>
#include <cctype>
#include <vector>
//Following are libraries defined by us.
#include "data.h"
#include "initial.h"
using namespace std;

//read a USER, and store the information in user to [username].txt
void save( USER &user )
{
    string filename = user.name + ".txt";
    
    ofstream file( filename.c_str() );
    
    if ( file.fail() )
    {
        cout<<"Save error, please try again.\n";
        return;
    }
    /*save a txt as:
    user_name user_money user_number_of_pokeman
    user.capture_status
    user.bossstatus
    user_pokemon:
    name level hp hpmax experience character
    */
    file << user.name << ' ' <<  user.money << ' ' << user.train <<' ' << user.number_of_pokeman << endl;
    file << user.capturestatus[0] <<" "<< user.capturestatus[1] <<" "<< user.capturestatus[2] <<" "<< user.capturestatus[3] <<endl;
    file << user.bossstatuse[0] <<" "<< user.bossstatuse[1] <<" "<< user.bossstatuse[2] <<" "<< user.bossstatuse[3] <<endl;
    for ( int i = 0; i < user.number_of_pokeman; i++ )
    {
        file << user.bag[i].name << ' ' << user.bag[i].level << ' ' << user.bag[i].hp << ' ' << user.bag[i].hpmax << ' ' << user.bag[i].experience << ' ' << user.bag[i].character << endl;
    }

    file.close();
    return;
}
