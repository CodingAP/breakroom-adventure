# RazorHack CTF 2024 - Breakroom Adventures
#### by Alex Prosser

> Look, I found this old game on one of the computers in the breakroom! It seems to have a good amount of content from what I was looking at, so why don't you look into it and see if it is worth anything. It may even have some easter eggs that no one has seen before!

The flags will take the structure of `flag{FLAG_HERE_XXXXX}`.

## Challenges

### 1. Just Like The Good Ole Days

> It seems like there is some areas to find as you move forward, so don't hesitate to do some exploring!

Flag: `flag{one_small_step_29103}`

- Do some exploring, finish the maze

### 2. It Seem's Impenetrable...

> Wow, there is a big castle in the distance on the cover art of GameTDB! Maybe you could go find something there in the game.

Flag: `flag{did_you_backtrack_48421}`

- when approaching the castle, you need a key (easter egg to adventure)
- find key in maze

### 3. Answer Be, These Riddles Three

> I've heard that there is this king that will grant all your wishes if you can answer his riddles. This seems kinda cliche for an adventure game, but why not?

Flag: `flag{pfft_what_a_gamer_92101}`

- Answer three riddles said by the king

### 4. Just a Peek

> I've always wondered what the text adventure will look like in the code itself, maybe you can explore the binary to find something cool?

Flag: `flag{uber_hacker_number_one_45391}`

- Before name input, there is a flag stored in the name string
- Use the 'strings' command to find it

### 5. The River is Overflowing!!!

> I've managed to look into a small part of the code myself, and there seems to be a debug function that isn't called anywhere that can show a cool easter egg!

Flag: `flag{it_couldnt_be_contained_63904}`

- There is a name input at the beginning of game
- There is also an unused flag function in the code
- Use buffer overflow on the name input to return unused function

### 6. A Duel You Say...

> Looking on Reddit, there seems to be an unbeatable goblin in the game, but it can't be that hard right?

Flag: `flag{one_of_these_will_work_24431}`

- Hidden in the maze is a goblin looking for a fight...
- Hopefully the user grabbed the sword, but it will do little
- 1/100 chance to kill goblin, based off time
- Find the correct time to run the program to get the right attack

### 7. A Hidden Path

> I don't think that you can find anymore easter eggs, there just doesn't seem to be a place to hide them. The only way to confirm is to look at the source code, but we can't get a full copy, right?
Flag: `flag{friendship_always_works_11259}`       

- The game is XOR encrypted and the key "riddles"
- Decrypting and looking at text will show a path not visible in normal gameplay

**Room Definition:**
ID: number of room to be referred to by other rooms
Name: name of room to be displayed
Description: description of room to be displayed
Directions: list of <direction>:<room_id>, enter <direction> to go to <room_id>
Items: list of item ids inside room

**Example:**
0
Example Room
This is an example of a room that can be created, just so I can make sure the format is correct
north:1 south:2
0 1

**Item Definition:**
ID: number of item to be referred to by rooms
Name: name of item to be displayed
Description: description of item to be displayed
Needed Room: room id for item to be used in
Replacement Room: new room id to replace room after successful use

**Example:**
0
Example Item
This is an example of a item that can be created, just so I can make sure the format is correct
0
1