#include<bits/stdc++.h>
using namespace std;
class math{
private:
    int data;
  ///  math(math&);  /////// making it private restricts it from accessing
  ///  math& operator = (math&);

public:
    math(){
    }
    math(int a):data(a){
    }
    math(math& m){
    data=m.data;
    cout<<"Copy Constructor Called"<<endl;
    }
    void display(){
    cout<<data<<endl;
    }
    void operator = (math& m){
    data=m.data;
    cout<<"Assignment Operator Called"<<endl;
    }
};
int main(){
math r;

math m1(38);
math m2(r);
m2=m1;

cout<<"Value of M2 : ";
m2.display();
cout<<endl;

math m3(m1);
cout<<"Value of M3 : ";
m3.display();
cout<<endl;

math m4=m1;
cout<<"Value of M4 : ";
m4.display();
cout<<endl;
}
