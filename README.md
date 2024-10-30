# RazorHack CTF 2024 - Breakroom Adventures
#### by Alex Prosser

> Look, I found this old game on one of the computers in the breakroom! It seems to have a good amount of content from what I was looking at, so why don't you look into it and see if it is worth anything. It may even have some easter eggs that no one has seen before!

The flags will take the structure of `flag{FLAG_HERE_XXXXX}`.

[Write-Up with Answers and Guide](https://codingap.github.io/blog/posts/razorhack-ctf-2024-breakroom-adventure/)

## Challenges

### 1. Just Like The Good Ole Days

> It seems like there is some areas to find as you move forward, so don't hesitate to do some exploring!

### 2. It Seem's Impenetrable...

> Wow, there is a big castle in the distance on the cover art of GameTDB! Maybe you could go find something there in the game.

### 3. Answer Be, These Riddles Three

> I've heard that there is this king that will grant all your wishes if you can answer his riddles. This seems kinda cliche for an adventure game, but why not?

### 4. Just a Peek

> I've always wondered what the text adventure will look like in the code itself, maybe you can explore the binary to find something cool?

### 5. The River is Overflowing!!!

> I've managed to look into a small part of the code myself, and there seems to be a debug function that isn't called anywhere that can show a cool easter egg!

### 6. A Duel You Say...

> Looking on Reddit, there seems to be an unbeatable goblin in the game, but it can't be that hard right?

### 7. A Hidden Path

<<<<<<< HEAD
> I don't think that you can find anymore easter eggs, there just doesn't seem to be a place to hide them. The only way to confirm is to look at the source code, but we can't get a full copy, right?
=======
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
>>>>>>> 249e3301138e6d02183118b01ec68321e6abbc62
