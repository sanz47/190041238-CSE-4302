#include<bits/stdc++.h>
using namespace std;
class Staff
{
private:
    int code;
    string name;
public:
    Staff():code(0){
    }
    void set_info()
    {
        cout<<"Enter Code: ";
        cin>>code;
        cout<<"Enter Name: ";
        cin>>name;
    }
    void get_info()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Code: "<<code<<endl;
    }
    void whoAmI()
    {
        cout<<" Staff."<<endl;
    }
    ~Staff(){
    }
};
class Teacher:public Staff
{
private:
    string subject;
    string publication;
public:
    void set_info()
    {
        Staff::set_info();
        cout<<"Enter Subject Name: ";
        cin>>subject;
        cout<<"Enter Publication Name: ";
        cin>>publication;
    }
    void get_info()
    {
        Staff::get_info();
        cout<<"Subject: "<<subject<<endl;
        cout<<"Publication: "<<publication<<endl;
    }
    void whoAmI()
    {
        cout<<" Teacher -";
        Staff::whoAmI();
    }
};
class officer:public Staff
{
private:
    string grade;
public:
    void set_info()
    {
        Staff::set_info();
        cout<<"Enter Grade: ";
        cin>>grade;
    }
    void get_info()
    {
        Staff::get_info();
        cout<<"Grade: "<<grade<<endl;
    }
    void whoAmI()
    {
        cout<<" Officer -";
        Staff::whoAmI();
    }
};
class typist:public Staff
{
private:
    double speed;
public:
    typist():speed(0.0){
    }
    void set_info()
    {
        Staff::set_info();
        cout<<"Enter Typing Speed: ";
        cin>>speed;
    }
    void get_info()
    {
        Staff::get_info();
        cout<<"Typing Speed: "<<speed<<endl;
    }
    void whoAmI()
    {
        cout<<" Typist -";
        Staff::whoAmI();
    }
    ~typist(){
    }
};
class casual:public typist
{
private:
    double daily_wages;
public:
    casual():daily_wages(0.0){
    }
    void set_info()
    {
        typist::set_info();
        cout<<"Enter Daily Wages: ";
        cin>>daily_wages;
    }
    void get_info()
    {
        typist::get_info();
        cout<<"Daily Wages: "<<daily_wages<<endl;
    }
    void whoAmI()
    {
        cout<<" Casual - ";
        typist::whoAmI();
    }
    ~casual(){
    }
};
class regular:public typist
{
private:
    double daily_wages;
public:
    regular():daily_wages(0.0){
    }
    void set_info()
    {
        typist::set_info();
        cout<<"Enter Daily Wages: ";
        cin>>daily_wages;
    }
    void get_info()
    {
        typist::get_info();
        cout<<"Daily Wages: "<<daily_wages<<endl;
    }
    void whoAmI()
    {
        cout<<" Regular - ";
        typist::whoAmI();
    }
    ~regular(){
    }
};
int main()
{
    Staff s1,s2;
    Teacher t1,t2;
    typist tt1,tt2;
    officer o1,o2;
    casual c1,c2;
    regular r1,r2;
    cout<<"Enter Data for Staff: "<<endl;
    s1.set_info();
    cout<<endl;
    cout<<"Enter Data for Teacher: "<<endl;
    t1.set_info();
    cout<<endl;
    cout<<"Enter Data for officer: "<<endl;
    o1.set_info();
    cout<<endl;
    cout<<"Enter Data for Typist: "<<endl;
    tt1.set_info();
    cout<<endl;
    cout<<"Enter Data for Casual Typist: "<<endl;
    c1.set_info();
    cout<<endl;
    cout<<"Enter Data for Regular Typist: "<<endl;
    r1.set_info();
    cout<<endl;
    cout<<endl;
    cout<<"I am a";
    s1.whoAmI();
    cout<<"About Staff:"<<endl;
    s1.get_info();
    cout<<endl;
    cout<<"I am a";
    t1.whoAmI();
    cout<<"About Teacher:"<<endl;
    t1.get_info();
    cout<<endl;
    cout<<"I am a";
    tt1.whoAmI();
    cout<<"About Typist:"<<endl;
    tt1.get_info();
    cout<<endl;
    cout<<"I am a";
    c1.whoAmI();
    cout<<"About Casual Typist:"<<endl;
    c1.get_info();
    cout<<endl;
    cout<<"I am an";
    o1.whoAmI();
    cout<<"About Officer:"<<endl;
    o1.get_info();
    cout<<endl;
    cout<<"I am a";
    r1.whoAmI();
    cout<<"About Regular Typist:"<<endl;
    r1.get_info();

}
