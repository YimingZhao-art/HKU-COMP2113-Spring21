#include<string>
#include<vector>
using namespace std;

#ifndef DATA_H
#define DATA_H

struct MAGICS //Store the inf of magics.
{
    string name;
    int damage; //The exact damage is between [ 0.8*damage , 1.2* damage ] randomly.
};


struct POKEMON //Store the inf of pokemon.
{
    string name; //name of each pokemon.
    int level = 1;  //level of each pokemon, from 1 to 10.
    int hp; //The maximum HP of a Pokemon should follow: HPmax = 24 * level. The hp variable here just means current hp.
    int hpmax;
    //For each of the four places means a magics from the Magic base. n means none. 0 to 9 is different 10 magics.
    string character; //The characteristic of a pokemon. i.e. fire water wood normal.
    int experience = 0; //Level up when experience > 100, then reset to 0 each time.
};


struct BOSS //Store the inf of Boss.
{
    string name; //name of each boss.
    int level = 10; //The default level of boss is 10;
    int hp; //The maximum HP of Boss, follow: HPmax = 800d.  The hp variable here just means current hp.
    int hpmax = 800;
    //Boss will use default magics.
    string character; //The characteristic of a boss. i.e. fire water wood normal.
};

struct USER //Store the inf of user.
{
    string name; // for reading
    int money = 100; //The money of user.
    int number_of_pokeman = 0;
    vector <POKEMON> bag;
    int train = 0; //The number of train can be add to a pokemon to train it.
    int capturestatus[4] = {0}; //To determine whether a kind of pokemon is captured.
    int bossstatuse[4] = {0}; //To record whether a boss was beaten.
};

MAGICS magics[10];
BOSS boss[4];
POKEMON pokemons[4];

#endif
