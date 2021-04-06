#include <string>
#include "data.h"
#include <ctime>
#include <cstdlib>
using namespace std;

#ifndef BATTLE_H
#define BATTLE_H

void showmagic(int x, MAGICS magics[]);
int dam(int level, int place, string c1, string c2, MAGICS magics[]);

void normalbattle(USER &user, POKEMON pokemons[], MAGICS magics[]); //For normal battle, can capture pokemons.
void bossbattle(USER &user, BOSS boss[], MAGICS magics[]); //Fight the boss.

#endif