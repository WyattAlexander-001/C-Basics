#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 100
#define MAX_DIALOGUE_LENGTH 512
#define MAX_DIALOGUES 100

// Happiness thresholds
#define VERY_SAD_THRESHOLD 20
#define SAD_THRESHOLD 40
#define HAPPY_THRESHOLD 60
#define VERY_HAPPY_THRESHOLD 80
#define MAX_HAPPINESS 100
#define MIN_HAPPINESS 0

int casperHappiness = 50;  // Initialize Casper's happiness level
int talkedToday = 0; // Flag to check if Casper has been talked to today

char verySadDialogues[MAX_DIALOGUES][MAX_DIALOGUE_LENGTH];
int numVerySadDialogues = 0;
char sadDialogues[MAX_DIALOGUES][MAX_DIALOGUE_LENGTH];
int numSadDialogues = 0;
char neutralDialogues[MAX_DIALOGUES][MAX_DIALOGUE_LENGTH];
int numNeutralDialogues = 0;
char happyDialogues[MAX_DIALOGUES][MAX_DIALOGUE_LENGTH];
int numHappyDialogues = 0;
char veryHappyDialogues[MAX_DIALOGUES][MAX_DIALOGUE_LENGTH];
int numVeryHappyDialogues = 0;
char randomQuotes[MAX_DIALOGUES][MAX_DIALOGUE_LENGTH];
int numRandomQuotes = 0;
char randomQuestions[MAX_DIALOGUES][MAX_DIALOGUE_LENGTH];
int numRandomQuestions = 0;

// Function prototypes
void readDialogues(char dialogues[][MAX_DIALOGUE_LENGTH], const char* filename, int *count);
void talkToCasper(int day);
void displaySplashScreen();
void displayArt(const char* filename);
void meetCasper();
void feedCasper();
void walkCasper();
void goToBed(int *day);
void dayLoop();

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
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        printf("%s", line);
    }
    fclose(file);
}

void meetCasper() {
    printf("You meet Casper, he is your new pomeranian friend. He's excited to spend his days with you.\n");
}


void trimWhitespace(char *str) {
    char *start = str;
    char *end;

    // Trim leading space
    while (isspace((unsigned char)*start)) start++;

    if (*start == 0) {  // All spaces?
        *str = 0;  // A string of all spaces makes it an empty string
        return;
    }

    // Trim trailing space
    end = start + strlen(start) - 1;
    while (end > start && isspace((unsigned char)*end)) end--;

    // Write new null terminator character
    *(end + 1) = '\0';

    // Shift the trimmed string to the start of the buffer
    memmove(str, start, end - start + 2);
}

void readDialogues(char dialogues[][MAX_DIALOGUE_LENGTH], const char* filename, int *count) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }
    char line[MAX_DIALOGUE_LENGTH];
    while (fgets(line, sizeof(line), file) != NULL) {
        trimWhitespace(line);  // Trim whitespace from the line read
        if (line[0] != '\0') {  // Check if line is not empty after trimming
            strncpy(dialogues[*count], line, MAX_DIALOGUE_LENGTH);
            dialogues[*count][MAX_DIALOGUE_LENGTH - 1] = '\0';  // Ensure null termination
            // printf("Loaded dialogue: '%s'\n", dialogues[*count]);  // Debug print
            (*count)++;
        }
    }
    fclose(file);
}





void feedCasper() {
    printf("You feed Casper. He wags his tail happily.\n");
}

void walkCasper() {
    printf("You take Casper for a walk. He enjoys the scenery.\n");
}

void goToBed(int *day) {
    (*day)++;
    talkedToday = 0;  // Reset daily talk flag
    printf("You go to bed. A new day begins...\n");
}

