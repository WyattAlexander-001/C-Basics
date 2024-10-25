#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // For handling strings
#include <time.h>  // For randomization

#define MAX_LINE_LENGTH 100
#define MAX_DIALOGUE_LENGTH 512
#define MAX_DIALOGUES 100

void displaySplashScreen() {
    printf("\nWelcome to the Adventure of Casper!\n\n");
    printf("      / \\__\n");
    printf("     (    @\\___\n");
    printf("     /         O\n");
    printf("    /   (_____/ \n");
    printf("   /_____/   U\n\n");
    printf("Press any key to start your adventure...\n");
    getchar(); // Wait for user input
}

void displayArt(const char* filename) {
    FILE *file = fopen(filename, "r"); // Open the file in read mode
    if (file == NULL) {
        perror("Error opening file");
        exit(1); // Exit if file cannot be opened
    }

    char line[MAX_LINE_LENGTH];  // Allocate a char array for reading lines

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        printf("%s", line); // Print each line of the file
    }

    fclose(file); // Close the file
}

void meetCasper() {
    printf("You meet Casper, he is your new pomeranian friend. He's excited to spend his days with you.\n");
}

// Function to read dialogues from a file, separated by commas
void readDialogues(char dialogues[MAX_DIALOGUES][MAX_DIALOGUE_LENGTH], const char* filename, int *count) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    char line[MAX_DIALOGUE_LENGTH]; // Buffer to hold each line
    while (fgets(line, MAX_DIALOGUE_LENGTH, file) != NULL && *count < MAX_DIALOGUES) {
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0'; // Remove newline character
        }
        strncpy(dialogues[*count], line, MAX_DIALOGUE_LENGTH);
        dialogues[*count][MAX_DIALOGUE_LENGTH - 1] = '\0'; // Ensure null termination
        (*count)++;
    }
    fclose(file);
}


void feedCasper() {
    // Placeholder for feeding Casper.
    printf("You feed Casper. He wags his tail happily.\n");
}

void walkCasper() {
    // Placeholder for walking Casper.
    printf("You take Casper for a walk. He enjoys the scenery.\n");
}

void goToBed(int *day) {
    // Increment the day counter.
    (*day)++;
    printf("You go to bed. A new day begins...\n");
}

void talkToCasper(int day) {
    static char dialogues[MAX_DIALOGUES][MAX_DIALOGUE_LENGTH];
    static int numDialogues = 0;
    static int initialized = 0;

    if (!initialized) {
        readDialogues(dialogues, "./dialogue/casperRandomQuotes.txt", &numDialogues);
        initialized = 1;
    }

    printf("You talk to Casper.\n");

    if (day == 1) {
        printf("Casper: Woof! Woof! I'm so happy to meet you!\n");
    } else if (day % 7 == 0) {
        printf("Casper: Woof! Woof! It's been a week! I love you!\n");
    } else if (day == 365) {
        printf("Casper: Woof! Woof! It's been a year! I love you!\n");
    } else if (day % 2 == 0 && numDialogues > 0) {
        int index = rand() % numDialogues;
        printf("Random index: %d, Total Dialogues: %d, Dialogue: %s\n", index, numDialogues, dialogues[index]);
    } else {
        printf("Casper: Woof! Woof!\n");
    }
}



void dayLoop() {
    int day = 1;
    const int totalDays = 365;
    int choice;

    while (day <= totalDays) {

        printf("\nDay %d\n", day);
        displayArt("art/casper.txt");  // Display ASCII art from file        
        printf("What would you like to do today?\n");
        printf("1. Talk to Casper\n");
        printf("2. Feed Casper\n");
        printf("3. Walk Casper\n");
        printf("4. Go to bed for the day\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                talkToCasper(day);
                break;
            case 2:
                feedCasper();
                break;
            case 3:
                walkCasper();
                break;
            case 4:
                goToBed(&day);
                if (day > totalDays) {
                    printf("It's past the final day... You say goodbye to Casper as he passes away.\n");
                    return; // End the loop and the game.
                }
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                continue;
        }
    }
}


int main() {
    time_t seed = time(NULL);
    srand((unsigned int)seed); // Seed random number generator
    printf("Seed used: %ld\n", seed);  // Debug: print the seed value

    displaySplashScreen();
    meetCasper();
    dayLoop();
    return 0;
}


// To compile: gcc main.c -o main
// To run: ./main

