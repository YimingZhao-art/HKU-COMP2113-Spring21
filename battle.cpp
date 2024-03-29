//This file is the battle function.
//Following are libraries we need to use.
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <string>
#include <cctype>
#include <iomanip>
#include <vector>
//Following are libraries defined by us.
#include "data.h"
#include "initial.h"
#include "savegame.h"
#include "readgame.h"
#include "battle.h"

///Give the graph of normal battle and boss battle;
string bossgraph = "                                    *    (---------)       *\n    *|````|*                     *       | \\|/     |          *\n  *--| ^ ^|--*                           | ^-^     |\n     |- ^-|                          /|\\ |-    -   |  /|\\\n     *----*                      *       |\\ ~ /    |          *\n                                    *    (---------)       *\n";
string normalgraph = "    *|````|*                            *|````|*\n  *--| ^ ^|--*                        *--|^ ^ |--*\n     |- ^-|                              |-^ -|\n     *````*                              *````*\n";

//Input: magics(data base), x(level of the pokemon).
//Function: Display the name list of magics.
void showmagic( int x, MAGICS magics[] ) //show what magics can be used.
{
    cout<<"please input the magic you want to use(input number)"<<endl;
    switch (x)
    {
    case 1:
        cout<< "1." <<magics[0].name<<endl;
        break;
    case 2:
        cout<< "1." <<magics[1].name<<endl;
        cout<< "2." <<magics[0].name<<endl;
        break;
    case 3:
        cout<< "1." <<magics[2].name<<endl;
        cout<< "2." <<magics[1].name<<endl;
        cout<< "3." <<magics[0].name<<endl;
        break;
    default:
        for( int i = 1; i <= 4; i++ )
            cout<<i<<"."<<magics[x-i].name<<endl;
        break;
    }
    return;
}

//Input: level of pokemon, the magic number, characteristcs of pokemon 1 and 2, magics.
//Output: The damage caused by a magic.
int dam( int level, int place, string c1, string c2, MAGICS magics[] ) //Calculate the damage.
{
    int damage = magics[level-place].damage;
    srand( time(NULL) );
    damage = damage + (rand()%13) - 6;

    if( c1 == "water" )
    {
        if( c2 == "fire" )
            damage *=2;
        else if( c2 == "wood" )
            damage /=2;
    }
    else if( c1 == "wood" )
    {
        if( c2 == "fire" )
            damage /=2;
        else if( c2 == "water" )
            damage *=2;
    }
    else if( c1 == "fire" )
    {
        if( c2 == "water" )
            damage /=2;
        else if( c2 == "wood" )
            damage *=2;
    }
    return damage;
}

