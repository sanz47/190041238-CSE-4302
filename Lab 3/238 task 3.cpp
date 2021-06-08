#include<bits/stdc++.h>
using namespace std;
class Medicine
{
private:
    string name,genericName;
    double discountPercent,unitPrice;
public:
    Medicine():discountPercent(10),unitPrice(0) {}
    void assignName(char* nam,char* gnrc)
    {
        name=nam;
        genericName=gnrc;
    }
    void assignPrice(double price)
    {
        unitPrice=price;
    }
    void setDiscountPercent(double percent)
    {
        if(percent>=0 && percent<=45)
        {
            discountPercent=percent;
        }
        else{
            return;
        }
    }
    double getSellingPrice(int nos)
    {
        double total=unitPrice-(unitPrice*(discountPercent/100));
        total*=(double)nos;
        return total;
    }
    void display()
    {
        cout<<name<<" ("<<genericName<<") has a unit price BDT "<<unitPrice<<". Current Discount "<<discountPercent<<"% "<<endl;
    }
    ~Medicine(){
    }
};
int main()
{
    Medicine medi;
    char name[100],generic[100];
    cout<<"Enter Name & Generic Name:";
    cin>>name>>generic;
    medi.assignName(name,generic);
    medi.assignPrice(10);
    medi.setDiscountPercent(7);
    cout<<"Total Price:"<<medi.getSellingPrice(1000)<<endl;
    medi.display();



}
