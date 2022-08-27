#include <stdio.h>
#include <conio.h>

void main (){
    int track_width     = 12;           // Width of the track
    int speed           = 100;          // How fast the game goes. 
    int width_from_left = 20;           // Where the track appears from the left
    char track[80];                     // The track = "**              **\n";
    int player_pos      = 6 ;    // The player starts in the center of the track. 

    // Initialize track to be blank
    // If you don't do this you get 'debris' on the track from leftover memory sometimes.
    for (int i = 0; i <= 80; i++){
        track[i]= 32;
    }
    // debug_codes(track_width, speed, track);

    // printf(track);

    int go = 1;

    while (go){
        char key_code[1];
        // track = generate_track();
        //printf(generate_track(6, track_width, 5));

        // Make the row blank
        for (int i = 0; i <= 80; i++){
            track[i]= 32;
        }

        track[width_from_left-2] = 'L';
        track[width_from_left-1] = 'L';

        track[player_pos+width_from_left] = '*';

        track[width_from_left + track_width] = 'R';
        track[width_from_left + track_width + 1] = 'R';

        printf("%s\n", track);
        
        // If a key is pressed, capture it.
        if ( kbhit() )
            key_code[0] = getch();

        // a) Determine what should be done with the key.
        // b) Move the character
        // c) Test to see if a crash has happened.
        if (key_code[0] == 'q'){
            go = 0;
            printf("Stopped here");
        }
        else if (key_code[0] == 'j'){
            // Subtract player position
            player_pos--;
            if (player_pos + width_from_left == (width_from_left-1)){
                printf("You hit the left side of the track.");
                go = 0;
            }
            key_code[0] =' ';
        }        
        else if (key_code[0] == 'l'){
            // Add player position
            player_pos++;
            if (player_pos+width_from_left == (width_from_left + track_width)){
                printf("You hit the right side of the track.");
                go = 0;
            }            
            key_code[0] =' ';
        }
        //printf ("Left: %d Player: %d, Right: %d", width_from_left, player_pos+width_from_left, (width_from_left + track_width - 1));
        // printf(c);
    }
}



