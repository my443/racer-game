#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

void main (){
    int track_width     = 12;           // Width of the track
    int speed           = 100;          // How fast the game goes. 
    
    char track[80];                     // The track = "**              **\n";

    int width_from_left = 20;           // Where the track appears from the left
    int player_pos      = 6 ;           // The player starts in the center of the track. 
    int direction       = 0;            // Random number to determine which direction the track will go.
    int go_direction    = 0;            // Direction that the track will move

    // Initialize the random number     (https://stackoverflow.com/questions/822323/how-to-generate-a-random-int-in-c)
    srand(time(NULL));                  // Initialization, should only be called once.
    
    // Clear the screen
    clrscr();
    
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

        //sleep(100);

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
        if (player_pos + width_from_left == (width_from_left)){
            printf("You hit the left side of the track.");
            go = 0;
        }
        else if (player_pos + width_from_left >= (width_from_left + track_width+1)){
            printf("You hit the right side of the track.");
            go = 0;
        }

        // From the captured keypress:
        //      a) Determine what should be done with the key.
        //      b) Move the character if needed
        if (key_code[0] == 'q'){
            go = 0;
            printf("Stopped here");
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
}



