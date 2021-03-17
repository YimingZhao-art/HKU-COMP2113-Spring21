# ENGG1340COMP2113 Project

## Group 211

### Members
#### Zhao Yiming
#### Xu   Haozhou

##### Pokemon
0. Brief Description

- Players can choose an initial Pokemon at the beginning. In this game, players can fight, train, strengthen their Pokemon, and defeat the bosses that appear in the game. In addition to the regular Pokémon mode, you can choose to play several types of mini games provided to earn rewards and have fun.
- The game provides a file io-based archive system, allowing you to continue your unfinished adventure the next time you open it.

1. Rules

   - User
     - choose a creature
     - have `x` gold at first
   - Creature
     - Four atrributes `fire`, `water`, `wood`, `neutral`
     - Water damages twice to fire, fire damages twice to wood, wood damages twice to water, neutral performs consistently
     - Maximum `level`
     - Certain `PP`
     - Learn more powerful magic and PP increase with level increasing
   - Battle
     - Water damages twice to fire, fire damages twice to wood, wood damages twice to water
     - Magics with different power
     - Damage cause PP decrease, when PP is 0, it cannot fight and lose
     - When wild creatures' PP is lower than 2, we can `capture` successfully
     - Defeat the `Boss` and win the game
	 - Bosses cannot be ‘capture’
   - Games
     - Earning gold and get creature level up
   - Bags
     - Recover creatures using gold
     - Learn about information about creatures
     - Own 3 creatures at most

2. Features

- a. Wizard management system (using arrays and strings to store current status information)
   - Show the information of every creature
       - `Level`, `PP`, `magics`
       - graph
   - Show the status of gold
- b. Randomized battle system (randomization of damage and opponents encountered) (The information of each battle is generated at the beginning of the battle and disappears after the end)
   - Showing information of `PP`, `name`, `graph`
      - Showing magic power
   - Choosing to use magic or capture or run
   - Random damage cause by magics
- c. Boss battle (the information of each battle is generated at the beginning of the battle and disappears after the end)
- d. Mini game (content will come from different cpp and h files) (the information of each game is generated at the beginning of the game and disappears after the end)
   - Tic-Tac-Toe & ??
   - Earning 5 gold when winning and get level up
- e. Menu interface (different functions will come from different cpp, h files)
- f. Archive system (based on file io)	
   - Choose start new game or load game at beginning
   - Save data before end game
	

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


4. Data Storing
   Use arrays, strings and structures to store datas for next time used
   - e.g. Creature -- Array[8] = {graphstring,name,pp,level,magics1,magics2,magics3,magic4}
