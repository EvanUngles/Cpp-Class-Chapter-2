/*
 Project description:
 The Harris–Benedict equation estimates the number of calories your body needs to maintain your weight if you do no exercise. This is called your basal metabolic rate, or BMR. The formula for the calories needed for a woman to maintain her weight is BMR = 655 + (4.3 × weight in pounds) + (4.7 × height in inches) – (4.7 × age in years). The formula for the calories needed for a man to maintain his weight is BMR = 66 + (6.3 × weight in pounds) + (12.9 × height in inches) - (6.8 × age in years)
 A typical chocolate bar will contain around 230 calories. Write a program that allows the user to input his or her weight in pounds, height in inches, age in years, and the character M for male and F for female. The program should then output the number of chocolate bars that should be consumed to maintain one’s weight for the appropriate sex of the specified weight, height, and age.
*/

#include <iostream>
#include <string>
using namespace std;



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
        const int CALS_IN_CHOCOLATE_BAR = 230;
        
        //Asks for the user's information
        double weight = askNum("Enter your weight (in pounds): ");
        double height = askNum("Enter your height (in inches): ");
        double age = askNum("Enter your age (in years): ");
        
        //Asks for the user's sex
        char sex;
        while (true)
        {
            cout << "Enter your sex (\"M\" for male or \"F\" for female) ";
            cin >> sex;
            sex = toupper(sex);
            
            //If the user put in several characters, the remaining characters would stay in the backlog and get read the next time cin is used, so this clears the backlog
            cin.ignore(10000, '\n');
            
            if (sex == 'M' || sex == 'F') { break; }
            cout << "\nSorry, this program only has data for male and female, please enter either \"M\" or \"F\"\n";
        }
        
        
        
        //Calculates the basal metabolic rate
        double metabolicRate;
        if (sex == 'M')
        {
            metabolicRate = 66 + (6.3 * weight) + (12.9 * height) - (6.8 * age);
        }
        else
        {
            metabolicRate = 655 + (4.3 * weight) + (4.7 * height) - (4.7 * age);
        }
        
        //Calculates the number of chocolate bars the user could eat without gaining weight
        double numChocolateBars = metabolicRate / CALS_IN_CHOCOLATE_BAR;
        //Rounds the number of chocolate bars to the nearest 0.25
        numChocolateBars = round(numChocolateBars * 4.0) / 4.0;
        
        
        
        //Prints out the results
        cout << "\nYour basal metabolic rate (BMR) is "<< metabolicRate <<" kcal/day\n";
        cout << "This means that you could eat "<< numChocolateBars <<" chocolate bars per day without gaining weight\n";
        
        
        
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
