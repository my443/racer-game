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
    int track_width = 12;           // Width of the track
    int speed       = 100;          // How fast the game goes. 

    char track[80] = "**              **\n";

    // debug_codes(track_width, speed, track);

    // printf(track);

    int go = 1;

    while (go){
        printf(track);
        char key_code[1];

        //key_code[0] = getch();
        //printf("%c", getch());
        //printf("%c", key_code[0]);
        
        if ( kbhit() )
            key_code[0] = getch();
            //printf("%d", evaluateKeyCode(key_code));
            // do stuff depending on key_code

        //printf(c);
        if (key_code[0] == 'q'){
            go = 0;
            printf("Stopped here");
        }
        // printf(c);
    }
}



