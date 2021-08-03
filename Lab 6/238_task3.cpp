#include<iostream>
using namespace std;
class FLOAT
{
private:
    float data;
public:
    FLOAT(float f):data(f)
    {
    }
    FLOAT():data(0.0)
    {
    }
    FLOAT operator +(FLOAT ft)
    {
        return FLOAT(data+ft.data);
    }
    FLOAT operator -(FLOAT ft)
    {
        return FLOAT(data-ft.data);
    }
    FLOAT operator *(FLOAT ft)
    {
        return FLOAT(data*ft.data);
    }
    FLOAT operator /(FLOAT ft)
    {
        return FLOAT(data/ft.data);
    }
    float getData()
    {
        return data;
    }
    ~FLOAT()
    {
    }
};
int main()
{
    FLOAT f1,f2,f3,f4;
    f1=2.5;
    f2=3.1;
    cout<<"F1 = "<<f1.getData()<<endl;
    cout<<"F2 = "<<f2.getData()<<endl;
    f3=f1+f2;
    cout<<"F1+F2 = "<<f3.getData()<<endl;
    f4=f1-f2;
    cout<<"F1-F2 = "<<f4.getData()<<endl;
    f4=f2*f1;
    cout<<"F1*F2 = "<<f4.getData()<<endl;
    f3=f1/f2;
    cout<<"F1/F2 = "<<f3.getData()<<endl;
    int i = f1;
}
