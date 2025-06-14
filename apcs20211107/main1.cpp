#include<bits/stdc++.h>
using namespace std;

int main(){

    int l, ans = 0;
    cin >> l;
    int arr[l];
    queue<int> b;
    for(int i = 0;i < l;i++){
        cin >> arr[i];
        if(arr[i]==0) b.push(i);
    }
    while (!b.empty()){
        int x = b.front(); b.pop();
        if(!x) ans += arr[x+1];
        else if(x+1==l) ans += arr[x-1];
        else ans += min(arr[x-1], arr[x+1]);
    }
    cout << ans;
    

    return 0;

}