#include <iostream>
using namespace std ;
class customer{
    public:
    string name;
    int acc_num;
    int * balance;
    //NOTE:when a parameterised constructor is present the compiler doesnt 
    //provide a constructor from its side
    
    //PARAMETERISED CONSTRUCTOR
    customer(string name, int acc_num,int bal){
        this->name = name ;
        this->acc_num= acc_num;
        balance=new int;
        *balance =bal;
    }
    customer()//DEFAULT CONSTRUCTOR 
    {
        cout<<"object created successfully"<<endl;
        name="omm";

    }
    //COPY CONSTRUCTOR
    customer(customer &b){
        name=b.name;
        acc_num=b.acc_num;
        balance=b.balance;

    }

    // //INLINE CONSTRUCTOR 
    // inline customer(string a, int b,int c):name(a),acc_num(b),balance(c){}


    
    void display(){
        cout<<name<<" "<<acc_num<<" "<<*balance<<" "<<endl;
    }

    //DESTRUCTOR
    
    ~customer(){
        delete balance;
        cout<<"memory freed successfully:)"<<endl;
    }

};
int main ()
{
    customer a1("OMM",123,5000);
    customer a2(a1);//Shallow copy
    a1.display();
    cout<<endl;
    a2.display();
    customer * a3=new customer;
    cout<<a3->name<<endl;
    delete a3;


}