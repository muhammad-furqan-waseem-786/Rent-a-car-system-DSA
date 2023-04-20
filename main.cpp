#include <iostream>
#include <stdlib.h>
#include "test.h"
#include "passwordtest.cpp"

using namespace std;

int main()
{
    linkList listObj;
    car carObj;

    string name = "\0" , phone = "\0" , cnic = "\0" , address = "\0" , Car = "\0" , storeCarName = "\0" ;
    string string_cost = "\0" , string_payment = "\0" , string_duration = "\0";
    int duration = 0 , payment = 0 , index = 0 , storeCost  = 0 , choice = 0 , total = 0 , store = 0 , total_cost = 0;
    int length = 0 , flag = 0 , carNo = 0;

    security();

    listObj.readFile();//read the data from the file and write it in link list

    do
    {
        cout << endl;
        cout << "\t\t\t*************************" << endl;
        cout << "\t\t\t*\t Menu\t        *" << endl;
        cout << "\t\t\t*************************" << endl;
        cout << "\t\t\t* 1. Rent a car         *" << endl;
        cout << "\t\t\t* 2. Return car         *" << endl;
        cout << "\t\t\t* 3. Display the record *" << endl;
        cout << "\t\t\t* 4. Quit               *" << endl;
        cout << "\t\t\t*************************" << endl;
        cout << "\t\t\tEnter your choice : ";
        cin >> choice;

        store = input_validator(choice , 4);

        switch(store)
        {

        case 1:

            system("cls");

            cout << "********************************" << endl;
            cout << "* welcome to rent a car system *" << endl;
            cout << "********************************" << endl;

            cout << "Enter the name : ";
            cin >> name;

            cout << "Enter the phone number : ";
            cin >> phone;

            cout << endl;

            while(phone.length() < 11 || phone.length() > 11)
            {
                cout << endl;
                cout << "invalid input " << endl;
                cout << "Enter again : ";
                cin >> phone;
            }

            cout << "Enter the cnic number : ";
            cin >> cnic;

            cout << endl;

            while(cnic.length() < 15 || cnic.length() > 15)
            {
                cout << "invalid input " << endl;
                cout << "Enter again : ";
                cin >> cnic;
            }

            cout << "Enter the address number : ";
            cin >> address;

            cout << endl << "How many cars/buses you want?" << endl;
            cout << endl  << "Maximum vehicle for rent 5" << endl;
            cout << endl  << "Enter the total number of vehicle : ";
            cin >> total;

            store = input_validator(total , 5);

            for(int i = 1 ; i <= store ; i++)
            {

                cout << endl;

                storeCost = carObj.allCars();

                cout << endl;

                cout << "Enter the car number : ";
                cin >> carNo;

                cout << "Enter the duration : ";
                cin >> duration;

                payment = calculator(storeCost , duration); //integer

                cout << "You have to pay : " << payment;

                total_cost = total_cost + payment;

                storeCarName = returnCar();

                listObj.insertData(name , phone , cnic , address , storeCarName , carNo , duration , payment , storeCost);
                listObj.writeFile(0 , name , phone , cnic , address , storeCarName , carNo , duration , payment , storeCost);
            }

            cout << endl << "Your total cost is : " << total_cost;

            break;

        case 2:

            system("cls");

            cout << "**********" << endl;
            cout << "* Delete *" << endl;
            cout << "**********" << endl;

            length = listObj.returnLength();

            listObj.display();

            cout << endl;

            cout << "Enter the index you want to delete : ";
            cin >> index;

            store = input_validator(index , length);

            if(store == 1)
            {
                listObj.delete_head();
            }
            else if(store == length)
            {
                listObj.delete_end();
            }
            else
            {
                listObj.delete_middle(store);
            }

            listObj.afterDeleteFile();

            remove("ClientData.txt");
            rename("new.txt" , "ClientData.txt");

            break;

        case 3:

            system("cls");

            cout << "***********" << endl;
            cout << "* Display *" << endl;
            cout << "***********" << endl;

            listObj.display();

            break;
        }
    }
    while(choice != 4);


    return 0;
}
