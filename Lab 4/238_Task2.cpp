#include<iostream>
#include<cmath>
using namespace std;
class Rectangle
{
private:
    double length,width;
public:
    Rectangle(double len=1.0,double wid=1.0)
    {
        length=len;
        width=wid;
    }

    double perimeter()
    {
        return 2*(length+width);
    }


    double area()
    {
        return (length*width);
    }
    double diagonal()
    {
        return sqrt((length*length)+(width*width));
    }
    double angle()
    {
        return acos(length/diagonal());
    }
    void setVal()
    {
        cout<<"Enter Length:";
        cin>>length;
        cout<<endl;
        cout<<"Enter Width:";
        cin>>width;
        cout<<endl;
        if(length>=1.0 && length<20.0 && width>=1 && width<20.0)
        {
            cout<<"Valid Input"<<endl;
        }
        else
        {
            cout<<"Invalid Input"<<endl;
            exit(0);
        }
    }
    void getVal()
    {
        cout<<"Length:"<<length<<endl;
        cout<<"Width:"<<width<<endl;
        cout<<area()<<endl;
        cout<<perimeter()<<endl;
        cout<<angle()<<endl;
        cout<<diagonal()<<endl;
    }


};

int main()
{
    Rectangle r1;
    r1.setVal();
    r1.getVal();
    return 0;
}
