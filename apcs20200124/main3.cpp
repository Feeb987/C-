#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, l;
    cin >> n >> l;
    vector<pair<int, int>> tree(n);
    vector<vector<int>> v(n, vector<int>(2));
    vector<bool> cut(n, false);
    queue<int> q;
    for(int i = 0;i < n;i++) cin >> tree[i].f;
    for(int i = 0;i < n;i++){
        cin >> tree[i].s;
        q.push(i);
        v[i][0] = i-1;
        v[i][1] = i+1;
    } 
    int mh = 0, c = 0;
    while (!q.empty()){
        int i = q.front();
        q.pop();
        if(cut[i]) continue;
        int left = (v[i][0]<0)? 0 : tree[v[i][0]].f, right = (v[i][1] >= n)? l : tree[v[i][1]].f;
        if(tree[i].f - tree[i].s >= left || tree[i].f + tree[i].s <= right){
            c++;
            cut[i] = true;
            mh = max(mh, tree[i].s);
            if(v[i][0] >= 0 && !cut[v[i][0]]) q.push(v[i][0]);
            if(v[i][1] < n && !cut[v[i][1]]) q.push(v[i][1]);
            if(v[i][0] >= 0)v[v[i][0]][1] = v[i][1];
            if(v[i][1] < n) v[v[i][1]][0] = v[i][0];
        }
    }
    cout << c << "\n" << mh;
    
    return 0;
    
}
