#include "splashkit.h"

int main()
{
    const int PLAYER_RADIUS = 50;
    const int PLAYER_SPEED = 3;
    int playerX = 640;
    int playerY = 360;
    
    open_window("Player Moving", 1280,720);
    
    while( !quit_requested() )
    {
        process_events();
        clear_screen(color_white());
    
        if( key_down(RIGHT_KEY) )
        {
            playerX += PLAYER_SPEED;
        }
        if ( key_down(LEFT_KEY) )
        {
            playerX -= PLAYER_SPEED;
        }
        if ( key_down(UP_KEY) )
        {
            playerY -= PLAYER_SPEED;
        }
        if ( key_down(DOWN_KEY) )
        {
            playerY += PLAYER_SPEED;
        }
        fill_circle(color_turquoise(), playerX,playerY, PLAYER_RADIUS);
    
        refresh_screen(60);
        //Provided movement to the player
    }
}
