#include<bits/stdc++.h>
using namespace std;

bool u(char c){
    return c == 'I' || c == 'X' || c == 'L' || c == 'J';
}

bool d(char c){
    return c == 'I' || c == 'X' || c == '7' || c == 'F';
}

bool le(char c){
    return c == 'H' || c == 'X' || c == '7' || c == 'J';
}

bool r(char c){
    return c == 'H' || c == 'X' || c == 'F' || c == 'L';
}

int main(){

    int x, y, ans = 0, maxPath = 0;
    cin >> y >> x;
    vector<vector<char> > tubeMap(y, vector<char>(x, '0'));
    vector<vector<int> > MAP(y, vector<int>(x, 0));
    for(int i = 0;i < y;i++)
        for(int l = 0;l < x;l++)
            cin >> tubeMap[i][l];
    for(int i = 0;i < y;i++){
        for(int l = 0;l < x;l++){

            if(tubeMap[i][l] != '0' && !MAP[i][l]){
                queue<pair<int, int> > to;
                to.push(make_pair(i, l));
                maxPath = 0;
                while(!to.empty()){
                    int nx = to.front().second, ny = to.front().first;
                    char tube = tubeMap[ny][nx];
                    to.pop();
                    if(MAP[ny][nx]) continue;
                    MAP[ny][nx] = 1;
                    if(u(tube) && ny-1 >= 0 && !MAP[ny-1][nx] && d(tubeMap[ny-1][nx])) to.push(make_pair(ny-1, nx));
                    if(d(tube) && ny+1 < y && !MAP[ny+1][nx] && u(tubeMap[ny+1][nx])) to.push(make_pair(ny+1, nx));
                    if(le(tube) && nx-1 >= 0 && !MAP[ny][nx-1] && r(tubeMap[ny][nx-1])) to.push(make_pair(ny, nx-1));
                    if(r(tube) && nx+1 < x && !MAP[ny][nx+1] && le(tubeMap[ny][nx+1])) to.push(make_pair(ny, nx+1));
                    maxPath++;
                }
                ans = max(ans, maxPath);
            }

        }
    }
    cout << ans;
    

    return 0;

}