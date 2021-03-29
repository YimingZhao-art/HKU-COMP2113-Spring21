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

MAGICS magics[10];
BOSS boss[4];
POKEMON pokemons[4];

int main()
{
    initialmagics(magics); //Initialize the data of magics.
    initialboss(boss); //Initial the data of boss.
    initialpokemon(pokemons); //Initial the data of Pokemons.
    
    display1(); //When first open the game, display the menu for user to choose: load game/new game/exit.
    while(1) //Used when first open the program.
    {   
        string get;
        cout<<"Instruction:"<<endl;
        cin >> get; //Get the instruction from the user.
        if (get == "loadgame")
        {
            loadgame(); //Call the function to load the game.
            break;
        }
        else if (get == "newgame")
        {
            newgame(); //Call the function to create new game.
            break;
        }
        else if (get == "exit")
            return 0; //shutdown the game.
        else
            cout<<"Wrong instruction! Please try again(loadgame, newgame, exit)."<<endl;  
    }
    
    //The following part would be main body of the program.
    
    return 0;
}
