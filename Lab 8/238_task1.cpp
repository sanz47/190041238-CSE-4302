#include<bits/stdc++.h>
using namespace std;
class Seat
{
private:
    string comfortability;
    string presence_of_warmSeat;
public:
    void set_info()
    {
        cout<<"Enter info For Comfortability: ";
        cin>>comfortability;
        cout<<"Enter info For Warm Seat: ";
        cin>>presence_of_warmSeat;
    }
    void get_info()
    {
        cout<<"Comfortability : "<<comfortability<<endl;
        cout<<"Presence of Warm Seat: "<<presence_of_warmSeat<<endl;
    }
};
class Wheel
{
private:
    double radius;
public:
    Wheel():radius(0)
    {
    }
    void set_info()
    {
        cout<<"Enter Radius: ";
        cin>>radius;
    }
    void get_info()
    {
        cout<<"Radius is: "<<radius<<endl;
    }
    ~Wheel(){
    }
};
class Engine
{
private:
    double Maximum_Fuel_Consumption_Rate;
    double Maximum_Energy_Production_Rate;
    double Average_RPM;
public:
    Engine():Maximum_Fuel_Consumption_Rate(0),Maximum_Energy_Production_Rate(0),Average_RPM(0)
    {
    }
    void set_info()
    {
        cout<<"Enter info For Maximum Fuel Consumption Rate: ";
        cin>>Maximum_Fuel_Consumption_Rate;
        cout<<"Enter info For Maximum Energy Production Rate: ";
        cin>>Maximum_Energy_Production_Rate;
        cout<<"Enter info For Average RPM ";
        cin>>Average_RPM;
    }
    void get_info()
    {
        cout<<"Info For Maximum Fuel Consumption Rate: "<<Maximum_Fuel_Consumption_Rate<<endl;
        cout<<"Info For Maximum Energy Production Rate: "<<Maximum_Energy_Production_Rate<<endl;
        cout<<"Info For Average RPM "<<Average_RPM<<endl;
    }
    ~Engine(){
    }
};
class Door
{
private:
    string way;
public:
    void set_info()
    {
        cout<<"Enter Opening Way: ";
        cin>>way;
    }
    void get_info()
    {
        cout<<"Opening Way: "<<way<<endl;
    }
};
class Truck
{
private:
    double maximum_acceleration;
    double fuel_capacity;
    double Load_capacity;
    Seat st[2];
    Wheel whl[6];
    Engine eng;
    Door dr[2];
public:
    Truck():maximum_acceleration(0),fuel_capacity(0),Load_capacity(0)
    {
    }
    void set_info()
    {
        int i;
        for(i=0;i<2;i++){
        cout<<"Enter Information for Seat "<<i+1<<endl;
        st[i].set_info();
        }
        cout<<"Enter Information for Wheel: "<<endl;
        whl[0].set_info();
        eng.set_info();
        for(i=0;i<2;i++){
        cout<<"Enter Information for Door "<<i+1<<endl;
        dr[i].set_info();
        }
        cout<<"Enter Maximum Acceleration: ";
        cin>>maximum_acceleration;
        cout<<"Enter Fuel Capacity: ";
        cin>>fuel_capacity;
        cout<<"Load Capacity: ";
        cin>>Load_capacity;
    }
    void display()
    {
        int i;
        for(i=0;i<2;i++){
        cout<<"Information for Seat "<<i+1<<endl;
        st[i].get_info();
        }
        cout<<"Information for Wheel"<<endl;
        whl[0].get_info();
        eng.get_info();
        for(i=0;i<2;i++){
        cout<<"Information for Door "<<i+1<<endl;
        dr[i].get_info();
        }
        cout<<"Maximum Acceleration: "<<maximum_acceleration<<endl;
        cout<<"Fuel Capacity: "<<fuel_capacity<<endl;
        cout<<"Load Capacity: "<<Load_capacity<<endl;
    }
    ~Truck(){
    }
};
int main()
{
    Truck t;
    cout<<"Enter Truck 1 Information-"<<endl;
    t.set_info();
    cout<<endl;
//    cout<<"Enter Truck 2 Information-"<<endl;
//    t2.set_info();
//    cout<<endl;
    cout<<endl;
    cout<<"Truck 1 Information-"<<endl;
    t.display();
    cout<<endl;
//    cout<<endl;
//    cout<<endl;
//    cout<<"Truck 2 Information-"<<endl;
//    t2.display();
}
