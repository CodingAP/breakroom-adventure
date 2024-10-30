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