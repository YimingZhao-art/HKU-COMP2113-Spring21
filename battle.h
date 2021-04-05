#include <string>
#include "data.h"
#include <ctime>
#include <cstdlib>
using namespace std;

#ifndef BATTLE_H
#define BATTLE_H

///Give the graph of normal battle and boss battle;
   string bossgraph = "                                    *    (---------)       *\n    *|````|*                     *       | \\|/     |          *\n  *--| ^ ^|--*                           | ^-^     |\n     |- ^-|                          /|\\ |-    -   |  /|\\\n     *----*                      *       |\\ ~ /    |          *\n                                    *    (---------)       *\n";
   string normalgraph = "    *|````|*                            *|````|*\n  *--| ^ ^|--*                        *--|^ ^ |--*\n     |- ^-|                              |-^ -|\n     *````*                              *````*\n";

void showmagic(string x);
int dam(int level, int place, string c1, string c2);

void normalbattle(USER &user); //For normal battle, can capture pokemons.
void bossbattle(USER &user); //Fight the boss.

#endif