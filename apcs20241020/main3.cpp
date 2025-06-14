#include<bits/stdc++.h>
using namespace std;
int **arr, stay, stax, m, n, q;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

struct bomp{
    int x, y, b;
    bomp(int x, int y, int b){
        this->x = x;
        this->y = y;
        this->b = b;
    }
};

int bsf(int index){

    int count = 1;
    vector<vector<int> > visited(m, vector<int>(n, 0));
    queue<bomp> qu;
    qu.push(bomp(stax, stay, index));
    visited[stay][stax] = index + 10;
    while (!qu.empty()) {
        bomp current = qu.front();
        qu.pop();
        if (current.b == 0) continue;
        for (int i = 0; i < 4; ++i) {
            int newX = current.x + dx[i];
            int newY = current.y + dy[i];
            if (newX >= 0 && newX < n && newY >= 0 && newY < m && arr[newY][newX] != -1) {
                int newRange = max(arr[newY][newX], current.b - 1); 
                if (visited[newY][newX] - 10 < newRange) {
                    if (!visited[newY][newX]) count++;
                    visited[newY][newX] = newRange + 10;
                    qu.push(bomp(newX, newY, newRange));
                }
            }
        }
    }

    return count;
    
}

int main(){

    cin >> m >> n >> q;
    arr = new int *[m];
    for (int i = 0;i < m;i++){
        arr[i] = new int[n];
        for (int l = 0;l < n;l++){
            cin >> arr[i][l];
            if(arr[i][l] == -2){
                stay = i;
                stax = l;
            }
        }
    }
    int l = 1, h = m*n, min;
    while(l <= h){
        min = (l+h)/2;
        if(bsf(min) >= q) h = min-1;
        else l = min+1;
    }
    cout << l;

    return 0;

}