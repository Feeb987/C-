#include<bits/stdc++.h>
using namespace std;

int main(){

    int s, t, n, m, r, c = 0, mi = INT32_MAX;
    bool is = true;
    cin >> s >> t >> n >> m >> r;
    vector<vector<int>> arr1(s, vector<int>(t));
    vector<vector<int>> arr2(n, vector<int>(m));
    for(int i = 0;i < s;i++)
        for(int l = 0;l < t;l++)
            cin >> arr1[i][l];
    for(int i = 0;i < n;i++)
        for(int l = 0;l < m;l++)
            cin >> arr2[i][l];
    for(int i = 0;i <= n - s;i++){
        for(int l = 0;l <= m - t;l++){
            int d = 0, nm = 0;
            for(int j = 0;j < s;j++){
                for(int k = 0;k < t;k++){
                    if(arr1[j][k] != arr2[i+j][l+k]){
                        d++;
                        nm += arr2[i+j][l+k]-arr1[j][k];
                    }
                }
            }
            if(d <= r && d){
                nm = abs(nm);
                mi = min(mi, nm);
                c++;
                is = false;
            }
        }
    }
    cout << c << "\n" << ((is)? -1 : mi);

    return 0;

}