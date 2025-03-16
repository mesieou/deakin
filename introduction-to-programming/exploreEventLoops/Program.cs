using SplashKitSDK;
using static System.Convert;
using static SplashKitSDK.SplashKit;

//Open a window
OpenWindow("Event loops", 980, 720);

// string radious;
// window will keep opened until the user exits the window
while (! QuitRequested())
{
    ProcessEvents();

    //logic if user presses c
    if (KeyTyped(KeyCode.CKey))
    {
        WriteLine("pressed c");
    }
     if (KeyTyped(KeyCode.SKey))
    {
        WriteLine("pressed s");
    }
     if (KeyTyped(KeyCode.MKey))
    {
        WriteLine("pressed m");
    }
     if (KeyTyped(KeyCode.LKey))
    {
        WriteLine("pressed l");
    }
     if (KeyTyped(KeyCode.Num5Key))
    {
        WriteLine("pressed 5");
    }                    



    //logic if the user clicks
      //draw circle where the user clicked with a random color
    

    //create the radious set to 50
    
}