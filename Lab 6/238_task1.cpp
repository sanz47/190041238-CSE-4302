#include<iostream>
using namespace std;
class Counter
{
private:
    int data;
    int step;
public:
    Counter():data(0),step(0)
    {
    }
    Counter(int dt,int st):data(dt),step(st)
    {
    }
    void setIncrementStep(int step_val)
    {
        if(step_val<0)
        {
            cout<<"Invalid increment"<<endl;
        }
        else
        {
            step=step_val;
        }
    }
    int getCount()
    {
        return data;
    }
    void increment()
    {
        data=data+step;
    }
    void resetCount()
    {
        data=0;
    }
    Counter operator +(Counter cnt)
    {
        int d=data+cnt.data;
        int s=min(step,cnt.step);
        return Counter(d,s);
    }
    Counter operator +(int var)
    {
        return Counter((data+var),step);
    }
    void operator +=(Counter cnt)
    {
        data=data+cnt.data;
    }
    Counter operator++()
    {
        data=data+step;
        return Counter(data,step);
    }
    Counter operator++(int)
    {
        int x;
        x=data;
        data=data+step;
        return Counter(x,step);
    }
    Counter operator +(int var,Counter rop)
    {
        return Counter((var+rop.data),rop.step);
    }
    ~Counter()
    {
    }
};
//Counter operator +(int var,Counter rop)
//{
//
//}
int main()
{
    Counter c1(1,2),c2(2,4),c3,c4;
    cout<<"count of C4: "<<c4.getCount()<<endl;
    c4.setIncrementStep(4);
    c4.increment();
    c4+=c2;
    cout<<"C4: "<<c4.getCount()<<endl;
    c2++;
    c3=c1+c2;
    cout<<"C1+C2= "<<c3.getCount()<<endl;
    c4=c1+7;
    c4=2+c2;
    cout<<"C4=C1+7= "<<c4.getCount()<<endl;
    c2=++c4;
    cout<<"C2:++C4  "<<c2.getCount()<<endl;
    c2=c4++;
    cout<<"C2:++C4  "<<c2.getCount()<<endl;
    cout<<"C4= "<<c4.getCount()<<endl;
}
