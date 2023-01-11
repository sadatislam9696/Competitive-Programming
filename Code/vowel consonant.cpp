#include<bits/stdc++.h>
using namespace std;
int main()
{
    char ch;
    cout <<"Enter any later : ";
    cin>>ch;

    ch = tolower(ch);

    switch (ch)
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        cout<<"This number is : Vowel  ";
        break ;
    default:
        cout<<"This number is : Consonant";
    }
}
