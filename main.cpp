//This file is used to be the main file of the game
//Following are libraries we need to use.
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<string>
#include<cctype>
#include <iomanip>
//Following are libraries defined by us.
#include "data.h"
#include "initial.h"
#include "savegame.h"
#include "readgame.h"
#include "game.h"


using namespace std;

MAGICS magics[10];
BOSS boss[4];
POKEMON pokemons[4];
USER user;


void display1() {
    cout << "------------------------------------------\n" <<
            "Choose one of the modes: \n" <<
            "loadgame\n" <<
            "newgame\n" <<
            "exit\n" <<
            "------------------------------------------\n";
}

void display() {
    cout << "------------------------------------------\n" <<
            "Choose one of the commands: \n" <<
            "Battle\n" <<
            "Bag\n" <<
            "Games\n" <<
            "SaveAndExit\n";
}

void display_game(){
    cout << "------------------------------------------\n" <<
            "Choose one of the games: \n" <<
            "Tic_Tac_Toe\n" <<
            "Guess\n" <<
            "Exit\n";
}

void game(USER user){
    string command;
    display_game();
    cin >> command;
    while ( command != "Exit" ){
        if ( command == "Tic_Tac_Toe" ){
            if ( Tic_Tac_Toe() ){
                cout << "Your win 10 golds.\n";
                user.money += 10;
            }
            else
                cout << "Your don't win the golds.\n";
        }
        else if ( command == "Guess" ){
            if ( GUESS() ){
                cout << "Your win 10 golds.\n";
                user.money += 10;
            }
            else
                cout << "Your don't win the golds.\n";
        }
        
        display_game();
        cin >> command;
        if ( command == "Exit" )
            return;
    }
}

void display_bag(USER user) {
    cout << setw(9) << setfill(' ') << "User: " << user.name << endl;
    cout << setw(9) << setfill(' ') << "Money: " << user.money << endl;
    cout << setw(9) << setfill(' ') << "Train: " << user.train << endl;
    for ( int i = 0; i < user.number_of_pokeman; i++ ){
        cout <<"------------------------------------------\n";
        cout << "name: "<< setw(20) << setfill(' ') << user.bag[i].name << ":\n";
        cout << "level: " << setw(2) << setfill(' ') << user.bag[i].level << ' ' << "experience: " << setw(2) << setfill(' ') << user.bag[i].experience <<endl;
        cout << "hp: "<< setw(3) << setfill(' ') << user.bag[i].hp << ' ' << "hpmax: "<< setw(3) << setfill(' ') << user.bag[i].hpmax << endl;
        cout << "character: " << setw(6) << setfill(' ') << user.bag[i].character << endl;
    }
}

void Bag(USER user){
    display_bag(user);
    string command;
    cin >> command;
    cout << "------------------------------------------\n" <<
            "Choose one of the commands: \n" <<
            "Recover\n" << 
            "DistributeTrain\n" <<
            "Exit\n";
    while ( command != "Eixt" ){
        if ( command == "Recover" ){
            user.money -= 5;
            for ( int i = 0; i < user.number_of_pokeman; i++ )
                user.bag[i].hp = user.bag[i].hpmax;
        }
        else if ( command != "DistributeTrain" ){
            //insert the level-up
        }
        display_bag(user);
        cout << "------------------------------------------\n" <<
        "Choose one of the commands: \n" <<
        "Recover\n" << 
        "DistributeTrain\n" <<
        "Exit\n";
        cin >> command;
    }
}

int main()
{
    initialmagics(magics); //Initialize the data of magics.
    initialboss(boss); //Initial the data of boss.
    initialpokemon(pokemons); //Initial the data of Pokemons.
    
    display1(); //When first open the game, display the menu for user to choose: load game/new game/exit.
    while ( 1 ) //Used when first open the program.
    {   
        string get;
        cout << "Instruction:" <<endl;
        cin >> get; //Get the instruction from the user.
        
        
        if ( get == "loadgame" )
        {
            cout << "Input your user name: ";
            cin >> user.name;
            read(user); //Call the function to load the game.
            break;
        }
        
        
        else if ( get == "newgame" )
        {
            //newgame(); //Call the function to create new game.
            cout << "Input your user name: ";
            cin >> user.name;
            user.money = 100;
            cout << "Choose one of the pokemons(input from 0-3):\n ";
            for ( int i = 0; i < 4; i++ ){
                cout << i << ": " << pokemons[i].name <<endl;
            }
            
            int x;
            cin >> x;
            
            user.number_of_pokeman = 1;
            user.bag[0] = pokemons[x];
            break;
        }
        
        
        
        
        else if ( get == "exit" ){
            return 0; //shutdown the game.
        }
        
        else
            cout << "Wrong instruction! Please try again(loadgame, newgame, exit)." << endl;
    }
    

    //The following part would be main body of the program.
    string command;
    display();
    cin >> command;
    while ( command != "SaveAndExit" ){
        if ( command == "Battle" ){
            //insert the battle function here
            cout << 1;
        }
        else if ( command == "Bag" ){
            Bag(user);
        }
        else if ( command == "Games"){
            game(user);
        }
        display();
        cin >> command;
        if ( command == "SaveAndExit" )
            save(user);
    }
    return 0;
}
