#include<bits/stdc++.h>
using namespace std;

int main(){

    int h, w, r, x, y, t, c;
    cin >> h >> w >> r;
    vector<vector<int> > paper(h, vector<int>(w, 0));
    for(int i = 0;i < r;i++){
        cin >> y >> x >> t >> c;
        for(int l = 0;l < h;l++){
            for(int k = 0;k < w;k++){
                if(abs(l-y)+abs(k-x) <= t){
                    paper[l][k] += c;
                }
            }
        }
    }
    for(int i = 0;i < h;i++){
        for(int l = 0;l < w;l++){
            cout << paper[i][l] << " ";
        }
        cout << endl;
    }
    return 0;

}