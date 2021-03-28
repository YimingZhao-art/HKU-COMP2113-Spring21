//This file is used to define all important data of the game
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<string>
#include<cctype>

using namespace std;

struct MAGICS //Store the inf of magics.
{
    int num; //The ten maigics have id numbers from 0-9.
    string name;
    string damage; //The exact damage is between [ 0.8*damage , 1.2* damage ] randomly.
}magics[10];

struct POKEMON //Store the inf of pokemon.
{
    string name; //name of each pokemon.
    int level;  //level of each pokemon, from 1 to 10.
    int hp; //The maximum HP of a Pokemon should follow: HPmax = 25 * level. The hp variable here just means current hp.
    char magics[5]="nnnn"; //For each of the four places means a magics from the Magic base. n means none. 0 to 9 is different 10 magics.
    string character; //The characteristic of a pokemon. i.e. fire water wood normal.
    int experience; //Level up when experience > 100, then reset to 0 each time.
}pokemons[4];

struct BOSS //Store the inf of Boss.
{
    string name; //name of each boss.
    int level = 10; //The default level of boss is 10;
    int hp; //The maximum HP of Boss, follow: HPmax = 40 * level.  The hp variable here just means current hp.
    char magics[5]="6789"; //Boss will use default magics.
    string character; //The characteristic of a boss. i.e. fire water wood normal.
}boss[4];

struct USER //Store the inf of user.
{
    int money; //The money of user.
    bool status[4]; //True for captured a pokemon, false for not.
    int train; //The number of train can be add to a pokemon to train it.
};



int main()
{
    initialmagics(magics); //Initialize the data of magics.

    display1(); //When first open the game, display the menu for user to choose: load game/new game/exit.
    while(1) //Used when first open the program.
    {   
        string get;
        cout<<"Instruction:"<<endl;
        cin >> get;//Get the instruction from the user.
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
