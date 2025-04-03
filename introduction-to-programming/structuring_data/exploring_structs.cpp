#include "splashkit.h"

using std::to_string;


// Declare target_data struct here
struct target_data
{
    double x;
    double y;
    double radious;
};

struct reaction_data 
{
    target_data target;
    int hits;
};


// Add draw target here
void draw_target(target_data target)
{
    fill_circle(COLOR_AQUA, target.x, target.y, target.radious);
}

target_data new_target(double x, double y, double radious)
{
    target_data target;
    target.x = x;
    target.y = y;
    target.radious = radious;
    
    return target;
}

target_data random_target()
{
    double radious = rnd(100);
    double diameter = radious * 2;
    double x = rnd(screen_width() - diameter) - radious;
    double y = rnd(screen_height() - diameter) - radious;
    
    target_data target = new_target(x, y, radious);
    
    return target;
}

reaction_data new_reaction_data()
{
    reaction_data new_data = { random_target(), 0 };
    return new_data;
}

bool mouse_over_target(target_data target)
{
    
    return point_in_circle(mouse_x(), mouse_y(), target.x, target.y, target.radious);
}

void draw_game(reaction_data game)
{
    clear_screen(COLOR_WHITE);
    draw_target(game.target);
    draw_text("Hits: " + to_string(game.hits), COLOR_BLUE_VIOLET, 700, 500);
    refresh_screen();
}

int main()
{
    open_window("Reaction Timer", 800, 600);
    
    //create the game data
    reaction_data game = new_reaction_data();
    
    while (!quit_requested())
    {
        process_events();
        
        
        if (mouse_clicked(LEFT_BUTTON) && mouse_over_target(game.target))
        {
            write_line(mouse_clicked(LEFT_BUTTON));
            game.target = random_target();
            game.hits++;
        }
        
        draw_game(game);
        
  }

  return 0;
}