//This function is the main function of normal battle.
void normalbattle( USER &user, POKEMON pokemons[], MAGICS magics[] ) //For normal battle, can capture pokemons.
{
    int numbers = user.number_of_pokeman;
    vector <int> can; //Record the number of pokemons that can attend the battle.
    for ( int i = 0; i < numbers; i++ )
        if ( user.bag[i].hp > 0 )
            can.push_back(i);
    if ( can.size() == 0 )
        {
            cout<< "No pokemons can attend the battle, Please recover their health.\n";
            cout << "-------------------------------------------------------------------\n";
            return;
        }
    
    int mid;
    int place;
    
    //Let the user choose a pokemon to attend.
    cout << "choose a pokemon to attend the battle:\n";
    cout << "input a integer which >= 0 and <= "<< can.size()-1 <<endl;
    cin >> place;
    while( place >= can.size() || place < 0 )
    {
        cout << "Do not exist, try again.\n";
        cin >> place;
    }
    mid = can[0];
    can[0] = can[place];
    can[place] = mid;
    cout << "-------------------------------------------------------------------\n";
    //Initial the data of enemies.
    for ( int i = 0; i < 4; i++ )
    {
        pokemons[i].level = user.bag[can[0]].level;
        pokemons[i].hp = 24 * pokemons[i].level;
        pokemons[i].hpmax = 24 * pokemons[i].level;
    }
    cout << "choose one enemy to fight(input the number):\n";
    for( int i = 0; i < 4; i++ )
        cout << i << "." << pokemons[i].name << endl;

    int chosen;
    cin >> chosen;
    
    //check if the input is legal
    while( chosen>3 || chosen <0 )
    {
        cout << "Do not exist, try again.\n";
        cin >> chosen;
    }
    cout << "-------------------------------------------------------------------\n";
    cout << normalgraph;
    cout << user.bag[can[0]].name << " VS " << pokemons[chosen].name << endl
         <<  user.bag[can[0]].hp << "/" << user.bag[can[0]].hpmax << "        "
         <<  pokemons[chosen].hp << "/" << pokemons[chosen].hpmax << endl
         <<  "1.fight\n2.capture\n3.flee\n"
         <<  "input command(number of it):\n";
    int l1, l2 = pokemons[chosen].level;
    int command;
    cin >> command;
    //check if the input is legal
    while (command < 1 || command > 3)
    {
        cout << "Wrong input, please input again.\n";
        cin >> command;
    }
    cout << "-------------------------------------------------------------------\n";
    while( command != 3 ) //The main body of the battle.
    {
        system("clear");
        if( command == 1 ) //Battle.
        {
            cout << normalgraph;
            cout << user.bag[can[0]].name << " VS " << pokemons[chosen].name << endl
            << user.bag[can[0]].hp << "/" << user.bag[can[0]].hpmax << "        "
            << pokemons[chosen].hp << "/" << pokemons[chosen].hpmax << endl;
            
            l1 = user.bag[can[0]].level;
            showmagic( user.bag[can[0]].level, magics );
            int cmagic1,cmagic2;
            cin >> cmagic1;
            while(cmagic1 > user.bag[can[0]].level || cmagic1 > 4)
            {
                cout<<"Magic do not exist, try again.\n";
                cin>>cmagic1;
            }
            if( pokemons[chosen].level < 3 )
            {
                cmagic2 = ( rand() % pokemons[chosen].level ) + 1;
            }
                
            else
                {
                    srand( time(NULL) );
                    cmagic2 = ( rand() % 4 ) + 1;
                }
            srand( time(NULL) );
            int d1 = dam( l1,cmagic1,user.bag[can[0]].character, pokemons[chosen].character,magics ) + (rand() % 11) - 5;
            int d2 = dam( l2,cmagic2,pokemons[chosen].character,user.bag[can[0]].character,magics ) + (rand() % 7) - 3;
            if(d1 <= 0)
                d1 = 1;
            if(d2 <= 0)
                d2 = 1;
            user.bag[can[0]].hp -= d2;
            pokemons[chosen].hp -= d1;
            cout << user.bag[can[0]].name << " use " << magics[l1-cmagic1].name << " cause " << d1 << " damage" << endl;
            cout << pokemons[chosen].name << " use " << magics[l2-cmagic2].name << " cause " << d2 << " damage" << endl;
            if( user.bag[can[0]].hp < 0 )
                user.bag[can[0]].hp = 0;
            if( pokemons[chosen].hp < 0 )
                pokemons[chosen].hp = 0;
            cout<< user.bag[can[0]].name << "    " << pokemons[chosen].name << endl
                <<  user.bag[can[0]].hp<<"/" << user.bag[can[0]].hpmax << "        "
                <<  pokemons[chosen].hp<<"/" << pokemons[chosen].hpmax << endl;
        }
        
        else if( command == 2 ) //Capture.
        {
            if( pokemons[chosen].hp > ( pokemons[chosen].hpmax / 4 ) )
            {
                cout << "Only hp < 25% of hpmax can be captured" << endl;
            }
            else if( user.capturestatus[chosen] == 1 )
            {
                cout << "You already have the same pokemon, can't capture a new one" << endl;
            }
            else
            {
                user.bag.push_back( pokemons[chosen] );
                cout << "Captured!!!" << endl;
                user.capturestatus[chosen] = 1;
                user.number_of_pokeman++;
                user.train += 5;
                cout << "Experience + 5" << endl;
                return;
            }
        }

        else if( command == 3 ) //Flee.
        {
            cout << "run......" << endl;
            return;
        }

        if( pokemons[chosen].hp == 0 ) //Win battle.
        {
            cout << "You win the battle!!!";
            user.train += 5;
            cout << "Experience + 5" << endl;
            return;
        }

        if ( user.bag[can[0]].hp == 0 ) //Check conditions.
        {
            cout << user.bag[can[0]].name << " was beaten, need another pokemon to attend." << endl;
            can.erase( can.begin() );
            if ( can.size() == 0 )
            {
                cout << "No more pokemon can fight, you lose." << endl;
                user.train += 3;
                cout<<"Experience + 3" << endl;
                return;
            }
            cout << "choose a pokemon to attend the battle:\n";
            cout << "input a integer which >= 0 and <= " << can.size()-1 << endl;
            cin >> place;
            while( place >= can.size() || place < 0 )
            {
                cout << "Do not exist, try again.\n";
                cin >> place;
            }
            mid = can[0];
            can[0] = can[place];
            can[place] = mid;
            cout << user.bag[can[0]].name << " now attend the battle" << endl;
        }

        cout << "-------------------------------------------------------------------\n";
        cout <<  "1.fight\n2.capture\n3.flee\n"
             <<  "input command(number of it):\n";

        cin >> command;
        cout << "-------------------------------------------------------------------\n";
    }
    
    return;
}




