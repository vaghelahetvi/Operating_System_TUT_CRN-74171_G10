#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "questions.h"
#include "players.h"
#include "jeopardy.h"

#define BUFFER_LEN 256
#define NUM_PLAYERS 4

// Function to tokenize a string into an array of tokens
void tokenize(char *input, char **tokens);

// Function to display final results
void show_results(player *players, int num_players);

int main(int argc, char *argv[])
{
    // Array to store player information
    player players[NUM_PLAYERS];
    char buffer[BUFFER_LEN] = {0};

    // Initialize the game
    initialize_game();

    // Prompt for players' names
    for (int i = 0; i < NUM_PLAYERS; ++i)
    {
        printf("Enter the name of Player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }

    // Main game loop
    while (1)
    {
        // Display game state
        display_categories();

        // Get player input for category and value
        char category[MAX_LEN];
        int value;
        printf("Enter the category and dollar amount (e.g., programming 100): ");
        scanf("%s %d", category, &value);

        // Check if the question has already been answered
        if (already_answered(category, value))
        {
            printf("This question has already been answered. Choose another.\n");
            continue;
        }

        // Display the question
        display_question(category, value);

        // Get player answer
        char answer[BUFFER_LEN];
        printf("Enter your answer: ");
        scanf("%s", answer);

        // Check if the answer is correct
        if (valid_answer(category, value, answer))
        {
            printf("Correct!\n");
            // Update player score
            update_score(players, NUM_PLAYERS, "player_name", value); // Replace "player_name" with the actual player's name
        }
        else
        {
            printf("Incorrect! The correct answer is ...\n");
        }

        // Mark the question as answered
        mark_answered(category, value);

        // Check if all questions are answered
        if (all_questions_answered())
        {
            break;
        }
    }

    // Display final results
    show_results(players, NUM_PLAYERS);

    return EXIT_SUCCESS;
}

// Function to tokenize a string into an array of tokens
void tokenize(char *input, char **tokens)
{
    // Implementation of string tokenization
    // (Omitted for brevity)
}

// Function to display final results
void show_results(player *players, int num_players)
{
    // Sorting players based on their scores (descending order)
    for (int i = 0; i < num_players - 1; ++i)
    {
        for (int j = 0; j < num_players - i - 1; ++j)
        {
            if (players[j].score < players[j + 1].score)
            {
                // Swap players
                player temp = players[j];
                players[j] = players[j + 1];
                players[j + 1] = temp;
            }
        }
    }

    // Display results
    printf("\nGame Results:\n");
    for (int i = 0; i < num_players; ++i)
    {
        printf("Player %d: %s - Score: %d\n", i + 1, players[i].name, players[i].score);
    }
}
