/*
 Project description:
 An employee is paid at a rate of $16.78 per hour for the first 40 hours worked in a week. Any hours over that are paid at the overtime rate of one-and-one-half times that. From the worker’s gross pay, 6% is withheld for Social Security tax, 14% is withheld for federal income tax, 5% is withheld for state income tax, and $10 per week is withheld for union dues. If the worker has three or more dependents, then an additional $35 is withheld to cover the extra cost of health insurance beyond what the employer pays.
 Write a program that will read in the number of hours worked in a week and the number of dependents as input and will then output the worker’s gross pay, each withholding amount, and the net take-home pay for the week.
 For a harder version, write your program so that it allows the calculation to be repeated as often as the user wishes. If this is a class exercise, ask your instructor whether you should do this harder version.
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
    
    //Constants
    const double HOURLY_RATE = 16.78;
    const double OVERTIME_RATE = 1.5 * HOURLY_RATE;
    const double SOCIAL_SECURITY = 0.06;
    const double FEDERAL_INCOME = 0.14;
    const double STATE_INCOME = 0.05;
    const int UNION_DUES = 10;
    const int EXTRA_INSURANCE = 35;
    
    //Repeats the process as many times as the user wants to
    while (true)
    {
        //Getting the user's information
        double hours = askNum("Enter the number of hours worked in a week: ");
        int numDependents = askInt("Enter the number of dependents: ");
        
        
        
        //Calculates the gross pay
        double grossPay;
        if (hours <= 40)
        {
            grossPay = HOURLY_RATE * hours;
        }
        else
        {
            grossPay = (HOURLY_RATE * 40) + (OVERTIME_RATE * (hours-40));
        }
        
        //Calculates the net pay
        double netPay = grossPay * (1 - SOCIAL_SECURITY - FEDERAL_INCOME - STATE_INCOME) - UNION_DUES;
        
        
        
        //Prints out the results
        cout << "\nGross pay: $"<< grossPay <<endl;
        cout << "\tSocial Security tax: -$"<< (SOCIAL_SECURITY * grossPay) <<endl;
        cout << "\tFederal income tax: -$"<< (FEDERAL_INCOME * grossPay) <<endl;
        cout << "\tState income tax: -$"<< (STATE_INCOME * grossPay) <<endl;
        if (numDependents >= 3)
        {
            cout << "\tHealth insurance for dependants: -$"<< EXTRA_INSURANCE <<endl;
            netPay -= EXTRA_INSURANCE;
        }
        
        if (netPay >= 0)
        {
            cout << "Net pay: $"<< netPay <<endl;
        }
        else
        {
            cout << "Net pay: -$"<< (-1 * netPay) <<endl;
        }
        
        
        
        
        
        //Asks if the user wants to repeat the process
        while (true)
        {
            char response;
            cout << "\nWould you like to repeat the process? (y/n) ";
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
