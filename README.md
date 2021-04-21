# ENGG1340COMP2113 Project

## Group 211

### Members
#### Zhao Yiming
#### Xu   Haozhou

##### Pokemon
0. Brief Description

- Players can choose an initial Pokemon at the beginning. In this game, players can fight, train, strengthen their Pokemon, and defeat the bosses that appear in the game. In addition to the regular Pokémon mode, you can choose to play several types of mini games provided to earn rewards and have fun.
- The game provides a file io-based archive system, allowing you to continue your unfinished adventure the next time you open it.
- What we do are not only a battle game. However, we are trying to make a system for players, where they can battle happily and play some small games for fun. Creating a small world for the player himself, and hope he enjoy himself!

1. Rules

   - User
     - choose a creature
     - have `100` gold at first
     - 0 train to get pokemon level-up
   - Creature
     - Four atrributes `fire`, `water`, `wood`, `normal`
     - Maximum `level`
     - Certain `hp`
     - Learn more powerful magic and hp increase with level increasing
     - level up when experience is 100, the highest level is 10
   - Battle
     - Water damages twice to fire, fire damages twice to wood, wood damages twice to water, normal performs consistently
     - Magics with different power (The exact damage will be randomly chosen)
     - Damage cause hp decrease, when hp is 0, it cannot fight and lose
     - When wild creatures' hp is lower than 25% of hpmax, we can `capture` successfully
     - Defeat the `Boss` and win.
     - Choose to flee if you can't beat the enemies.
	 - Bosses cannot be ‘capture’
     - Flee if you can't continue the battle.
   - Games
     - Earning gold and train
   - Bags
     - Recover creatures using gold
     - Learn about information about creatures
     - Own 4 creatures at most
     - Distribute train to make pokemon level-up

2. Features
  - Savegame and Readgame by File I/O and Struct:
    - Player can store the information of his account status in a [username].txt.
    - Player can reopen a game by enter the right username saved. The program will read the [username].txt.
  
  - Battle and Capture by vector and rand():
    - Player use his pokemons to compete with wild animals or bosses.
    - Player can capture animals to enlarge his bag.
    - Damage of magics is a random with given algorithm.
  
  - Doing small game to earn train and money by use `.h` `.cpp` and rand():
    - 	Try tic-tac-toe
    - 	Try guess a random numebr
    - 	Try paper-scissors-rock
    - 	Notakto
    - 	MineSweep
    - 	Earn  golds and  train if win.
  
  - Bag interface by vector etc. :
    - Show the information of pokemons
    - Distribute train to level-up pokemons 		
    - Recover pokemons to hpmax
	

 3. Code flow
    - Start (end)
      - New Game/Load Game
      - Save Game/Exit without save 
    - Choose first creature
    - While not end
      - Check bags / Battle / Game / End
      - Check bags
        - Print information
        - Recover using gold
        - Distribute train
        - Close
      - Battle
        - Choose opponents to battle
        - Choose own creatures to start
        - Choose magic
          - High level do magic first, if same, user first
        - Change when one is dead
        - Capture
        - Run
      - Game
        - Choose game
        - Win/Lost end
        - Get gold / level  


4. Data Structure
   - User
     - name
     - money
     - number of pokemon
     - train
     - pokemon
       - name
       - level
       - hp
       - hpmax
       - experience
       - character
       - magic
         - name
	 - num
	 - damage

5. File include
 - `*.cpp`
   - `main.cpp run` the flow
   - `game.cpp` implement small game
   - `readgame.cpp` read file to get information
   - `savegame.cpp` save information to file
   - `battle.cpp` battle function
   - `initial.cpp` initial the data
   - `notakto.cpp` do the notakto game
   - `MineSweep.cpp` do the minesweep game
 - `header` i.e. `*.h`
   - `game.h` store the declaration of game 	
   - `savegame.h` store the declaration of savegame 
   - `readgame.h`store the declaration of readgame 
   - `battle.h` store the declaration of battle
   - `data.h` store the struct of user, pokemon, etc
   - `initial.h`
   - `notakto.h` store the game notakto
   - `MineSweep.h` store the game minesweep
 - `Makefile`
   - for compile the code
   - delete the `*.cpp` and `*.o` and `*.h` after compile 
 - `Sample input-output.docx`
   - show the samples of input and output.  
