#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

char intro_screen(){
    char press_any_key = ' ';

    system("cls");  
    printf("\n\n\n\n\n\n\n\n\n\n");
    printf("                 _______      _______      _______      _______      _______\n"); 
    printf("                (  ____ )    (  ___  )    (  ____ \\    (  ____ \\    (  ____ )\n");
    printf("                | (    )|    | (   ) |    | (    \\/    | (    \\/    | (    )|\n");
    printf("                | (____)|    | (___) |    | |          | (__        | (____)|\n");
    printf("                |     __)    |  ___  |    | |          |  __)       |     __)\n");
    printf("                | (\\ (       | (   ) |    | |          | (          | (\\ (   \n");
    printf("                | ) \\ \\__    | )   ( |    | (____/\\    | (____/\\    | ) \\ \\__\n");
    printf("                |/   \\__/    |/     \\|    (_______/    (_______/    |/   \\__/\n");

    printf("\n\n\n");
    printf("                                   A CLASSIC RACING GAME\n\n\n");

    printf("                               -j- makes your racer go left.\n");
    printf("                               -l- makes your racer go right.\n");
    printf("                               -q- quits the game.\n");
    printf("\n\n\n");
    printf("                                    Press any key to begin.");
    press_any_key = getch();



    return press_any_key;

}

void exit_game(){
    printf("\n\nThanks for racing!\nSee you soon!");
    exit(0);
}


void main (){
    int track_width     = 12;           // Width of the track
    int speed           = 75;           // How fast the game goes. The smaller the number, the faster the game.4
    int speed_input     = 1;            // An integer to get the speed of the game. 
    
    char track[80];                     // The track = "**              **\n";

    int width_from_left = 20;           // Where the track appears from the left
    int player_pos      = 6 ;           // The player starts in the center of the track. 
    int direction       = 0;            // Random number to determine which direction the track will go.
    int go_direction    = 0;            // Direction that the track will move
    char press_any_key  =' ';            // To get the press any key from intro screen
    // Initialize the random number     (https://stackoverflow.com/questions/822323/how-to-generate-a-random-int-in-c)
    srand(time(NULL));                  // Initialization, should only be called once.

    press_any_key = intro_screen();

    if (press_any_key == 'q'){
        exit_game();
    }

    printf("\n\nHow wide do you want the track to be? Enter a number between 6 and 30.\n");
    scanf("%d", &track_width);
    printf("How fast do you want to go? Choose between 1(slowest) and 5(fastest).\n");
    scanf("%d", &speed_input);

    speed = 150 -(speed_input * 25);    
    // Clear the screen
    system("cls");  
    
    // Initialize track to be blank
    // If you don't do this you get 'debris' on the track from leftover memory sometimes.
    for (int i = 0; i <= 80; i++){
        track[i]= 32;
    }

    int go = 1;

    while (go){
        char key_code[1];

        // Make the row blank
        for (int i = 0; i <= 80; i++){
            track[i]= 32;
        }

        sleep(speed);

        track[width_from_left-2] = 'L';
        track[width_from_left-1] = 'L';

        track[width_from_left + track_width] = 'R';
        track[width_from_left + track_width + 1] = 'R';

        track[player_pos + width_from_left] = '*';

        printf("%s\n", track);
        
        // If a key is pressed, capture it.
        if ( _kbhit() )
            key_code[0] = getch();

        // Test to see if the player hits a wall
        if (player_pos + width_from_left == (width_from_left-1)){
            printf("You hit the left side of the track.");
            go = 0;
            getch();
        }
        else if (player_pos + width_from_left >= (width_from_left + track_width)){
            printf("You hit the right side of the track.");
            go = 0;
            getch();
        }

        // From the captured keypress:
        //      a) Determine what should be done with the key.
        //      b) Move the character if needed
        if (key_code[0] == 'q'){
            go = 0;
            exit_game();
            
        }
        else if (key_code[0] == 'j'){
            // Subtract player position
            player_pos--;
            key_code[0] =' ';
        }        
        else if (key_code[0] == 'l'){
            // Add player position
            player_pos++;
            key_code[0] =' ';
        }

        direction = rand() % 3;      // Returns a pseudo-random integer between 0 and RAND_MAX.
        // direction = 2;

        if (direction == 1){
            // Track position goes to the left, but player positions stays the same.
            width_from_left--;
            player_pos++;
            // If it gets to close to the left side, make sure it doesn't go off the screen.
            if (width_from_left == 0){
                width_from_left = 1;
            }
        }
        else if (direction == 2){
            // Track position goes to the right, but player position stays in the same place.
            width_from_left++;
            player_pos--;
            if (width_from_left == (79 - track_width)){
                // Don't let it go off the right side of the screen.
                width_from_left = (78 - track_width);
            }
       }  // else - if it is a zero, the width from left doesn't change at all.
    }
    main();
}



// Here are some ideas of what you could add to the game to increase player engagement.
// TODO - Add a scoring section based on how many rows are printed or how long you go
// TODO - After a set amount of time (or rows) increase the speed of the game. 
// TODO - Put 'billboards' along the side, or in the middle of the track to let people know that they have increased speed or moved to the next level. 
// TODO - Check the speed and width entries to ensure that they are valid. 

// Bugs
// If you enter a character for the speed or width, it doesn't ask you again. 