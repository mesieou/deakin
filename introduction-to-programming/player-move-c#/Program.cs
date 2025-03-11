using static System.Console;
using static SplashKitSDK.SplashKit;

const int PLAYER_RADIUS = 50;

OpenWindow("Player Moving", 1280,720);

ClearScreen(ColorWhite());

FillCircle(ColorTurquoise(), 640,360, PLAYER_RADIUS);

RefreshScreen(60);

Delay(5000);




