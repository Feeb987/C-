#include<iostream>
#include<set>
#define f first
#define s second
using namespace std;
int m[50][50], mx, my;
set<pair<int, int> > xy;

int sub(int x, int y);

int main(){

    int x, y, ans = 0, num;
    cin >> my >> mx;      
    for(int i = 0;i < my;i++){
        for(int l = 0;l < mx;l++){
            cin >> m[i][l];
        }
    }
    // for(int i = 0;i < my;i++){
    //     for(int l = 0;l < mx;l++){
    //         cout <<  m[i][l];
    //     }
    //     cout << endl;
    // }
    for(int i = 0;i < my;i++){
        for(int l = 0;l < mx;l++){
            ans += sub(l+1, i+1);
        }
    }
    cout << ans << endl;
    for(auto it : xy)
        cout << it.f << " " << it.s << endl;

    return 0;

}

int sub(int x, int y){

    int num = 0, ans = 0;
    for(int i = 0;i < my;i++){
        for(int l = 0;l < mx;l++){
            if(abs((x-1) - l) + abs((y-1) - i) <= m[y-1][x-1]){
                num += m[i][l];
            }
        }
    }
    if(num % 10 == m[y-1][x-1]){
        xy.insert(make_pair(y-1, x-1));
        ans++;
    }
    return ans;

}