#include <stdio.h>
#include "utils.h"
#include <string.h>

void rock_paper_scissors(const char* player1, const char* player2, char* result) {
    if ((strcmp(player1, "Rock") && strcmp(player1, "Paper") && strcmp(player1, "Scissors")) ||
        (strcmp(player2, "Rock") && strcmp(player2, "Paper") && strcmp(player2, "Scissors"))) {
        strcpy(result, "Invalid");
        return;
    }
    if (strcmp(player1, player2) == 0) {
        strcpy(result, "Draw");
    }
    else if ((strcmp(player1, "Rock") == 0 && strcmp(player2, "Scissors") == 0) ||
        (strcmp(player1, "Scissors") == 0 && strcmp(player2, "Paper") == 0) ||
        (strcmp(player1, "Paper") == 0 && strcmp(player2, "Rock") == 0)) {
        strcpy(result, "Player1");
    }
    else {
        strcpy(result, "Player2");
    }
}