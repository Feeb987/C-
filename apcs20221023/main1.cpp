#include<bits/stdc++.h>
using namespace std;

int main(){

    int n, nMax = -1, nMin = INT32_MAX, x, y, dx = 101, dy = 101;
    cin >> n;
    while(n--){
        cin >> x >> y;
        if(dx == 101){
            dx = x;
            dy = y;
            continue;
        }
        int tem = abs(x-dx) + abs(y-dy);
        nMin = min(nMin, tem); nMax = max(nMax, tem);
        dx = x;
        dy = y;
    }
    cout << nMax << " " << nMin;

    return 0;

}