void talkToCasper(int day) {
    if (talkedToday) {
        printf("You have already talked to Casper today.\n");
        return;
    }
    printf("You talk to Casper.\n");
    talkedToday = 1;  // Mark as talked to for today

    if (day % 2 == 0 && numRandomQuotes > 0) {
        int index = rand() % numRandomQuotes;
        printf("Casper says: %s\n", randomQuotes[index]);
    }

    char (*questions)[MAX_DIALOGUE_LENGTH];
    int numQuestions = 0;

    // Assign questions based on happiness thresholds
    if (casperHappiness <= VERY_SAD_THRESHOLD) {
        questions = verySadDialogues;
        numQuestions = numVerySadDialogues;
    } else if (casperHappiness <= SAD_THRESHOLD) {
        questions = sadDialogues;
        numQuestions = numSadDialogues;
    } else if (casperHappiness >= HAPPY_THRESHOLD) {
        questions = happyDialogues;
        numQuestions = numHappyDialogues;
    } else if (casperHappiness >= VERY_HAPPY_THRESHOLD) {
        questions = veryHappyDialogues;
        numQuestions = numVeryHappyDialogues;
    } else {
        questions = neutralDialogues;  // Use neutral dialogues for mid-range happiness
        numQuestions = numNeutralDialogues;
    }

    if (numQuestions > 0) {
        int questionIndex = rand() % numQuestions;
        printf("Casper asks: %s (Yes/No): ", questions[questionIndex]);

        char response[10];
        scanf("%s", response);

        // Check for affirmative response
        if (strcasecmp(response, "Yes") == 0 || strcasecmp(response, "y") == 0) {
            casperHappiness += 10; // Increase happiness
            printf("Casper looks happier!\n");
        } else {
            casperHappiness -= 10; // Decrease happiness
            printf("Casper seems a bit sad.\n");
        }

        // Check if Casper becomes too sad
        if (casperHappiness <= MIN_HAPPINESS) {
            printf("Casper is too sad and has passed away...\n");
            exit(0); // End the game if too sad
        }
        printf("Casper's happiness is now: %d\n", casperHappiness);
    } else {
        printf("Casper seems content today and does not have any questions.\n");
    }
}



void dayLoop() {
    int day = 1;
    const int totalDays = 365;
    char input[100];

    while (day <= totalDays) {
        printf("\nDay %d\n", day);
        displayArt("art/casper.txt");
        printf("What would you like to do today?\n");
        printf("1. Talk to Casper\n2. Feed Casper\n3. Walk Casper\n4. Go to bed for the day\n9. Exit the game\nEnter your choice: ");
        fgets(input, sizeof(input), stdin);  // Read input as a string

        // Check for 'quit' or '9' to exit
        if (strncmp(input, "quit", 4) == 0 || strncmp(input, "9", 1) == 0) {
            printf("Goodbye! Thanks for playing.\n");
            exit(0);  // Exit the program
        }
        int choice = atoi(input);  // Converts string to integer, returns 0 if conversion fails

        switch(choice) {
            case 1:
                talkToCasper(day);
                break;
            case 2:
                feedCasper();
                casperHappiness += 5;
                break;
            case 3:
                walkCasper();
                casperHappiness += 5;
                break;
            case 4:
                goToBed(&day);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                continue;
        }
        if (day > totalDays) {
            printf("It's past the final day... You say goodbye to Casper as he passes away.\n");
            return;
        }
    }
}

int main() {
    srand((unsigned int)time(NULL)); // Seed random number generator

    readDialogues(randomQuotes, "./dialogue/casperRandomQuotes.txt", &numRandomQuotes);
    readDialogues(sadDialogues, "./dialogue/sadDialogues.txt", &numSadDialogues);
    readDialogues(happyDialogues, "./dialogue/happyDialogues.txt", &numHappyDialogues);
    readDialogues(neutralDialogues, "./dialogue/neutralDialogues.txt", &numNeutralDialogues);
    readDialogues(verySadDialogues, "./dialogue/verySadDialogues.txt", &numVerySadDialogues);
    readDialogues(veryHappyDialogues, "./dialogue/veryHappyDialogues.txt", &numVeryHappyDialogues);
    readDialogues(randomQuestions, "./dialogue/randomQuestions.txt", &numRandomQuestions);

    displaySplashScreen();
    meetCasper();
    dayLoop();
    return 0;
}
