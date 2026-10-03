/*
 Project description:
 Write a program that calculates the total grade for N classroom exercises as a percentage. The user should input the value for N followed by each of the N scores and totals. Calculate the overall percentage (sum of the total points earned divided by the total points possible) and output it as a percentage. Sample input and output is shown below.
 How many exercises to input? 3
 
 Score received for exercise 1: 10
 Total points possible for exercise 1: 10
 
 Score received for exercise 2: 7
 Total points possible for exercise 2: 12
 
 Score received for exercise 3: 5
 Total points possible for exercise 3: 8
 
 Your total is 22 out of 30, or 73.33%.
*/

#include <iostream>
#include <string>
using namespace std;



//Asks the given question until the user puts in a positive integer
int askInt(string question)
{
    string response;
    while (true)
    {
        try
        {
            cout << question;
            cin >> response;
            
            //Tries to convert the response to a number and store it in num
            double num = stod(response);
            
            //Checks if the user put in a whole number
            if (num == static_cast<int>(num))
            {
                //Returns the number if it's positive or 0
                if (num >= 0)
                {
                    return num;
                }
                cout << "Please enter a positive number\n\n";
            }
            else
            {
                cout << "Please enter a whole number\n\n";
            }
        }
        catch (invalid_argument) //If the user didn't put in a number
        {
            cout << "Please enter a number\n\n";
        }
    }
}



//Asks the given question until the user puts in a positive number (can have a decimal)
double askNum(string question)
{
    string response;
    while (true)
    {
        try
        {
            cout << question;
            cin >> response;
            
            //Tries to convert the response to a number and store it in num
            double num = stod(response);
            
            //Returns the number if it's positive or 0
            if (num >= 0)
            {
                return num;
            }
            cout << "Please enter a positive number\n\n";
        }
        catch (invalid_argument) //If the user didn't put in a number
        {
            cout << "Please enter a number\n\n";
        }
    }
}



int main()
{
    while (true)
    {
        int numExercises = askInt("How many exercises to input? ");
        
        //Asks for the number of points earned and the number of points possible for every exercise
        double totalPointsEarned = 0.0;
        double totalPointsPossible = 0.0;
        for (int exercise = 1; exercise <= numExercises; exercise++)
        {
            cout << endl;
            
            double pointsEarned = askNum("Score received for exercise " + to_string(exercise) + ": ");
            double pointsPossible = askNum("Total points possible for exercise " + to_string(exercise) + ": ");
            
            //Adds them to the totals
            totalPointsEarned += pointsEarned;
            totalPointsPossible += pointsPossible;
        }
        
        //Calculates the overall grade
        double overallGrade = (totalPointsEarned / totalPointsPossible) * 100.0;
        //Rounds the overall grade to 2 decimal places
        overallGrade = round(overallGrade * 100.0) / 100.0;
        
        //Prints out the grade
        cout << "\nYour total is "<< totalPointsEarned <<" out of "<< totalPointsPossible <<", or "<< overallGrade <<"%\n";
        
        
        
        //Asks if the user wants to repeat the calculation
        while (true)
        {
            char response;
            cout << "\nWould you like to run the calculation again? (y/n) ";
            cin >> response;
            
            //If the user put in several characters, the remaining characters would stay in the backlog and get read the next time cin is used, so this clears the backlog
            cin.ignore(10000, '\n');
            
            if (tolower(response) == 'y')
            {
                cout << endl;
                break;
            }
            else if (tolower(response) == 'n')
            {
                return 0;
            }
            cout << "Sorry, I didn't understand that, please enter either \"y\" (for yes) or \"n\" (for no)";
        }
    }
}
