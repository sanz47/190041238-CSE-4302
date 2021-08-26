#include<bits/stdc++.h>
using namespace std;
class electronics
{
private:
    string name;
public:
//    virtual void getinfo(){               //// virtual function
//    cout<<"I'm an Electronic item ."<<endl;
//    }
    virtual void getinfo()=0;    ///pure virtual function
};

class television:public electronics
{
private:
    string brand_name;
public:
    void getinfo()
    {
        cout<<"I'm a Television ."<<endl;
    }
};

class fridge:public electronics
{
private:
    string brand_name;
public:
    void getinfo()
    {
        cout<<"I'm a Fridge ."<<endl;
    }
};

class washingMachine:public electronics
{
private:
    string brand_name;
public:
    void getinfo()
    {
        cout<<"I'm a Washing Machine ."<<endl;
    }
};
int main()
{
    electronics* e[4];

    for(int i=0; i<=3; i++)
    {
        e[i]=nullptr;
    }

    e[0]=new fridge;
    e[1]=new television;
    e[2]=new washingMachine;
///e[3]=new electronics; /// Error: because of virtual function . abstract base class .

    e[0]->getinfo();
    e[1]->getinfo();
    e[2]->getinfo();
///e[3]->getinfo();

    for(int i=0; i<=3; i++)
    {
        delete e[i];
    }

}
