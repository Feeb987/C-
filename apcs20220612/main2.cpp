#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    string s;
    cin >> s;
    for(int row = n - 1; row >= 0; --row) {
        string t;
        int c = 0;
        for(int j = m - 1; j >= 0; --j) {
            if(a[row][j] == '1') {
                t.push_back(s[j]);
                c++;
            }
            else t.insert(t.begin(), s[j]);
        }
        if(c % 2) {
            int len = t.length(), mid = len / 2;
            if(!len % 2) t = t.substr(mid) + t.substr(0, mid);
            else t = t.substr(mid + 1) + t[mid] + t.substr(0, mid);
        }
        s = t;
    }
    cout << s;

    return 0;
    
}