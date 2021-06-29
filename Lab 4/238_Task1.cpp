#include<iostream>
#include<string>
using namespace std;
class BankAccount
{
private:
    int acc_number;
    string name;
    string type;
    double curr_balance;
    double min_balance;
public:
    BankAccount()
    {
    }
    BankAccount(int a_n,string n,string t,double m_b):acc_number(a_n),name(n),type(t),curr_balance(m_b),min_balance(m_b)
    {

    }
    void input()
    {
        string s;
        cout<<"Enter Account Number:";
        cin>>acc_number;
        cout<<endl;
        cout<<"Enter Name:";
        cin>>name;
        cout<<endl;
        cout<<"Enter Account Type:";
        cin>>type;
        cout<<endl;
        cout<<"Enter Minimum Balance:";
        cin>>min_balance;
        curr_balance=min_balance;
        cout<<endl;
    }
    void display()
    {
        cout<<"Account Number:"<<acc_number<<endl;
        cout<<"Account Holder:"<<name<<endl;
        cout<<"Account Type:"<<type<<endl;
        cout<<"Current Balance:"<<curr_balance<<endl;
    }
    double showBalance()
    {
        return curr_balance;
    }
    void deposit(double add)
    {
        curr_balance+=add;
    }
    void withdrawal(double del)
    {
        if(curr_balance-del<min_balance)
        {
            cout<<"ERROR"<<endl;
        }
        else
        {
            curr_balance-=del;
        }
    }
    void giveInterest()
    {
        double inter=curr_balance*(0.03);
        inter-=inter*0.1;
        deposit(inter);
    }
    ~BankAccount()
    {
        cout<<"Account of "<<name<<" with account no "<<acc_number<<" is destroyed with a balance BDT "<<curr_balance<<endl;
    }
};

int main()
{
    BankAccount person1;
    person1.input();
    person1.display();
    person1.deposit(777);
    person1.withdrawal(500);
    cout<<"Current Balance:"<<person1.showBalance()<<endl;
    person1.withdrawal(500);
    person1.giveInterest();
    cout<<"Current Balance:"<<person1.showBalance()<<endl;
}