//This function is the main function of boss battle.
void bossbattle( USER &user, BOSS boss[], MAGICS magics[] ) //Fight the boss.
{
    int numbers = user.number_of_pokeman;
    vector <int> can; //Record the number of pokemons that can attend the battle.
    for ( int i = 0; i < numbers; i++ )
        if ( user.bag[i].hp > 0 )
            can.push_back(i);
    if ( can.size() == 0 )
        {
            cout << "No pokemons can attend the battle, Please recover their health.\n";
            cout << "-------------------------------------------------------------------\n";
            return;
        }
    int mid;
    int place;
    //Let the user choose a pokemon to attend.
    cout << "choose a pokemon to attend the battle:\n";
    cout << "input a integer which >= 0 and <= "<<can.size()-1<<endl;
    cin >> place;
    
    //check if the input is legal
    while( place >= can.size() || place < 0 )
    {
        cout << "Do not exist, try again.\n";
        cin >> place;
    }
    mid = can[0];
    can[0] = can[place];
    can[place] = mid;
    cout << "-------------------------------------------------------------------\n";

    //Initial the data of enemies.
    for ( int i=0; i<4; i++ )
        boss[i].hp = boss[i].hpmax;
    cout << "choose one Boss to fight(input the number):\n";
    for( int i = 0; i < 4; i++ )
            cout << i << "." << boss[i].name << "(have been beaten for " << user.bossstatuse[i] << " times)\n";

    int chosen;
    cin >> chosen;
    
    //check if the input is legal
    while( chosen > 3 || chosen < 0)
    {
        cout << "Do not exist, try again.\n";
        cin >> chosen;
    }
    cout << "-------------------------------------------------------------------\n";

    cout << bossgraph;
    cout << user.bag[can[0]].name <<" VS " << boss[chosen].name << endl
         <<  user.bag[can[0]].hp << "/" << user.bag[can[0]].hpmax << "        "
         <<  boss[chosen].hp<<"/"<<boss[chosen].hpmax << endl
         <<  "1.fight\n2.flee\n"
         <<  "input command(number of it):\n";
    int l1, l2 = boss[chosen].level;
    int command;
    cin >> command;
    //check if the input is legal
    while (command < 1 || command > 3)
    {
        cout << "Wrong input, please input again.\n";
        cin >> command;
    }
    cout << "-------------------------------------------------------------------\n";
    while( command != 2 ) //The main body of the battle.
    {
        system("clear");
        if( command == 1 ) //Battle.
        {
            cout << bossgraph;
            cout << user.bag[can[0]].name << " VS " << boss[chosen].name << endl
                 <<  user.bag[can[0]].hp << "/" << user.bag[can[0]].hpmax << "         "
                 <<  boss[chosen].hp << "/" << boss[chosen].hpmax << endl;
            l1 = user.bag[can[0]].level;
            showmagic( user.bag[can[0]].level, magics );
            int cmagic1, cmagic2;
            cin >> cmagic1;
            while(cmagic1 > user.bag[can[0]].level || cmagic1 > 4)
            {
                cout<<"Magic do not exist, try again.\n";
                cin>>cmagic1;
            }
            srand( time(NULL) );
            cmagic2 = ( rand() % 4 ) + 1;
            srand( time(NULL) );
            int d1 = dam( l1, cmagic1, user.bag[can[0]].character, boss[chosen].character, magics ) + (rand() % 11) - 5;
            int d2 = dam( l2, cmagic2,boss[chosen].character, user.bag[can[0]].character, magics ) * 1.1 + (rand() % 7) - 3; //Boss will cause extra damage
            if(d1 <= 0)
                d1 = 1;
            if(d2 <= 0)
                d2 = 1;
            user.bag[can[0]].hp -= d2;
            boss[chosen].hp -= d1;
            cout << user.bag[can[0]].name << " use "<< magics[l1-cmagic1].name << " cause " << d1 << " damage" << endl;
            cout << boss[chosen].name << " use " << magics[l2-cmagic2].name << " cause " << d2 << " damage" << endl;
            if( user.bag[can[0]].hp < 0 )
                user.bag[can[0]].hp = 0;
            if( boss[chosen].hp < 0 )
                boss[chosen].hp = 0;
            cout << user.bag[can[0]].name << "    " << boss[chosen].name << endl
                 <<  user.bag[can[0]].hp << "/"<< user.bag[can[0]].hpmax << "         "
                 <<  boss[chosen].hp << "/" << boss[chosen].hpmax << endl;
        }
        
        else if( command == 2 ) //Flee.
        {
            cout << "run......" << endl;
            return;
        }

        if( boss[chosen].hp == 0 ) //Win.
        {
            cout << "You win the battle!!!";
            user.train += 25;
            user.bossstatuse[chosen]++;
            cout << "Train + 25" << endl;
            return;
        }

        if ( user.bag[can[0]].hp == 0 ) //Check conditions.
        {
            cout << user.bag[can[0]].name << " was beaten, need another pokemon." << endl;
            can.erase(can.begin());
            if( can.size() == 0 )
            {
                cout << "No more pokemon can fight, you lose." << endl;
                user.train += 3;
                cout << "Train + 3" << endl;
                return;
            }
            cout << "choose a pokemon to attend the battle:\n";
            cout << "input a integer which >= 0 and <= " << can.size()-1 << endl;
            cin >> place;
            while( place >= can.size() || place < 0 )
            {
                cout << "Do not exist, try again.\n";
                cin >> place;
            }
            mid = can[0];
            can[0] = can[place];
            can[place] = mid;
            cout << user.bag[can[0]].name << " now attend the battle" << endl;
        }

        cout << "-------------------------------------------------------------------\n";
        cout <<  "1.fight\n2.flee\n"
             <<  "input command(number of it):\n";

        cin >> command;
        cout << "-------------------------------------------------------------------\n";
    }
    
    return;
}
