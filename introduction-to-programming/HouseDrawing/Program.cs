using System.Drawing;
using static SplashKitSDK.SplashKit;
using static System.Convert;

//Creating some variables variable
const int SCREEN_WIDTH = 800, SCREEN_HEIGHT = 600, BOTTOM_GAP = 100;
const int HILL_HEIGHT = SCREEN_HEIGHT * 2 / 3;

int houseSize;
string userInput;
int wallX, wallY;
int roofLeft, roofMiddle, roofRight, roofTop;
int roofOverhang, roofHeight;

//Prompting the user for the house size and sabi
WriteLine("Enter the size of the size of the house: ");
userInput = ReadLine();
houseSize = ToInt32(userInput);

wallX = (SCREEN_WIDTH - houseSize) / 2;
wallY = SCREEN_HEIGHT - BOTTOM_GAP - houseSize;

roofOverhang = houseSize / 4;
roofHeight = houseSize * 3 / 4;
roofLeft = wallX - roofOverhang;
roofMiddle = wallX + houseSize / 2;
roofRight = wallX + houseSize + roofOverhang;
roofTop = wallY - roofHeight;

//cleaning the screen
ClearScreen(ColorWhite());

//Opening the window with the drawing
OpenWindow("House Drawing by Juan Bernal", 800, 600);

//Drawing a circle
FillEllipse(ColorBrightGreen(), 0, HILL_HEIGHT, SCREEN_WIDTH, HILL_HEIGHT);
//Drawing a rectangle
FillRectangle(ColorGray(), wallX, wallY, houseSize, houseSize);
// Drawing a triangle
FillTriangle(ColorRed(), roofLeft, wallY, roofMiddle,roofTop, roofRight, wallY);

//show the shape to the user
RefreshScreen();

Delay(5000);
