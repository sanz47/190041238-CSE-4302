#include <iostream>
#include <string>
using namespace std;

enum class Material {Wood,Board,Steel,foam};
class Furniture
{
protected:
    double price;
    double discount;
    Material madeof;
public:
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
    virtual void productDetails()=0;
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
        cout<<endl<<endl;
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
        cout<<endl<<endl;
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
        cout<<endl<<endl;
    }
    ~DiningTable()
    {
    }
};


int main()
{

    Furniture* f_list[100];
    f_list[0] = new Bed(10000,123,Material::Wood,BedSize::Single);
    //f_list[0]->productDetails();
    f_list[1] = new Sofa(11000,234,Material::Steel,SofaSize::Five);
    f_list[2] = new DiningTable(13000,345,Material::Wood,DiningTableSize::Four);
    f_list[3] = new Almirah(10090,123,Material::Wood,AlmirahSize::Single);
    delete f_list[0];
    delete f_list[1];
    delete f_list[2];
    delete f_list[3];
    /** for(int i=0;i<=100;i++){
         delete f_list[i];
    } **/

}
