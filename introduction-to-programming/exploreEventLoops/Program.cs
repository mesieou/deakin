using SplashKitSDK;
using static System.Convert;
using static SplashKitSDK.SplashKit;

//Open a window
OpenWindow("Event loops", 980, 720);

int radious = 50;
// window will keep opened until the user exits the window
while (! QuitRequested())
{
    ProcessEvents();

    //logic if user presses c
    if (KeyTyped(KeyCode.CKey))
    {
        ClearScreen(RandomColor());
    }

    //logic if user presses s
     if (KeyTyped(KeyCode.SKey))
    {
        radious = 10;
    }

    //logic if user presses m
     if (KeyTyped(KeyCode.MKey))
    {
        radious = 50;
    }

    //logic if user presses l
     if (KeyTyped(KeyCode.LKey))
    {
        radious = 100;
    }

    //logic if user presses 5
     if (KeyTyped(KeyCode.Num5Key))
    { 
        //added 100 random circles
        for (int i = 0; i < 100; i++)
        {
            FillCircle(RandomColor(), Rnd(ScreenWidth()), Rnd(ScreenHeight()), radious);
        }
    } 
    
    RefreshScreen();                       
}