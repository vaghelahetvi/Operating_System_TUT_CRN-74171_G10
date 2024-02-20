// questions.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "questions.h"

// An array to store the different categories of questions
char categories[NUM_CATEGORIES][MAX_LEN] = {
    "programming", 
    "algorithms", 
    "databases"
};

// An array to store the questions and their details
question questions[NUM_QUESTIONS];

// Function to initialize the array of questions for the game
void initialize_game(void)
{
    // initialize each question struct and assign it to the questions array

    strcpy(questions[0].category, "programming");
    strcpy(questions[0].question, "What is the file extension for a Python source code file");
    strcpy(questions[0].answer, ".py");
   
    questions[0].value = 100;
    questions[0].answered = false;
    
    strcpy(questions[1].category, "algorithms");
    strcpy(questions[1].question, "What data structure follows the First In, First Out (FIFO) principle?");
    strcpy(questions[1].answer, "queue");
   
    questions[1].value = 100;
    questions[1].answered = false;
    
    strcpy(questions[2].category, "databases");
    strcpy(questions[2].question, "What type of database model stores data in tables with rows and columns?");
    strcpy(questions[2].answer, "Relational");
   
    questions[2].value = 100;
    questions[2].answered = false;
    

    strcpy(questions[3].category, "programming");
    strcpy(questions[3].question, "Which programming language is known for its use in developing Android applications");
    strcpy(questions[3].answer, "java");
   
    questions[3].value = 200;
    questions[3].answered = false;
    
    strcpy(questions[4].category, "algorithms");
    strcpy(questions[4].question, "In algorithmic analysis, what does O(n) represent?");
    strcpy(questions[4].answer, "linear");
   
    questions[4].value = 200;
    questions[4].answered = false;
    
    strcpy(questions[5].category, "databases");
    strcpy(questions[5].question, "In a relational database, what represents a single data value in a record?");
    strcpy(questions[5].answer, "attribute");
   
    questions[5].value = 200;
    questions[5].answered = false;
    

    strcpy(questions[6].category, "programming");
    strcpy(questions[6].question, "What is the purpose of the printf function in C");
    strcpy(questions[6].answer, "print");
    
    questions[6].value = 300;
    questions[6].answered = false;
    
    strcpy(questions[7].category, "algorithms");
    strcpy(questions[7].question, "In algorithmic complexity, what does O(1) represent?");
    strcpy(questions[7].answer, "constant");
    
    questions[7].value = 300;
    questions[7].answered = false;
    
    strcpy(questions[8].category, "databases");
    strcpy(questions[8].question, " What operation is used to combine rows from two or more tables based on a related column?");
    strcpy(questions[8].answer, "Join");
   
    questions[8].value = 300;
    questions[8].answered = false;
    

    strcpy(questions[9].category, "programming");
    strcpy(questions[9].question, "Who invented python programming language?");
    strcpy(questions[9].answer, " Guido");
   
    questions[9].value = 400;
    questions[9].answered = false;
    
    strcpy(questions[10].category, "algorithms");
    strcpy(questions[10].question, "What is the term for an algorithm that solves a problem by solving smaller instances of the same problem?");
    strcpy(questions[10].answer, "recursion");
   
    questions[10].value = 400;
    questions[10].answered = false;
    
    strcpy(questions[11].category, "databases");
    strcpy(questions[11].question, "What clause is used to filter records in a SQL query?");
    strcpy(questions[11].answer, "WHERE");
  
    questions[11].value = 400;
    questions[11].answered = false;
}


// Function to display each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    // Print categories and dollar values for each unanswered question in the questions array
    printf("Available Categories:\n");
    for (int i = 0; i < NUM_QUESTIONS; ++i) {
        if (!already_answered(questions[i].category, questions[i].value)) {
            printf("%d. %s ($%d)\n", i + 1, questions[i].category, questions[i].value);
        }
    }
}

// Function to display the question for the specified category and dollar value
void display_question(char *category, int value)
{
    for (int i = 0; i < NUM_QUESTIONS; ++i) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            printf("Question: %s\n", questions[i].question);
            break;
        }
    }
}

// Function to check if the answer is correct for the specified category and dollar value
bool valid_answer(char *category, int value, char *answer)
{
    // Check if the provided answer matches the correct answer for the question
    for (int i = 0; i < NUM_QUESTIONS; ++i) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            return (strcmp(questions[i].answer, answer) == 0);
        }
    }
    return false;
}

// Function to check if the question has already been answered
bool already_answered(char *category, int value)
{
    // Check if the question has already been marked as answered
    for (int i = 0; i < NUM_QUESTIONS; ++i) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            return questions[i].answered;
        }
    }
    return false;
}

// Function to mark the question as answered
void mark_answered(char *category, int value)
{
    // Mark the question as answered
    for (int i = 0; i < NUM_QUESTIONS; ++i) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            questions[i].answered = true;
            break;
        }
    }
}

// Function to check if all questions have been answered
bool all_questions_answered(void)
{
    // Check if all questions have been answered
    for (int i = 0; i < NUM_QUESTIONS; ++i) {
        if (!questions[i].answered) {
            return false;
        }
    }
    return true;
}