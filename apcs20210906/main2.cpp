#include<bits/stdc++.h>

using namespace std;

int main(){

    int n, m, k, no;
    cin >> n >> m >> k;
    vector<vector<int> > boss(k, vector<int>(4));
    vector<vector<bool> > bomn(n, vector<bool>(m, false));
    for(int i = 0;i < k;i++) cin >> boss[i][0] >> boss[i][1] >> boss[i][2] >> boss[i][3];
    bool moving = true;
    while (moving) {
        moving = false;
        for (int i = 0; i < k; i++) {
            int& y = boss[i][0];
            int& x = boss[i][1];
            int dy = boss[i][2];
            int dx = boss[i][3];
            if (x == -1 && y == -1) {
                continue;
            }
            if (x >= 0 && x < n && y >= 0 && y < m) {
                bomn[y][x] = true;
            }
            x += dx;y += dy;
            if (x < 0 || x >= n || y < 0 || y >= m) {
                x = -1;
                y = -1;
                continue;
            }
            if (bomn[y][x]) {
                bomn[y][x] = false;
                x = -1;
                y = -1;
                continue;
            }
            cout << i << " " << x << " " << y << endl;
            moving = true;
        }
        for(int i = 0;i < n;i++){
            for(int l = 0;l < m;l++){
                cout << ((bomn[i][l])? 1 : 0) << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    int ans = 0;
    for(int i = 0;i < n;i++){
        for(int l = 0;l < m;l++){
            if(bomn[i][l]) ans++;
            cout << ((bomn[i][l])? 1 : 0) << " ";
        }
        cout << endl;
    }
    cout << ans;

    return 0;

}