#include<bits/stdc++.h>
using namespace std;

int main(){

    int f, n, now, last, wlr = 0;
    bool wl = false;
    cin >> f >> n;
    map<int, int> a = {{0, 5}, {2, 0}, {5, 2}};
    for(int i = 0;i < n;i++){
        cin >> now;
        if(!wlr){
            cout << f << " ";
            if(a[f]==now){
                wlr = i+1;
                wl = false;
            }
            else if(a[now]==f){
                wlr = i+1;
                wl = true;
            }
            else if(i > 0 && now == last){
                f = a[now];
            }
            else f = now;
            last = now;
        }
    }
    string str = (!wlr)? ": Drew at round " : (wl)? ": Won at round " : ": Lost at round ";
    if(!wlr) wlr = n;
    cout << str << wlr;

    return 0;

}