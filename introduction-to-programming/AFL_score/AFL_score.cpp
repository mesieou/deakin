#include "splashkit.h"
#include <sstream>  // For stringstream

using namespace std;

const int GOAL_POINTS = 6;
const int BEHIND_POINTS = 1;

// Prompts the user for a string and return user's output
string read_string(string prompt)
{
    write_line(prompt);
    return read_line();
}

// Prompts the user for an integer and return user's output
int read_integer(string prompt, 
    int from = numeric_limits<int>::min(), 
    int to = numeric_limits<int>::max())
{
    string user_output = read_string(prompt);
    
    while(!is_integer(user_output))
    {
        write_line("Please enter a whole number");
        user_output = read_string(prompt);
    }

    int user_output_int = convert_to_integer(user_output);
    while (!(user_output_int > from and user_output_int < to))
    {
        stringstream ss;
        ss << "Please enter a number from " << from << " to " << to;

        write_line( ss.str());
        user_output_int = convert_to_integer(read_string(prompt));
    }
    return user_output_int;
}
// Calculate scores
int calculate_scores(int goals, int behinds)
{
    return goals * GOAL_POINTS + behinds * BEHIND_POINTS;
}

// Displays the winner and the player scores
void output_details(string team_name, int team_score, int goals, int behinds)
{
    write_line(team_name + ": " + to_string(goals) + ", " + to_string(behinds) + ", " + to_string(team_score));
}

//calculate the winner and return names and scores
string calculate_winner(string team_name_1, string team_name_2, int team_score_1, int team_score_2)
{
    write_line("Calculating details...");
    string winner;

    if(team_score_1 > team_score_2)
    {
        winner = team_name_1;
    
    } else if(team_score_2 > team_score_1)
    {
        winner = team_name_2;
    }
    return winner; 
}

int print_menu(string team_name_1, string team_name_2)
{
    write_line("");
    write_line("1: Update " + team_name_1 + " goals");
    write_line("2: Update " + team_name_1 + " behinds");
    write_line("3: Update " + team_name_2 + " goals");
    write_line("4: Update " + team_name_2 + " behinds");
    write_line("5: Print details:");
    write_line("6: Quit");
    write_line("");
    return read_integer("Option: ");
}

int main()
{
    int user_option;
    write_line("Welcome to the AFL score calculator!");
    write_line("");

    write_line("Enter team 1 details:");
    string team_name_1 = read_string("Name: ");
    int team_1_goals = read_integer("Goals: ");
    int team_1_behinds = read_integer("Behinds: ");
    
    write_line("Enter team 2 details:");
    string team_name_2 = read_string("Name: ");
    int team_2_goals = read_integer("Goals: ");
    int team_2_behinds = read_integer("Behinds: ");

    int team_1_score = calculate_scores(team_1_goals, team_1_behinds);
    int team_2_score = calculate_scores(team_2_goals, team_2_behinds);

    string winner = calculate_winner(team_name_1, team_name_2, team_1_score, team_2_score);

    write_line("");
    write_line("The " + winner + " is winning");
    output_details(team_name_1, team_1_score, team_1_goals, team_1_behinds);
    output_details(team_name_2, team_2_score, team_2_goals, team_2_behinds);
    
    write_line("");
    do
    {
        user_option = print_menu(team_name_1, team_name_2);
        switch (user_option)
        {
        case 1:
            team_1_goals = read_integer("Goals: ");
            break;
        case 2:
            team_1_behinds = read_integer("Behinds: ");
            break;
        case 3:
            team_2_goals = read_integer("Goals: ");
            break;
        case 4:
            team_2_behinds = read_integer("Behinds: ");
            break;
        case 5:
            team_1_score = calculate_scores(team_1_goals, team_1_behinds);
            team_2_score = calculate_scores(team_2_goals, team_2_behinds);
    
            winner = calculate_winner(team_name_1, team_name_2, team_1_score, team_2_score);
        
            write_line("The " + winner + " is winning");
            output_details(team_name_1, team_1_score, team_1_goals, team_1_behinds);
            output_details(team_name_2, team_2_score, team_2_goals, team_2_behinds);
            break;
        default:
            break;
        }

    } while (user_option != 6);
    return 0;
}