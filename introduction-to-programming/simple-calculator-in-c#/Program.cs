// See https://aka.ms/new-console-template for more information
using static SplashKitSDK.SplashKit;
using static System.Convert;

//create the variables
double kilometersTraveled, kilometersToDestination, kilometersPerHour, totalDistance, mintutePerKilometer;
int minutesSpent, minutesToArrive, totalTime;
string name;

//Name prompt
WriteLine("Please enter your name: ");
//user name saved in the name variavle
name = ReadLine();

//welcoming message
WriteLine($"Hello {name}, Welcome!");

//user prompt
WriteLine("How far have you travelled so far?: Enter kilometers");
//user name saved in the name variavle
kilometersTraveled = ToDouble(ReadLine());

//user propmt
WriteLine("How long has it taken?. Enter minutes: ");
//minutes spent saved in the name variavle
minutesSpent = ToInt32(ReadLine());

// calculating kilometers per hour 
kilometersPerHour = kilometersTraveled * 60 / minutesSpent;

//Kilometers per hour output
WriteLine($"Your average speed is {kilometersPerHour} km/h");

//user prompt
WriteLine("How far do you have to go? Enter kilometers:");
kilometersToDestination = ToDouble(ReadLine());

//minutes to arrive calculation
totalDistance = kilometersTraveled + kilometersToDestination;
mintutePerKilometer = kilometersTraveled / minutesSpent;
minutesToArrive = ToInt32(kilometersToDestination / mintutePerKilometer);
totalTime = minutesSpent + minutesToArrive;

//remaining time output
WriteLine($"You will take another {minutesToArrive} minutes before you arrive.");

//total distance ouput
WriteLine($"Total distance will be {totalDistance} kms");

//total time ouput
WriteLine($"Total time will be {totalTime} minutes");









