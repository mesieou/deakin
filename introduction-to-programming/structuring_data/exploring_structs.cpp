#include "splashkit.h"

// Declare target_data struct here
struct target_data
{
    double x;
    double y;
    double radious;
};

// Add draw target here
void draw_target(target_data target)
{
    fill_circle(COLOR_AQUA, target.x, target.y, target.radious);
}

int main()
{
  open_window("Reaction Timer", 800, 600);

  target_data target;

  target.x = 400;
  target.y = 300;
  target.radious = 75;

  while (!quit_requested())
  {
    process_events();

    clear_screen(COLOR_WHITE);
    draw_target(target);
    refresh_screen();
  }

  return 0;
}