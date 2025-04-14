#include<iostream>
using namespace std;

int main(){

    int m, n, k, r, c, s = 0, t = 0, ans = 0;
    int f[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    cin >> m >> n >> k >> r >> c;
    int map[m][n];
    for(int i = 0;i < m;i++){
        for(int l = 0;l < n;l++){
            cin >> map[i][l];
        }
    }
    while(1){
        if(map[r][c] == 0) break;
        s += map[r][c]--;
        ans++;
        // cout << s << " " << r << " " << c << endl;
        if(s % k == 0) t = (t+1) % 4;
        while (map[r+f[t][0]][c+f[t][1]] < 0 || r+f[t][0] < 0 || r+f[t][0] >= m || c+f[t][1] < 0 || c+f[t][1] >= n ){
            t = (t+1) % 4;
        }
        r+=f[t][0];c+=f[t][1];
    }
    cout << ans++;

    return 0;
}