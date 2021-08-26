#include <iostream>
#include <string>
using namespace std;

enum class Material {Wood,Board,Steel,foam};
class Furniture
{
protected:
    Material madeof;
public:
    double price;
    double discount;
    Furniture()
    {
    }
    Furniture(double p,double d,Material m):price(0),discount(0),madeof(Material::Wood)
    {
        setPrice(p);
        setDiscount(d);
        setMadeof(m);
    }
    void setPrice(double val)
    {
        if(val>0)
            price=val;
    }
    void setDiscount(double val)
    {
        if(val<=price)
            discount=val;
    }
    void setMadeof(Material val)
    {
        madeof=val;
    }
    void disc()
    {
        cout<<"Enter Price: ";
        cin>>price;
        cout<<"Enter Discount: ";
        cin>>discount;
        price=price-discount;
    }
    void getPrice()
    {
        cout<<price<<endl;
    }
    void getMadeof()
    {
        if(madeof==Material::Wood)
            cout<<"Wood";
        else if(madeof==Material::Board)
            cout<<"Board";
        else if(madeof==Material::Steel)
            cout<<"Steel";
        else
            cout<<"FOam";
    }
    void getData()
    {
        cout<<"Regular Price: "<<price<<endl;
        cout<<"Discounter Price: "<<(price-discount)<<endl;
        cout<<"Material: ";
        getMadeof();
        cout<<endl;
    }

    ~Furniture()
    {
    }
};



enum class BedSize {Single,SemiDouble,Double};

class Bed:public Furniture
{
private:
    BedSize bdsz;
public:
    Bed()
    {
    }
    Bed(double p=0.0,double d=0.0,Material m=Material::Wood,BedSize b=BedSize::Single)
    {
        setPrice(p);
        setDiscount(d);
        setMadeof(m);
        setBedSize(b);
    }
    void setBedSize(BedSize val)
    {
        bdsz=val;
    }
    void getBedSize()
    {
        cout<<"Bed Size: ";
        if(bdsz==BedSize::Single)
            cout<<"Single";
        else if(bdsz==BedSize::SemiDouble)
            cout<<"Semi Double";
        else if(bdsz==BedSize::Double)
            cout<<"Double";
    }
    void productDetails()
    {
        Furniture::getData();
        getBedSize();
        cout<<endl;
        cout<<endl;
    }
    ~Bed()
    {
    }
};

enum class SofaSize {One, Two, Three, Four, Five};
class Sofa:public Furniture
{
private:
    SofaSize seatNo;
public:
    Sofa()
    {
    }
    Sofa(double p=0.0,double d=0.0,Material m=Material::Wood,SofaSize sn=SofaSize::One)
    {
        setPrice(p);
        setDiscount(d);
        setMadeof(m);
        setSeatNumber(sn);
    }
    void setSeatNumber(SofaSize val)
    {
        seatNo=val;
    }
    void getSeatNumber()
    {
        cout<<"Seat Number: ";
        if(seatNo==SofaSize::One)
            cout<<"One";
        else if(seatNo==SofaSize::Two)
            cout<<"Two";
        else if(seatNo==SofaSize::Three)
            cout<<"Three";
        else if(seatNo==SofaSize::Four)
            cout<<"Four";
        else if(seatNo==SofaSize::Five)
            cout<<"Five";
    }
    void productDetails()
    {
        Furniture::getData();
        getSeatNumber();
        cout<<endl;
        cout<<endl;
    }
    ~Sofa()
    {
    }
};
enum class AlmirahSize {Single,SemiDouble,Double};
class Almirah:public Furniture
{
private:
    AlmirahSize alsz;
public:
    Almirah()
    {
    }
    Almirah(double p=0.0,double d=0.0,Material m=Material::Wood,AlmirahSize a=AlmirahSize::Single)
    {
        setPrice(p);
        setDiscount(d);
        setMadeof(m);
        setAlmirahSize(a);
    }
    void setAlmirahSize(AlmirahSize val)
    {
        alsz=val;
    }
    void getAlmirahSize()
    {
        cout<<"Almirah Size: ";
        if(alsz==AlmirahSize::Single)
            cout<<"Single";
        else if(alsz==AlmirahSize::SemiDouble)
            cout<<"Semi Double";
        else if(alsz==AlmirahSize::Double)
            cout<<"Double";
    }
    void productDetails()
    {
        Furniture::getData();
        getAlmirahSize();
        cout<<endl;
        cout<<endl;
    }
    ~Almirah()
    {
    }
};
enum class DiningTableSize {Two,Four,Six};
class DiningTable:public Furniture
{
private:
    DiningTableSize dtsz;
public:
    DiningTable()
    {
    }
    DiningTable(double p=0.0,double d=0.0,Material m=Material::Wood,DiningTableSize dn=DiningTableSize::Two)
    {
        setPrice(p);
        setDiscount(d);
        setMadeof(m);
        setDiningTableSize(dn);
    }
    void setDiningTableSize(DiningTableSize val)
    {
        dtsz=val;
    }
    void getDiningTableSize()
    {
        cout<<"DiningTable Size: ";
        if(dtsz==DiningTableSize::Two)
            cout<<"Two";
        else if(dtsz==DiningTableSize::Four)
            cout<<"Four";
        else if(dtsz==DiningTableSize::Six)
            cout<<"Six";
    }
    void productDetails()
    {
        Furniture::getData();
        getDiningTableSize();
        cout<<endl;
        cout<<endl;
    }
    ~DiningTable()
    {
    }
};

void order(Furniture** f1, Furniture** f2)
{
    if( (*f1)->price < (*f2)->price )
    {
        Furniture* tempptr = *f1;
        *f1 = *f2;
        *f2 = tempptr;
    }
}

void sort_furniture_price(Furniture **ff, int n)
{
    void order(Furniture**, Furniture**);
    int j, k;
    for(j=0; j<n-1; j++)
        for(k=j+1; k<n; k++)
            order(ff+j, ff+k);
}


int main()
{
    Furniture *furnPtr[100];
    int n = 0;
    char choice;

    do
    {
        furnPtr[n] = new Furniture;
        furnPtr[n] -> disc();
        n++;
        cout<<"Enter choice (Y/N)?";
        cin>>choice;
    }
    while(choice == 'Y' || choice == 'y');

    cout<<"\nUnsorted List: "<<endl;

    for(int j=0; j<n; j++)
    {
        furnPtr[j]->getPrice();
    }
    sort_furniture_price(furnPtr,n);
    cout<<"\nSorted List: "<<endl;
    for(int i=0; i<n; i++)
    {
        furnPtr[i]->getPrice();
    }

    cout<<endl;

    return 0;
}

