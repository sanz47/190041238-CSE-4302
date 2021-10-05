#include<bits/stdc++.h>
using namespace std;
template<class Type>
Type amax(Type* arr,int n)
{
    Type a=0;
    for(int i=0; i<n; i++)
    {
        if(arr[i]>a)
        {
            a=arr[i];
        }
    }
    return a;
}

int main()
{
//int arr[10]={1,2,7,2,56,89,45,12,45,67};
//float arr[10]={1.2,2.4,7.6,2.1,56.6,8.9,45.5,12.6,4.5,6.7};
    double arr[10]= {1.0,2.7,7.9,2.4,5.6,8.9,4.5,1.2,4.5,6.7};
    cout<<amax(arr,10);
}
