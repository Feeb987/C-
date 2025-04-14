#include<iostream>
#include<set>
using namespace std;
set<int> food;

int main(){

    int x, n, num, b = 101, s = -101;
    cin >> x >> n;
    for(int i = 0;i < n;i++){
        cin >> num;
        if(num >= x && num < b) b = num;
        if(num <= x && num > s) s = num;
        food.insert(num);
    }  
    auto it1 = food.find(s), it2 = food.find(b);
    int in1 = distance(food.begin(), it1) + 1, in2 = distance(food.begin(), it2), size = food.size();
    if(in1 > size - in2 && in1 != -101 && s != -101) cout << in1 << " " << *food.begin();
    else cout << size - in2 << " " << *--food.end();

    return 0;

}
/*
c C++  
*/