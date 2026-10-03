//This project was not assigned, but I misread the list of assignments and thought this one was on there
/*
 Project description:
 Sound travels through air as a result of collisions between the molecules in the air. The temperature of the air affects the speed of the molecules, which in turn affects the speed of sound. The speed of sound in dry air can be approximated by the formula: speed ≈ 331.3 + 0.61 × T_c, where T_c is the temperature of the air in degrees Celsius and the speed is in meters/second.
 Write a program that allows the user to input a starting and an ending temperature. Within this temperature range, the program should output the temperature and the corresponding speed in 1° increments.
 For example, if the user entered 0 as the start temperature and 2 as the end temperature, then the program should output:
         At 0 degrees Celsius the speed of sound is 331.3 m/s
         At 1 degrees Celsius the speed of sound is 331.9 m/s
         At 2 degrees Celsius the speed of sound is 332.5 m/s
*/

#include <iostream>
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
            if (num == (int)num)
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



int main()
{
    //Adjusts the settings for printing decimals so it will only show 1 decimal place
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);
    
    //Allows the user to repeat the calculation
    while (true)
    {
        //Ask for the information
        int startingTemp = askInt("Enter the starting temperature: ");
        int endingTemp = askInt("Enter the ending temperature: ");
        
        
        
        cout << endl;
        
        //Calculates and prints the results
        for (int temp = startingTemp; temp <= endingTemp; temp++)
        {
            double speedOfSound = 331.3 + 0.61*temp;
            cout << "At "<< temp <<" degrees Celsius the speed of sound is "<< speedOfSound <<" m/s\n";
        }
        
        cout << endl;
        
        
        
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
