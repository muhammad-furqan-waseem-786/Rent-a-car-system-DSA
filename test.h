#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

//**********************************************
//Global Variables and functions
//**********************************************

string caar_name = "\0";

void getCar(string& car_name); //take the car name
string& returnCar(); //return the car name
int calculator(int cost ,int time); //calculate the cost per hour
int input_validator(int input , int limit);//checks the input from the user

class linkList
{
private:

    int cost , duration , car_No, cost_per;
    string caar , name , phone , cnic , address;
    linkList *next , *head;
    ifstream read;
    ofstream write;
    int length ;

    void insert_head(string name , string phone , string cnic , string address , string Car , int car_no , int duration , int payment , int cost_hour);//insert data at head
    void insert_end(string name , string phone , string cnic , string address , string Car , int car_no , int duration , int payment , int cost_hour);//insert data at end

public:

    linkList();
    void insertData(string name , string phone , string cnic , string address , string Car , int car_no , int duration , int payment , int cost_hour); //insert the data in the link list
    void writeFile(int flag , string name , string phone , string cnic , string address , string Car , int car_no , int duration , int payment , int cost_hour);//write the data in the file
    void display(); //display the record
    void readFile(); //read the data from the file
    void afterDeleteFile(); //call after the deletion of the data from the link list
    int returnLength();//calculate the length of the link list
    void delete_head();//delete the head
    void delete_middle(int index);//delete the data from the given index
    void delete_end();//delete the last data
};

class car
{
public:

    int choice = 0 , time = 0 , cost = 0 , store = 0;
    string Car;

    int suv();
    int cuv();
    int sedan();
    int hatchBack();
    int buses();

public:

    car();
    int allCars();
};

linkList::linkList()
{
    head = NULL;
    next = NULL;
    length = 0;
    cost = 0;
    duration = 0;
    car_No = 0;
    cost_per = 0;
    caar = "\0";
    name = "\0";
    phone = "\0";
    cnic = "\0";
    address = "\0";
}

car::car()
{
    choice = 0;
    time = 0;
    cost = 0;
    store = 0;
    Car = "\0";
}

void linkList::insert_head(string name , string phone , string cnic , string address , string Car , int car_no , int duration , int payment , int cost_hour)
{
    linkList *new_linkList = new linkList();

    new_linkList -> name = name;
    new_linkList -> phone = phone;
    new_linkList -> cnic = cnic;
    new_linkList -> address = address;
    new_linkList -> caar = Car;
    new_linkList -> car_No = car_no;
    new_linkList -> duration = duration;
    new_linkList -> cost = payment;
    new_linkList -> cost_per = cost_hour;

    new_linkList -> next = head;
    head = new_linkList;

    length++;
}
void linkList::insert_end(string name , string phone , string cnic , string address , string Car , int car_no , int duration , int payment , int cost_hour)
{
    linkList *iteration = new linkList();
    linkList *new_linkList = new linkList();

    iteration = head;

    while(iteration -> next != NULL)
    {
        iteration = iteration -> next;
    }

    new_linkList -> name = name;
    new_linkList -> phone = phone;
    new_linkList -> cnic = cnic;
    new_linkList -> address = address;
    new_linkList -> caar = Car;
    new_linkList -> car_No = car_no;
    new_linkList -> duration = duration;
    new_linkList -> cost = payment;
    new_linkList -> cost_per = cost_hour;

    iteration -> next = new_linkList ;
    new_linkList -> next = NULL;

    length++;
}

void linkList::insertData(string name , string phone , string cnic , string address , string Car , int car_no , int duration , int payment , int cost_hour)
{
    linkList *new_linkList = new linkList();
    linkList *iteration = new linkList();

    iteration = head;

    if(iteration == NULL)
    {
        insert_head(name , phone , cnic , address , Car , car_no , duration , payment , cost_hour);
    }
    else
    {
        insert_end(name , phone , cnic , address , Car , car_no , duration , payment , cost_hour);
    }
}

void linkList::display()
{
    linkList *iteration = new linkList();
    iteration = head;
    int i = 1;

    if(iteration == NULL)
    {
        cout << "list is empty \n";
        return;
    }

    cout << "-------------------------------------------------------------------------------------------------------------------------------------------\n";
    cout << "\t Name\t\t Phone number \t  Cnic \t\tCar \t   Car Number     Duration     Payment \tAddress" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------------------------------\n";

    while(iteration != NULL)
    {
        cout << "[" << i << "] | ";
        cout << setw(10) << iteration -> name;
        cout << setw(15) <<  iteration -> phone;
        cout << setw(1) << "  " << iteration -> cnic;
        cout << setw(3) << "" << iteration -> caar;
        cout << setw(8) <<  iteration -> car_No;
        cout << setw(13) <<  iteration -> duration;
        cout << setw(11) << iteration -> cost;
        cout << setw(3) << " " << iteration -> address;
        cout << endl;

        iteration = iteration -> next;
        i++;
    }
}
void linkList::delete_head()
{
    int time_period = 0;
    int time = 0;
    int intCost = 0;

    linkList *iteration = new linkList();

    iteration = head;
    head = iteration -> next;

    cout << "enter the duration : ";
    cin >> time_period;

    time = iteration -> duration;
    intCost = iteration ->cost_per;

    cout << "++++++++++++++++++++++++++++" << endl;
    cout << iteration -> name << endl;
    cout << iteration -> car_No << endl;
    cout << "++++++++++++++++++++++++++++" << endl;

    if(time < time_period)
    {
        cout << "You have to pay : " << calculator(intCost , time_period);
    }

    delete iteration;

    length--;
}

