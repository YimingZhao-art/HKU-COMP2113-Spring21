# ENGG1340COMP2113 Project

## Group 211

### Members
#### Zhao Yiming & Xu Haozhou

1. Description
   - A game like pokeman. User become strong by competing with wild creatures or doing games and then kill the boss.


2. Rules
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
     - Damage cause PP decrease, when PP is 0, it dead
     - When wild creatures' PP is lower than 2, we can `capture` successfully
     - Kill the `Boss` and win the game
   - Games
     - Earning gold and get creature level up
   - Bags
     - Recover creatures using gold
     - Learn about information about creatures
     - Own 3 creatures at most


3. Features
   - Choosing one creature at first and get some gold
   - Open bags
     - Show the information of every creature
       - `Level`, `PP`, `magics`
       - graph
     - Recover creature's status
   - Battle with wild creature
     - Showing information of `PP`, `name`, `graph`
     - Showing magic power
     - Choosing to use magic or capture or run
   - Doing entertainment games
     - Tic-Tac-Toe & ??
     - Earning 5 gold when winning and get level up
 
 
 4. Code flow
    - Start (end)
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


5. Structure
   - Creature -- Array[8] = {graphstring,name,pp,level,magics1,magics2,magics3,magic4} 
