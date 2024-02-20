/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, Rushi Rathod, Shivam Patel, Hetvi Vaghela
 * All rights reserved.
 *
 */
#ifndef PLAYERS_H_
#define PLAYERS_H_

#include <stdbool.h>

// Define the maximum length for player names
#define MAX_LEN 256

// Structure to represent a player
typedef struct {
    char name[MAX_LEN];
    int score;
} player;

// Function to check if a player with the given name already exists
extern bool player_exists(player *players, int num_players, char *name);

// Function to update the score of a player with the given name
extern void update_score(player *players, int num_players, char *name, int score);

#endif /* PLAYERS_H_ */
