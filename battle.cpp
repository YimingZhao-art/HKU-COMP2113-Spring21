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
#include "savegame.h"
#include "readgame.h"
#include "battle.h"

void normalbattle(USER user) //For normal battle, can capture pokemons.
{
    int numbers = user.number_of_pokeman;
    int can = 0; //Record the number of pokemons that can attend the battle.
    for (int i = 0; i < numbers; i++)
        if (user.bag[i].hp > 0)
            can++;
    if (can == 0)
        {
            cout<<"No pokemons can attend the battle, Please recover their health.\n";
            return;
        }
    
    
}


void bossbattle(USER user) //Fight the boss.
{

}