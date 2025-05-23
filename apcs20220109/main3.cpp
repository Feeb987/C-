#include<bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    int r;
    cin >> r;
    vector<string> word(r);
    set<string> wordSet;
    while(r--) cin >> word[r];
    wordSet.insert(word.begin(), word.end());
    int ans = 0;
    for(string str : word){
        int len = str.length();
        for(int l = 1;l*2 < len;l++){
            string h = str.substr(0, l), t = str.substr(len - l, len);
            if(h == t){
                string mid = str.substr(l, len-l*2);
                ans += wordSet.count(mid);
            }
        }
    }
    cout << ans;

    return 0;

}