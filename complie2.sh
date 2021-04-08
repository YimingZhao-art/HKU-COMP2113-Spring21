#!/bin/bash

g++ -pedantic-errors -std=c++11 -c *.cpp
g++ -pedantic-errors -std=c++11 *.o -o pokemon

./pokemon