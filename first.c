#include <stdio.h>
#include <conio.h>

void debug_codes(int track_width, int speed, char track[]){
    printf("Track Width: %d\n", track_width);
    printf("Speed:       %d\n", speed);
    printf("Track:       %s\n", track);
}

int evaluateKeyCode(key_code){
    if (key_code == 'q'){
        return 0;
    }
    else
    {
        return 1;
    }
}


void main (){
    int track_width     = 12;           // Width of the track
    int speed           = 100;          // How fast the game goes. 
    int width_from_left = 20;           // Where the track appears from the left
    char track[80];                     // The track = "**              **\n";
    int player_pos      = 6;    // The player starts in the center of the track. 

    // Initialize track to be blank
    // If you don't do this you get 'debris' on the track from leftover memory sometimes.
    for (int i = 0; i <= 80; i++){
        track[i]= 32;
    }
    // debug_codes(track_width, speed, track);

    // printf(track);

    int go = 1;

    while (go){
        // track = generate_track();
        //printf(generate_track(6, track_width, 5));

        // Make space from the left
        for (int i = 0; i < width_from_left; i++){
            track[i] = ' ';
        }

        track[width_from_left-2] = 'L';
        track[width_from_left-1] = 'L';

        // Space before player
        for (int i = width_from_left+2; i < player_pos + width_from_left; i++){
            track[i] = ' ';
        }

        track[player_pos + width_from_left] = '*';

        // // Space after player
        // for (int i = 0; i< track_width - player_pos; i++){
        //     track[i] = ' ';
        // }

        // track[width_from_left + track_width] = '|';
        // track[width_from_left + track_width + 1] = '|';
        track[80]=' ';

        printf("%s\n", track);

        char key_code[1];
        
        // If a key is pressed, capture it.
        if ( kbhit() )
            key_code[0] = getch();

        // Determine what should be done with the key.
        if (key_code[0] == 'q'){
            go = 0;
            printf("Stopped here");
        }
        else if (key_code[0] == 'j'){
            printf("Left");
        }        
        else if (key_code[0] == 'l'){
            printf("Right");
        }
        // printf(c);
    }
}



