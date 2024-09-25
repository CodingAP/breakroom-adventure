# RazorHack CTF 2024 - Breakroom Adventures
#### by Alex Prosser

> Look, I found this old game on one of the computers in the breakroom! It seems to have a good amount of content from what I was looking at, so why don't you look into it and see if it is worth anything. It may even have some easter eggs that no one has seen before!

The flags will take the structure of `flag{FLAG_HERE_XXXXX}`.

## Challenges

### 1. Just Like The Good Ole Days

- Do some exploring, finish the maze
- flag{play_maze_flag}

### 2. It Seem's Impenetrable...

- when approaching the castle, you need a key (easter egg to adventure)
- find key in maze
- flag{castle_key}

### 3. Answer Be, These Riddles Three

- Answer three riddles said by the king
- flag{riddle_key}

### 4. Just a Peek

- Before name input, there is a flag stored in the name string
- Use the 'strings' command to find it
- FLAG: flag{strings_flag}

### 5. The River is Overflowing!!!

- There is a name input at the beginning of game
- There is also an unused flag function in the code
- Use buffer overflow on the name input to return unused function
- FLAG: flag{overflow_flag}

### 6. A Duel You Say...

- Hidden in the maze is a goblin looking for a fight...
- Hopefully the user grabbed the sword, but it will do little
- 1/100 chance to kill goblin, based off time
- Find the correct time to run the program to get the right attack
- FLAG: flag{duel_flag}

### 7. A Hidden Path

- The game is XOR encrypted and the key "riddle"
- Decrypting and looking at text will show a path not visible in normal gameplay
- Access it by "use power of friendship" just before maze
- FLAG: flag{friendship_works}        

Room Definition:
ID: number of room to be referred to by other rooms
Name: name of room to be displayed
Description: description of room to be displayed
Directions: list of <direction>:<room_id>, enter <direction> to go to <room_id>
Items: list of item ids inside room

Item Definition:
ID: number of item to be referred to by rooms
Name: name of item to be displayed
Description: description of item to be displayed
Needed Room: room id for item to be used in
Replacement Room: new room id to replace room after successful use