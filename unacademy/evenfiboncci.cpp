#include <iostream>

using namespace std;

int main()
{
    int x;
    cin>>x;

    int zero_even_fibonacci = 0;
    int first_even_fibonacci = 2;

    cout<<zero_even_fibonacci<<" "<<first_even_fibonacci<<" ";

    int a= 0, b=2 , c= 2;

    while(c <= x) {
        c= 4*b + a;
        a = b;
        b = c;
        cout<<c<<" ";
    }
    return 0;
}
