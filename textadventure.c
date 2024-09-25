#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ITEMS 10

typedef struct {
    int id;
    char name[100];
    char description[255];
    int needed_room;
    int replacement_room;
    bool in_inventory;
} Item;

typedef struct {
    char name[20];
    int room_id;
} Direction;

typedef struct {
    int id;
    char name[100];
    char description[255];
    Direction directions[10];
    int num_directions;
    int item_ids[MAX_ITEMS];
} Room;

Room rooms[100];
Item items[50];
int current_room_id = 0;

Item inventory[MAX_ITEMS];
int inventory_count = 0;

void initialize_game();
void game_loop();
void add_direction(Room *room, const char *dir_name, int room_id);
void handle_command(char *input);
void take_item(char *item_name);
void inspect_item(char *item_name);
void use_item(char *item_name);
void copy_room(int source_room_id, int target_room_id);

int main() {
    initialize_game();
    game_loop();
    return 0;
}

void initialize_game() {
    rooms[0].id = 0;
    strcpy(rooms[0].name, "Starting Room");
    strcpy(rooms[0].description, "You are in a small, dimly lit room.");
    rooms[0].num_directions = 0;
    add_direction(&rooms[0], "north", 1);
    rooms[0].item_ids[0] = 0;

    rooms[1].id = 1;
    strcpy(rooms[1].name, "Second Room");
    strcpy(rooms[1].description, "You've entered a quiet gallery.");
    rooms[1].num_directions = 0;
    add_direction(&rooms[1], "south", 0);
    rooms[1].item_ids[0] = -1;

    rooms[2].id = 2;
    strcpy(rooms[1].name, "Opened Second Room");
    strcpy(rooms[1].description, "You've entered a quiet gallery with a door opened.");
    rooms[2].num_directions = 0;
    add_direction(&rooms[2], "south", 0);
    add_direction(&rooms[2], "north", 3);
    rooms[2].item_ids[0] = -1;

    rooms[3].id = 3;
    strcpy(rooms[1].name, "Empty Dungeon");
    strcpy(rooms[1].description, "There seems to be a dungeon, but with no dungeon-like elements.");
    rooms[3].num_directions = 0;
    add_direction(&rooms[3], "south", 1);
    rooms[3].item_ids[0] = -1;

    items[0].id = 0;
    strcpy(items[0].name, "Magic Key");
    strcpy(items[0].description, "A small, ornate key that glimmers with a faint, magical light.");
    items[0].needed_room = 1;
    items[0].replacement_room = 2;
    items[0].in_inventory = false;
}

void add_direction(Room *room, const char *dir_name, int room_id) {
    if (room->num_directions < 10) {
        strcpy(room->directions[room->num_directions].name, dir_name);
        room->directions[room->num_directions].room_id = room_id;
        room->num_directions++;
    }
}

void game_loop() {
    char input[100];
    while (1) {
        printf("You are in %s\n", rooms[current_room_id].name);
        printf("%s\n", rooms[current_room_id].description);
        printf("What do you want to do? ");
        fgets(input, sizeof(input), stdin);
        handle_command(input);
    }
}

void handle_command(char *input) {
    char *cmd = strtok(input, " \n");
    if (cmd == NULL) return;

    char *rest_of_input = strtok(NULL, "\n");

    if (strcmp(cmd, "go") == 0) {
        if (rest_of_input != NULL) {
            for (int i = 0; i < rooms[current_room_id].num_directions; i++) {
                if (strcmp(rooms[current_room_id].directions[i].name, rest_of_input) == 0) {
                    current_room_id = rooms[current_room_id].directions[i].room_id;
                    return;
                }
            }
            printf("You can't go that way.\n");
        } else {
            printf("Go where?\n");
        }
    } else if (strcmp(cmd, "take") == 0) {
        if (rest_of_input != NULL) {
            take_item(rest_of_input);
        } else {
            printf("Take what?\n");
        }
    } else if (strcmp(cmd, "inspect") == 0) {
        if (rest_of_input != NULL) {
            inspect_item(rest_of_input);
        } else {
            printf("Inspect what?\n");
        }
    } else if (strcmp(cmd, "use") == 0) {
        if (rest_of_input != NULL) {
            use_item(rest_of_input);
        } else {
            printf("Use what?\n");
        }
    } else {
        printf("Unknown command.\n");
    }
}

void take_item(char *item_name) {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (rooms[current_room_id].item_ids[i] != -1 && strcmp(items[rooms[current_room_id].item_ids[i]].name, item_name) == 0) {
            if (inventory_count < MAX_ITEMS) {
                inventory[inventory_count++] = items[rooms[current_room_id].item_ids[i]];
                items[rooms[current_room_id].item_ids[i]].in_inventory = true;
                rooms[current_room_id].item_ids[i] = -1;
                printf("%s taken.\n", item_name);
                return;
            } else {
                printf("Your inventory is full.\n");
                return;
            }
        }
    }
    printf("No such item here.\n");
}

void inspect_item(char *item_name) {
    for (int i = 0; i < inventory_count; i++) {
        if (strcmp(inventory[i].name, item_name) == 0) {
            printf("%s: %s\n", inventory[i].name, inventory[i].description);
            return;
        }
    }
    printf("You do not have a %s.\n", item_name);
}

void use_item(char *item_name) {
    for (int i = 0; i < inventory_count; i++) {
        if (strcmp(inventory[i].name, item_name) == 0) {
            if (inventory[i].needed_room == current_room_id) {
                if (inventory[i].replacement_room != -1) {
                    copy_room(inventory[i].replacement_room, inventory[i].needed_room);
                    printf("Using %s...\n", item_name);
                    printf("Something changed in the environment!\n");
                } else {
                    printf("Nothing happens.\n");
                }
            } else {
                printf("You can't use that here.\n");
            }
            return;
        }
    }

    printf("You don't have %s.\n", item_name);
}

void copy_room(int source_room_id, int target_room_id) {
    Room *source_room = NULL;
    Room *target_room = NULL;

    for (int i = 0; i < 100; i++) {
        if (rooms[i].id == source_room_id) source_room = &rooms[i];
        if (rooms[i].id == target_room_id) target_room = &rooms[i];
    }

    if (source_room == NULL || target_room == NULL) {
        printf("Invalid room ID(s). One or both rooms not found.\n");
        return;
    }

    strcpy(target_room->name, source_room->name);
    strcpy(target_room->description, source_room->description);

    target_room->num_directions = source_room->num_directions;
    for (int i = 0; i < source_room->num_directions; i++) {
        strcpy(target_room->directions[i].name, source_room->directions[i].name);
        target_room->directions[i].room_id = source_room->directions[i].room_id;
    }

    for (int i = 0; i < MAX_ITEMS; i++) {
        target_room->item_ids[i] = source_room->item_ids[i];
    }
}
