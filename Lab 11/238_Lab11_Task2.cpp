#include<iostream>
#include<typeinfo>
#include<process.h>
#include<fstream>

using namespace std;

const int MAXSTF=100;

enum staff_type { eteacher, eofficer} ;

class Staff
{
private:
    int code;
    string name;
    static int n;
    static Staff* arrst[];
public:
    virtual void set_info()
    {
        cout<<"Enter Code: ";
        cin>>code;
        cout<<"Enter Name: ";
        cin>>name;
    }
    virtual void get_info()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Code: "<<code<<endl;
    }
    virtual staff_type get_type();
    static void add();
    static void display();
    static void read(); //read from disk file
    static void write(); //write to disk fil
};

int Staff::n;
Staff* Staff::arrst[MAXSTF];

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
    }
};

void Staff::add()
{
    int in;
    cout<<"Press 1 to add an officer"<<endl;
    cout<<"Press 2 to add a Teacher"<<endl;
    cout<<"Enter Choice: ";
    cin>>in;
    switch(in)
    {
    case 1:
        arrst[n]=new officer;
        break;
    case 2:
        arrst[n]=new Teacher;
        break;
    default:
        cout<<"Error in Input"<<endl;
    }
    arrst[n++]->set_info();
}

void Staff::display()
{
    for(int j=0; j<n; j++)
    {
        cout<<"Staff No: "<<(j+1)<<endl;
        switch(arrst[j]->get_type())
        {
        case eofficer:
            cout<<"Staff Type : Officer"<<endl;
            break;
        case eteacher:
            cout<<"Staff Type : Teacher"<<endl;
            break;
        default:
            cout<<"Error Occurred"<<endl;
        }
        arrst[j]->get_info();
    }
}

staff_type Staff::get_type()
{
    if(typeid(*this)==typeid(Teacher))
    {
        return eteacher;
    }
    else if(typeid(*this)==typeid(officer))
    {
        return eofficer;
    }
    else
    {
        cerr<<"\nWrong Employee Type"<<endl;
        exit(1);
    }
    return eteacher;
}

void Staff::write()
{
    int siz;
    cout << "Writing " << n << " Staffs"<<endl;
    ofstream ouf; //open ofstream in binary
    staff_type stype; //type of each employee object
    ouf.open("Staff.DAT", ios::trunc | ios::binary );
    if(!ouf)
    {
        cout<<"\nCan't open file"<<endl;
        return;
    }
    for(int j=0; j<n; j++) //for every employee object
    {
        //get its type
        stype = arrst[j]->get_type();
//write type to file
        ouf.write( (char*)&stype, sizeof(stype) );
        switch(stype) //find its size
        {
        case eteacher:
            siz=sizeof(Teacher);
            break;
        case eofficer:
            siz=sizeof(officer);
            break;
        } //write employee object to file
        ouf.write( (char*)(arrst[j]), siz );
        if(!ouf)
        {
            cout << "\nCan't write to file"<<endl;
            return;
        }
    }
}
//--------------------------------------------------------------
//read data for all employees from file into memory
void Staff::read()
{
    int siz; //size of employee object
    staff_type stype; //type of employee
    ifstream inf; //open ifstream in binary
    inf.open("Staff.DAT", ios::binary);
    if(!inf)
    {
        cout << "\nCan't open file"<<endl;
        return;
    }
    n = 0; //no employees in memory yet
    while(1)
    {
        //read type of next employee
        inf.read( (char*)&stype, sizeof(stype) );
        if( inf.eof() ) //quit loop on eof
            break;
        if(!inf) //error reading type
        {
            cout << "\nCan't read type from file"<<endl;
            return;
        }
        switch(stype)
        {
        //make new employee
        case eteacher: //of correct type
            arrst[n] = new Teacher;
            siz=sizeof(Teacher);
            break;
        case eofficer:
            arrst[n] = new officer;
            siz=sizeof(officer);
            break;
        default:
            cout << "\nUnknown type in file"<<endl;
            return;
        } //read data from file into it
        inf.read( (char*)arrst[n], siz );
        if(!inf) //error but not eof
        {
            cout << "\nCan't read data from file"<<endl;
            return;
        }
        n++; //count employee
    } //end while
    cout << "Reading " << n << " Staffs"<<endl;
}

int main()
{
    int input;
    while(1)
    {
        cout <<"\n\nPress 1 to add data for an employee"<<endl;
        cout<<"Press 2 to display data for all employees"<<endl;
        cout<<"Press 3 write all employee data to file"<<endl;
        cout<<"Press 4 read all employee data from file"<<endl;
        cout<<"Press 5 to exit"<<endl;
        cout<<"\nEnter selection: ";

        cin >> input;
        switch(input)
        {
        case 1: //add an employee to list
            Staff::add();
            break;
        case 2: //display all employees
            Staff::display();
            break;
        case 3: //write employees to file
            Staff::write();
            break;
        case 4: //read all employees from file
            Staff::read();
            break;
        case 5:
            exit(0); //exit program
        default:
            cout << "\nUnknown command";
        } //end switch
    } //end while
    return 0;


}
