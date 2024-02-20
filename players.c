#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "players.h"

// Function to check if a player with the given name already exists
bool player_exists(player *players, int num_players, char *name)
{
    // Iterate through the array of players to find a match
    for (int i = 0; i < num_players; ++i) {
        if (strcmp(players[i].name, name) == 0) {
            return true; // Player with the given name exists
        }
    }
    return false; // Player with the given name does not exist
}

// Function to update the score of a player with the given name
void update_score(player *players, int num_players, char *name, int score)
{
    // Iterate through the array of players to find the player with the given name
    for (int i = 0; i < num_players; ++i) {
        if (strcmp(players[i].name, name) == 0) {
            players[i].score += score; // Update the score for the player
            break;
        }
    }
}
