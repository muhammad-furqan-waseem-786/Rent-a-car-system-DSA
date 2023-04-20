#include <iostream>
#include <fstream>
#include <windows.h>
#include <stdlib.h>

using namespace std;

void security()
{
    string password;

    ifstream read;
    string read_password = "\0";
    int flag = 0;
    int pinCode = 0 , pin = 1223;

    /*cout << "***********************************************************" << endl;
    cout << "*\t\t\tLogin Page\t\t\t  *" << endl;
    cout << "***********************************************************" << endl;*/

    read.open("password.txt");

    while(!read.eof())
    {
        read >> read_password;
    }

    read.close();

    for(int i = 5 ; i > 0 ; i--)
    {
        cout << "***********************************************************" << endl;
        cout << "*\t\t\tLogin Page\t\t\t  *" << endl;
        cout << "***********************************************************" << endl;

        cout << "You have " << i << " chances left " << endl;
        cout << "Enter the password : ";
        cin >> password;

        if(read_password == password)
        {
            system("cls");

            cout << "system has successfully logged in " << endl;
            return;
        }
        system("cls");
    }

    cout << "system has been locked for 5 seconds" << endl;
    Sleep(5000);

    system("cls");

    for(int i = 5 ; i > 0 ; i--)
    {
        cout << "***********************************************************" << endl;
        cout << "*\t\t\tLogin Page\t\t\t  *" << endl;
        cout << "***********************************************************" << endl;

        cout << "You  have " << i << " chances left " << endl;
        cout << "Enter the pin code : ";
        cin >> pinCode;

        if(pinCode == pin)
        {
            cout << "system is successfully logged in" << endl;
            return;
        }
        system("cls");
    }
    cout << "system has been locked";
    exit(0);
}
