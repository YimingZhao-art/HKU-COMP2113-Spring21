#include <string>
#include "data.h"
using namespace std;

#ifndef BATTLE_H
#define BATTLE_H

///Give the graph of normal battle and boss battle;
   string bossb = "                           *    ╭┴┴—————┴┴╮       *\n ◎oо.╭∞━━━╮             *       │ │＼｜／           *\n  *--┃ ● ●┃--*                  │ ● ● │—☆—\n     ┃﹋ ^┃                 ／| │○ ╰┬┬┬╯ ○│／｜＼\n     *━━━━*             *       │ ╰—╯ ／            *\n                           *    ╰—┬○————┬○╯       *\n";
   string normalb = " ◎oо.╭∞━━━╮             ╭∞━━━╮.oо◎\n  *--┃ ● ●┃--*       *--┃● ● ┃--*\n     ┃﹋ ^┃             ┃ε ﹋┃\n     *━━━━*             ○━━━━╯\n";
void normalbattle(USER user); //For normal battle, can capture pokemons.

void bossbattle(USER user); //Fight the boss.

#endif