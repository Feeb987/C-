#include<bits/stdc++.h>
using namespace std;

int main() {

    int n, d, x, y, ans = 0;
    bool b = true;
    cin >> n >> d >> x;
    n--;
    while(n--){
        cin >> y;
        if(!b && y<=x-d){
            x = y;
            b = true;
        }
        if(y>=x+d && b){
            ans += y - x;
            x = y;
            b = false;
        }
    }
    cout << ans;

    return 0;

}