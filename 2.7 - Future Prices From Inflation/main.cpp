/*
 Project description:
 It is difficult to make a budget that spans several years, because prices are not stable. If your company needs 200 pencils per year, you cannot simply use this year’s price as the cost of pencils 2 years from now. Because of inflation the cost is likely to be higher than it is today.
 Write a program to gauge the expected cost of an item in a specified number of years. The program asks for the cost of the item, the number of years from now that the item will be purchased, and the rate of inflation. The program then outputs the estimated cost of the item after the specified period. Have the user enter the inflation rate as a percentage, like 5.6 (percent). Your program should then convert the percent to a fraction, like 0.056, and should use a loop to estimate the price adjusted for inflation.
         (Hint: This is similar to computing interest on a charge card account, which was discussed in this chapter.)
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
    //Adjusts the settings for printing decimals so it will always show 2 decimal places
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    while (true)
    {
        //Asks for the information
        double cost = askNum("Enter the current cost of the item: $");
        int numYears = askInt("Enter the number of years from now that the item will be purchased: ");
        double inflationRate = askNum("Enter the rate of inflation as a percentage (do not add the \"%\" at the end): ");
        
        
        
        //Calculates the future cost
        for (int year = 1; year <= numYears; year++)
        {
            cost *= 1 + (inflationRate/100.0);
        }
        
        //Prints out the result
        cout << "\nIn "<< numYears <<" years, the item will cost $"<< cost <<endl;
        
        
        
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
