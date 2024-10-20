#include <stdio.h>

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

void meetCasper() {
    printf("You meet Casper, a friendly spirit in the form of a dog. He's excited to spend the days with you.\n");
}

void talkToCasper(int day) {
    // Placeholder for talking to Casper. You can add dialogues based on the day.
    printf("You talk to Casper. He seems %s today.\n", (day % 5 == 0) ? "thoughtful" : "cheerful");
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

void dayLoop() {
    int day = 1;
    const int totalDays = 365;
    int choice;

    while (day <= totalDays) {
        printf("\nDay %d\n", day);
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
                    printf("It's the final day... You say goodbye to Casper as he passes away.\n");
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
    displaySplashScreen();
    meetCasper();
    dayLoop();
    return 0;
}

// To compile: gcc main.c -o main
// To run: ./main

