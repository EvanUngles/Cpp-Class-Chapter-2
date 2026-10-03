/*
 Project description:
 Write a program that reads in ten whole numbers and that outputs the sum of all the numbers greater than zero, the sum of all the numbers less than zero (which will be a negative number or zero), and the sum of all the numbers, whether positive, negative, or zero. The user enters the ten numbers just once each and the user can enter them in any order. Your program should not ask the user to enter the positive numbers and the negative numbers separately.
*/

#include <iostream>
#include <string>
using namespace std;



//Asks the given question until the user puts in an integer
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
                return num;
            }
            cout << "Please enter a whole number\n\n";
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
        //Asks for the numbers
        int numbers[10];
        for (int idx = 0; idx < 10; idx++)
        {
            numbers[idx] = askInt("Enter integer #" + to_string(idx + 1) + ": ");
        }
        
        //Adds up the postiive and negative numbers
        int positiveTotal = 0;
        int negativeTotal = 0;
        for (int idx = 0; idx < 10; idx++)
        {
            if (numbers[idx] > 0)
            {
                positiveTotal += numbers[idx];
            }
            else
            {
                negativeTotal += numbers[idx];
            }
        }
        
        
        
        //Prints out the totals
        cout << "\nTotal of the positive numbers: "<< positiveTotal <<endl;
        cout << "Total of the negative numbers: "<< negativeTotal <<endl;
        cout << "Total of all of the numbers: "<< (positiveTotal + negativeTotal) <<endl<<endl;
        
        
        
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
