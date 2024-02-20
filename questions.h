/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, Rushi Rathod, Shivam Patel, Hetvi Vaghela 
 * All rights reserved.
 *
 */
#ifndef QUESTIONS_H_
#define QUESTIONS_H_

#include <stdbool.h>

// Define the maximum length for strings
#define MAX_LEN 256

// Define the number of categories and questions
#define NUM_CATEGORIES 3
#define NUM_QUESTIONS 12

// Structure to represent a question
typedef struct {
    char category[MAX_LEN];
    char question[MAX_LEN * 2];
    char answer[MAX_LEN];
    int value;
    bool answered;
} question;

// Array to store the categories
extern char categories[NUM_CATEGORIES][MAX_LEN];

// Array of questions, initialized in initialize_game function
// This may need to be a pointer if you want it set dynamically
extern question questions[NUM_QUESTIONS];

// Function to initialize the array of questions for the game
extern void initialize_game(void);

// Function to display each of the remaining categories and question dollar values that have not been answered
extern void display_categories(void);

// Function to display the question for the specified category and dollar value
extern void display_question(char *category, int value);

// Function to check if the answer is correct for the specified category and dollar value
extern bool valid_answer(char *category, int value, char *answer);

// Function to check if the question has already been answered
extern bool already_answered(char *category, int value);

#endif /* QUESTIONS_H_ */
