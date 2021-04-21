FlAG = -pedantic-errors -std=c++11

battle.o: battle.cpp battle.h 
	g++ $(FLAG) -c $<

initial.o: initial.cpp initial.h 
	g++ $(FLAG) -c $<

game.o: game.cpp game.h
	g++ $(FLAG) -c $<

readgame.o: readgame.cpp readgame.h
	g++ $(FLAG) -c $<
	
savegame.o: savegame.cpp savegame.h
	g++ $(FLAG) -c $<

notakto.o : notakto.cpp notakto.h
	g++ $(FALG) -c $<	
	
MineSweep.o: MineSweep.cpp Minesweep.h
	g++ $(FALG) -c $<
	
main.o: main.cpp
	g++ $(FLAG) -c $<
	
main: main.o initial.o game.o readgame.o savegame.o battle.o notakto.o MineSweep.o
	g++ $(FLAG) $^ -o $@

clean:
	rm -f *.o main
	
.PHONY: clean

