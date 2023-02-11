#include<bits/stdc++.h>
using namespace std;
/*Encapsulation babohar korar karon holo
data ke private and protect korar janno
*/
class student
{
private :
    string name ;
public :
    void setname (string x)
    {
        name = x;
    }
    string  getname ()
    {
        return name ;
    }
};
int main ()
{
    student s1;
    s1.setname("Sadat");
    cout<<s1.getname();
}

//outputy=Sadat.
