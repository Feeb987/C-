#include<bits/stdc++.h>
using namespace std;
long long ans = 0;

void dfs(int last){
    int now;
    cin >> now;
    if(last && now) ans += abs(now-last);
    if(now) for(int i = 0;i < 2 + now%2;i++) dfs(now);
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(0);
    dfs(0);
    cout << ans;

    return 0;

}