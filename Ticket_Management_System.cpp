#include<iostream>
#include<fstream>
#include<conio.h>
#include<string.h>
#include<bits/stdc++.h>

using namespace std;


class TourBus{

    int bid;
    char destination[200];
    char time[50];
    int max_seats;
    int booked;

    public:

    TourBus()
    {
    bid = 0;
    max_seats = 50;
    booked = 0;
    strcpy(time, " 9 : 10 AM");
    strcpy(destination, "");
    }

    void input();
    void show();
    void display();


    int getid()
    {
        return bid;
    }
    char* getDestination()
    {
        return destination;
    }
    char* getTime()
    {
        return time;
    }
    int getBooked()
    {
        return booked;
    }
    int getMax()
    {
        return max_seats;
    }


};

class Ticket
{
    char name[50];
    TourBus bus;

    public:

    void generate(char cname[], TourBus tb)
    {
        strcpy(name, cname);
        bus = tb;
    }
    void display(){

        cout<<"Customer Name"<<name<<endl;
        cout<<"Details of Bus"<<endl;
        bus.show();
    }
};

void TourBus :: input()
{
    cout<<"Enter Bus id : ";
    cin >> bid;
    cout<<"Enter Bus destination : ";
    cin >> destination;
    cout<<"Enter time of bus : ";
    cin >> time;
}

void TourBus :: display()
{
    cout<<bid<<"\t"<<destination<<"\t"<<time<<"\t"<<max_seats<<"\t"<<booked;

}

void TourBus :: show()
{

}

void main(){

    int ch;
    fstream F, G;
    TourBus b;

    do
    {
        cout<<"Press 1 - Add a new tour bus "<<endl;
        cout<<"Press 2 - Show Selected Bus "<<endl;
        cout<<"Press 3 - Display all Buses "<<endl;
        cout<<"Press 4 - Delete a Bus "<<endl;
        cout<<"Press 5 - Book a ticket "<<endl;
        cout<<"Press 6 - Exit "<<endl;
        cout<<"Enter your voice";
        cin >> ch;
        switch(ch)
        {
            case 1:
            F.open("tour.dat", ios :: app | ios :: binary);
            b.input();
            F.write((char*)&b, sizeof(b));
            F.close();
            cout<<"This data was added successfully"<<endl;
            getch();
            break;

            case 3:

            F.open("tour.dat", ios :: app | ios :: binary);

            if(F.fail())
                cout<<"Can't open file";

            else{
                while(F.read((char*)&b, sizeof(b)))
                    b.dispay();
            }
            F.close();
            cout<<"Press a key to continue";
            getch();
            break;
        }   
    }
   
}