void linkList::delete_middle(int index)
{
    int time_period = 0;
    int time = 0;
    int store = 0;
    int intCost = 0;

    linkList *iteration = new linkList();
    linkList *deleteNode = new linkList();

    iteration = head;
    deleteNode = head;

    for(int i = 1 ; i < index ; i++)
    {
        iteration = iteration -> next;
    }
    for(int i = 1 ; i < index -1 ; i++)
    {
        deleteNode = deleteNode -> next;
    }

    cout << "enter the duration : ";
    cin >> time_period;

    time = iteration -> duration;
    intCost = iteration ->cost_per;

    cout << "++++++++++++++++++++++++++++" << endl;
    cout << iteration -> name << endl;
    cout << iteration -> car_No << endl;
    cout << "++++++++++++++++++++++++++++" << endl;

    if(time < time_period)
    {
        cout << "You have to pay : " << calculator(intCost , time_period);
    }

    deleteNode -> next = iteration -> next;

    delete iteration;

    length--;
}

void linkList::delete_end()
{
    int time_period = 0;
    int time = 0;
    int store = 0;
    int intCost = 0;

    linkList *iteration = new linkList();
    linkList *deleteNode = new linkList();

    iteration = head;

    while(iteration -> next -> next != NULL)
    {
        iteration = iteration -> next;
    }

    cout << "enter the duration : ";
    cin >> time_period;

    time = iteration -> duration;
    intCost = iteration ->cost_per;

    cout << "++++++++++++++++++++++++++++" << endl;
    cout << iteration -> next -> name << endl;
    cout << iteration -> next ->  car_No << endl;
    cout << "++++++++++++++++++++++++++++" << endl;

    if(time < time_period)
    {
        cout << "You have to pay : " << calculator(intCost , time_period);
    }

    deleteNode = iteration -> next;
    iteration -> next = NULL;

    delete deleteNode;

    length--;
}

void linkList::readFile()
{
    string readName = "\0" , readPhone = "\0"  , readCnic = "\0"  , readAddress = "\0"  , readCar = "\0"  , counter = "\0"  ;
    int readCarNo = 0  , readDuration = 0  , readPayment = 0 , cost_hour = 0 ;

    int i = 0;

    read.open("ClientData.txt");

    while(getline(read , counter))
    {
        i++;
    }

    read.close();

    read.open("ClientData.txt");

    for(int j = 0 ; j < i / 9 ; j++)
    {
        read >> readName;
        read >> readPhone;
        read >> readCnic;
        read >> readAddress;
        read >> readCar;
        read >> readCarNo;
        read >> readDuration;
        read >> readPayment;
        read >> cost_hour;

        insertData(readName , readPhone , readCnic , readAddress , readCar , readCarNo , readDuration , readPayment , cost_hour);
    }

    read.close();
}

void linkList::writeFile(int flag , string name , string phone , string cnic , string address , string Car , int car_no , int duration , int payment , int cost_hour)
{
    if(flag == 0)
    {
        write.open("ClientData.txt" , ios::app);

        write << endl;
        write << name << endl;
        write << phone << endl;
        write << cnic << endl;
        write << address << endl;
        write << Car << endl;
        write << car_no << endl;
        write << duration << endl;
        write << payment << endl;
        write << cost_hour << endl;

        write.close();
    }
    else
    {
        write.open("new.txt" , ios::app);

        cout << endl << name << endl;
        cout << phone << endl;
        cout << cnic << endl;
        cout << address << endl;
        cout << Car << endl;
        cout << car_no << endl;
        cout << duration << endl;
        cout << payment << endl;
        cout << cost_hour << endl;

        write << name << endl;
        write << phone << endl;
        write << cnic << endl;
        write << address << endl;
        write << Car << endl;
        write << car_no << endl;
        write << duration << endl;
        write << payment << endl;
        write << cost_hour << endl;

        write.close();
    }
}

int car::suv()
{
    cout << endl;
    cout << "1. Range Rover (30,000)" << endl;
    cout << "2. Prado (28,000)" << endl;
    cout << "3. Black Vigo (25,000)" << endl;
    cout << "4. Fortuner (23,000)" << endl;
    cout << "Enter your choice : ";
    cin >> choice;

    store = input_validator(choice , 4);

    switch(store)
    {
        case 1:

            cost = 30000;
            Car = "Range-Rover";

        break;

        case 2:

            cost = 28000;
            Car = "Prado";

        break;

        case 3:

            cost = 25000;
            Car = "Black-Vigo";

        break;

        case 4:

            cost = 23000;
            Car = "Fortuner";

        break;
    }

    getCar(Car);
    return cost;
}

