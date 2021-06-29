#include<iostream>
using namespace std;
class Employee
{
private:
    string name;
    int id;
    int age;
    double salary;
public:
    void getStatus()
    {
        if(age>25)
        {
            if(salary<=210000.0)
            {
                cout<<"Low";
            }
            if(salary<=60000.0)
            {
                cout<<"Moderate";
            }
            else
            {
                cout<<"High";
            }
        }
        else
        {
            if(salary<=20000.0)
            {
                cout<<"Low";
            }
            else
            {
                cout<<"Moderate";
            }
        }
    }
    void FeedInfo()
    {
        cout<<"Enter Employee Name:";
        cin>>name;
        cout<<"Enter ID:";
        cin>>id;
        cout<<"Enter Age:";
        cin>>age;
        cout<<"Enter Salary:";
        cin>>salary;
    }
    void showInfo()
    {
        cout<<name<<endl;
        cout<<id<<endl;
        cout<<age<<endl;
        cout<<salary<<endl;
        getStatus();
        cout<<" Salaried Person"<<endl;
    }
};
int main()
{
    Employee emp;
    emp.FeedInfo();
    emp.showInfo();
}
