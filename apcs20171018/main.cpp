#include<iostream>
using namespace std;

int main(){

    int a, b, o;
    cin >> a >> b >> o;
    a = (a >= 1)? 1 : 0;
    b = (b >= 1)? 1 : 0;
    if(a * b == o) cout << "AND" << endl;
    if(((a + b > 1)? 1 : a + b) == o) cout << "OR" << endl;
    if((a != b) == o) cout << "XOR";
    if((a * b != o) && (a + b != o) && ((a != b) != o)) cout << "IMPOSSIBLE";

    return 0;   
}