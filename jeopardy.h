/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, Rushi Rathod, Shivam Patel, Hetvi Vaghela
 * All rights reserved.
 *
 */
#ifndef JEOPARDY_H_
#define JEOPARDY_H_

// Define the maximum length for strings
#define MAX_LEN 256

// Function to process the answer from the user containing "what is" or "who is" and tokenize it to retrieve the answer
extern void tokenize(char *input, char **tokens);

// Function to display the game results for each player, including their name and final score, ranked from first to last place
extern void show_results(player *players, int num_players);

#endif /* JEOPARDY_H_ */
