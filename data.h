#include <string>
using namespace std;

#ifndef DATA_H
#define DATA_H

struct MAGICS //Store the inf of magics.
{
    int num; //The ten maigics have id numbers from 0-9.
    string name;
    string damage; //The exact damage is between [ 0.8*damage , 1.2* damage ] randomly.
};

struct POKEMON //Store the inf of pokemon.
{
    string name; //name of each pokemon.
    int level;  //level of each pokemon, from 1 to 10.
    int hp; //The maximum HP of a Pokemon should follow: HPmax = 24 * level. The hp variable here just means current hp.
    int hpmax;
    string magics = "nnnn"; //For each of the four places means a magics from the Magic base. n means none. 0 to 9 is different 10 magics.
    string character; //The characteristic of a pokemon. i.e. fire water wood normal.
    int experience = 0; //Level up when experience > 100, then reset to 0 each time.
};

struct BOSS //Store the inf of Boss.
{
    string name; //name of each boss.
    int level = 10; //The default level of boss is 10;
    int hp; //The maximum HP of Boss, follow: HPmax = 40 * level.  The hp variable here just means current hp.
    int hpmax = 400;
    string magics = "6789"; //Boss will use default magics.
    string character; //The characteristic of a boss. i.e. fire water wood normal.
};

struct USER //Store the inf of user.
{   
    string name; // user name to save
    int money; //The money of user.
    bool status[4]; //True for captured a pokemon, false for not.
    int train; //The number of train can be add to a pokemon to train it.
};




#endif
