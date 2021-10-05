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
    Type& operator [](int n) //note: return by reference
    {
        if( n< 0 || n>=LIMIT )
        {
            cout << "\nIndex out of bounds";
            exit(1);
        }
        return arr[n];
    }
};
////////////////////////////////////////////////////////////////
int main()
{
///safearay<int>sa1;
///safearay<float>sa1;
///safearay<double>sa1;
    safearay<char>sa1;
//for(int j=0; j<LIMIT; j++) //insert elements
//sa1[j] = j*10; //*left* side of equal sign
//for(int j=0; j<LIMIT; j++) //display elements
//{
//int temp = sa1[j]; //*right* side of equal sign
//cout << "Element " << j << " is " << temp << endl;
//}

    for(int j=0; j<LIMIT; j++) //insert elements
        sa1[j] = 'a'+j; //*left* side of equal sign
    for(int j=0; j<LIMIT; j++) //display elements
    {
        char temp = sa1[j]; //*right* side of equal sign
        cout << "Element " << j << " is " << temp << endl;
    }

    return 0;
}