int car::cuv()
{
    cout << endl;
    cout << "1. Honda HRV (20,000)" << endl;
    cout << "2. Suzuki Vitara (17,000)" << endl;
    cout << "3. Hyundai Tucson (16,500)" << endl;
    cout << "4. Kia Sportage (16,000)" << endl;
    cout << "5. Nissan Juke (13,000)" << endl;
    cout << "Enter your choice : ";
    cin >> choice;

    store = input_validator(choice , 5);

    switch(store)
    {
        case 1:

            cost = 20000;
            Car = "Honda-HRV";

        break;

        case 2:

            cost = 17000;
            Car = "Suzuki-Vitara";

        break;

        case 3:

            cost = 16500;
            Car = "Hyundai-Tucson";

        break;

        case 4:

            cost = 16000;
            Car = "Kia-Sportage";

        break;

        case 5:

            cost = 13000;
            Car = "Nissan-Juke";

        break;
    }

    getCar(Car);
    return cost;
}

int car::sedan()
{
    cout << endl;
    cout << "1. Honda Civic (11,000)" << endl;
    cout << "2. Toyota Corolla Altis Grande (10,000)" << endl;
    cout << "3. Honda City (9,500)" << endl;
    cout << "4. Toyota Yaris (9,000)" << endl;
    cout << "5. Suzuki Ciaz (8,000)" << endl;
    cout << "Enter your choice : ";
    cin >> choice;

    store = input_validator(choice , 5);

    switch(store)
    {
        case 1:

            cost = 11000;
            Car = "Honda-Civic";

        break;

        case 2:

            cost = 10000;
            Car = "Toyota-Grande";

        break;

        case 3:

            cost = 9500;
            Car = "Honda-City";

        break;

        case 4:

            cost = 9000;
            Car = "Toyota-Yaris";

        break;

        case 5:

            cost = 8000;
            Car = "Suzuki-Ciaz";

        break;
    }

    getCar(Car);
    return cost;
}

int car::hatchBack()
{
    cout << endl;
    cout << "1. Swift (7,500)" << endl;
    cout << "2. WaganR (7,000)" << endl;
    cout << "3. Vitz (6,500)" << endl;
    cout << "4. Cultus (6,000)" << endl;
    cout << "Enter your choice : ";
    cin >> choice;

    store = input_validator(choice , 4);

    switch(store)
    {
        case 1:

            cost = 7500;
            Car = "Suzuki-Swift";

        break;

        case 2:

            cost = 7000;
            Car = "Suzuki-WaganR";

        break;

        case 3:

            cost = 6500;
            Car = "Toyota-Vitz";

        break;

        case 4:

            cost = 6000;
            Car = "Suzuki-Cultus";

        break;
    }

    getCar(Car);
    return cost;
}

int car::buses()
{
    cout << "1. Coaster (14,500)" << endl;
    cout << "2. High-roof (12,000)" << endl;
    cout << "Enter your choice : ";
    cin >> choice;

    store = input_validator(choice , 2);

    switch(store)
    {
        case 1:

            cost = 14500;
            Car = "Coaster";

        break;

        case 2:

            cost = 12000;
            Car = "High-roof";

        break;
    }

    getCar(Car);
    return cost;
}
int car::allCars()
{
    int choice = 0 , store = 0 , time = 0;

    cout << endl;
    cout << "1. For SUV's" << endl;
    cout << "2. For CUV's" << endl;
    cout << "3. For Sedans" << endl;
    cout << "4. For Hatch Backs" << endl;
    cout << "5. For Buses" << endl;
    cout << "Enter your choice : ";
    cin >> choice;

    store = input_validator(choice , 5);

    switch(store)
    {
        case 1:

        store = suv();

        break;

        case 2:

        store = cuv();

        break;

        case 3:

        store = sedan();

        break;

        case 4:

        store = hatchBack();

        break;

        case 5:

        store = buses();

        break;
    }

    return store;
}

void getCar(string& car_name)
{
    caar_name = car_name;
}

string& returnCar()
{
    return caar_name;
}

int calculator(int cost , int time) //calculate the cost of the car for the required days
{
    int divide = 0;

    divide = cost / 24;
    time = time * divide;

    return time;
}

int input_validator(int input , int limit)//Checks the input from the user
{
    while(input <= 0 || input > limit)
    {
        cout << endl;
        cout << "Invalid input" << endl;
        cout << "Enter your choice : ";
        cin >> input;
    }

    return input;
}

int linkList::returnLength()//calculate the length of the link list
{
    return length;
}

void linkList::afterDeleteFile()//call after the deletion of the data from the link list
{
    linkList *iteration = new linkList();

    iteration = head; //start the iteration from the head which is equal to NULL

    while(iteration != NULL)//iterate until the NULL is not approached
    {
        writeFile(1 , iteration -> name , iteration -> phone , iteration -> cnic , iteration -> address , iteration -> caar , iteration -> car_No , iteration -> duration , iteration -> cost , iteration -> cost_per);

        iteration = iteration -> next; //move to the next node
    }
}
