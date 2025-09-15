#include <iostream>
using namespace std ;
class student{
    public:
    string name;
    int rn;
    int age;
};
int main ()
{
    student s1,s2;
    s1.name="omm";
    s1.rn=1606;
    s1.age =19;
    s2.name="asmit";
    s2.rn=2953;
    s2.age=19;
    cout<<s1.name<<" "<<s1.rn<<" "<<s1.age<<" ";
    cout<<endl;
    cout<<s2.name<<" "<<s2.rn<<" "<<s2.age<<" ";



}