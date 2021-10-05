#include <iostream>
using namespace std;
#include <process.h> //for exit()
const int LIMIT = 100; //array size
////////////////////////////////////////////////////////////////
template<class Type>
class safearay
{
private:
    Type arr[LIMIT];
public:
    class outofBound
    {
    public:
        int indx;
        outofBound(int in):indx(in)
        {
        }
    };
    Type& operator [](int n)   //note: return by reference
    {
        if( n< 0 || n>=LIMIT )
        {
            throw outofBound(n);
        }
        return arr[n];
    }
};

int main()
{
    try
    {
        safearay<int>sa1;
        for(int j=0; j<LIMIT+2; j++) //insert elements
            sa1[j] = j*10; //*left* side of equal sign
        for(int j=0; j<LIMIT; j++) //display elements
        {
            int temp = sa1[j]; //*right* side of equal sign
            cout << "Element " << j << " is " << temp << endl;
        }
    }
    catch(safearay<int>::outofBound x)
    {
        cout<<"Error Occurred at index : "<<x.indx<<endl;
    }
    return 0;
}
