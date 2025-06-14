#include<bits/stdc++.h>
using namespace std;
long long i = 0, ans = 0;
queue<int> arr;

void dfs(){
    int n = arr.front();
    arr.pop();
    if (!n) return;
    for(int i = 0;i < 2 + n%2;i++){
        int t = arr.front();
        if(t)ans += abs(n - t);
        dfs();
    }
}

int main(){
    
    string str;
    getline(cin, str);
    int t = 0;
    for(char c : str){
        if(c==' '){
            arr.push(t);
            t = 0;
            continue;
        }
        t = t*10 + c-'0';
    }
    arr.push(t);
    dfs();
    cout << ans;
    
    return 0;
    
}