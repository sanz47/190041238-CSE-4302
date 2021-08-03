#include<iostream>
#include<math.h>
using namespace std;
class Coordinate
{
private:
    float abscissa,ordinate;
public:
    Coordinate(float x,float y):abscissa(x),ordinate(y)
    {
    }
    Coordinate():abscissa(0.0),ordinate(0.0)
    {
    }
    float getDistance(Coordinate c)
    {
        return (sqrt(((abscissa-c.abscissa)*(abscissa-c.abscissa))+((ordinate-c.ordinate)*(ordinate-c.ordinate))));
    }
    float getDistance()
    {
        return (sqrt((abscissa*abscissa)+(ordinate*ordinate)));
    }
    float distance(Coordinate X,Coordinate Y)
    {
        return (sqrt(((X.abscissa-Y.abscissa)*(X.abscissa-Y.abscissa))+((X.ordinate-Y.ordinate)*(X.ordinate-Y.ordinate))));
    }
    void move_x(float val)
    {
        abscissa=abscissa+val;
    }
    void move_y(float val)
    {
        ordinate=ordinate+val;
    }
    void move(float val)
    {
        move_x(val);
        move_y(val);
    }
    bool operator >(Coordinate c)
    {
        Coordinate c1(abscissa,ordinate);
        Coordinate origin(0,0);
        return distance(c1,origin)>distance(c,origin);
    }
    bool operator <(Coordinate c)
    {
        Coordinate c1(abscissa,ordinate);
        Coordinate origin(0,0);
        return distance(c1,origin)<distance(c,origin);
    }
    bool operator >=(Coordinate c)
    {
        Coordinate c1(abscissa,ordinate);
        Coordinate origin(0,0);
        return distance(c1,origin)>=distance(c,origin);
    }
    bool operator <=(Coordinate c)
    {
        Coordinate c1(abscissa,ordinate);
        Coordinate origin(0,0);
        return distance(c1,origin)<=distance(c,origin);
    }
    bool operator ==(Coordinate c)
    {
        Coordinate c1(abscissa,ordinate);
        Coordinate origin(0,0);
        return distance(c1,origin)==distance(c,origin);
    }
   bool operator !=(Coordinate c){
//        Coordinate c1(abscissa,ordinate);
//        Coordinate origin(0,0);
//        return distance(c1,origin)!=distance(c,origin);
        return getDistance()!=c.getDistance();
   }
    Coordinate operator++()
    {
        return Coordinate((++abscissa),(++ordinate));
    }
    Coordinate operator++(int)
    {
        return Coordinate((abscissa++),(ordinate++));
    }
    Coordinate operator--()
    {
        return Coordinate((--abscissa),(--ordinate));
    }
    Coordinate operator--(int)
    {
        return Coordinate((abscissa--),(ordinate--));
    }
    void getResult()
    {
        cout<<"Abscissa: "<<abscissa<<endl;
        cout<<"Ordinate: "<<ordinate<<endl;
    }
    ~Coordinate()
    {
    }
};
int main()
{
    Coordinate a1(1.11,2.22),b1(3.33,4.44);
    a1.getResult();
    a1++;
    cout<<"Distance from b1 for a1 "<<a1.getDistance(b1)<<endl;
    b1.move_x(1.23);
    cout<<"Distance from origin "<<b1.getDistance()<<endl;
    --b1;
    b1.getResult();
    ++a1;
    ++b1;
    b1.getResult();
    a1.getResult();
    a1.move_y(2.34);
    cout<<"Distance from a1 for b1 "<<b1.getDistance(a1)<<endl;
    cout<<"a1>=b1: "<<(a1>=b1)<<endl;
    cout<<"b1>a1: "<<(b1>a1)<<endl;
    cout<<"a1!=b1: "<<(a1!=b1)<<endl;
    cout<<"b1<a1: "<<(b1<a1)<<endl;
    cout<<"a1<=b1: "<<(a1<=b1)<<endl;
}
