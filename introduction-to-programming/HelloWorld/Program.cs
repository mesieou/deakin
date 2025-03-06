//access to Splash and Syste Conver libraries
using System.Runtime.CompilerServices;
using static SplashKitSDK.SplashKit;
using static System.Convert;

//setting up variables
string UserInput;
int width, height, seconds;

//Output
WriteLine("Window Test");

// Promp the user to type Width and saves it in the UserInput variable
Write("How do you want the window. Please enter Width:");
UserInput = ReadLine();

width = ToInt32(UserInput);

Write("How high do you want the window to be: Plrease enter the height:");
UserInput = ReadLine();

height = ToInt32(UserInput);

Write("Type the number of seconds:");
UserInput = ReadLine();

seconds = ToInt32(UserInput);

OpenWindow("Test Window", width, height);





