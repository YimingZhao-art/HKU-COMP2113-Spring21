#!/bin/bash

g++ -pedantic-errors -std=c++11 -c battle.cpp
g++ -pedantic-errors -std=c++11 -c game.cpp
g++ -pedantic-errors -std=c++11 -c initial.cpp
g++ -pedantic-errors -std=c++11 -c main.cpp
g++ -pedantic-errors -std=c++11 -c readgame.cpp
g++ -pedantic-errors -std=c++11 -c savegame.cpp

g++ -pedantic-errors -std=c++11 battle.o game.o initial.o main.o savegame.o readgame.o -o pokemon
./pokemon