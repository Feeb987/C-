#include<bits/stdc++.h>

using namespace std;
int **arr, stay, stax, m, n, q;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bsf(int index);

struct bomp{
    int x, y, b;
    bomp(int x, int y, int b){
        this->x = x;
        this->y = y;
        this->b = b;
    }
};


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
        // cout << endl << h << " " << l << " " << min << endl;
        if(bsf(min) >= q) h = min-1;
        else l = min+1;
    }
    cout << l;

    return 0;

}

//看不懂哥們
int bsf(int index) {
    int count = 1; // 計算能炸到的格子數量（包含初始位置）
    vector<vector<int> > visited(m, vector<int>(n, 0)); // 訪問標記陣列，紀錄爆炸範圍
    queue<bomp> qu; // 廣度優先搜尋隊列

    qu.push(bomp(stax, stay, index)); // 從初始炸彈位置開始爆炸
    visited[stay][stax] = index + 10; // 標記起始點，數值加 10 來防止誤判

    while (!qu.empty()) {
        bomp current = qu.front();
        qu.pop();

        if (current.b == 0) continue; // 若當前範圍已經耗盡則跳過

        for (int i = 0; i < 4; ++i) { // 遍歷四個方向
            int newX = current.x + dx[i];
            int newY = current.y + dy[i];

            if (newX >= 0 && newX < n && newY >= 0 && newY < m && arr[newY][newX] != -1) {
                int newRange = max(arr[newY][newX], current.b - 1); // 計算新位置的爆炸範圍

                // 如果該格未被訪問或爆炸範圍更大則更新
                if (visited[newY][newX] - 10 < newRange) {
                    if (!visited[newY][newX]) count++; // 未訪問過則計入爆炸範圍
                    visited[newY][newX] = newRange + 10;
                    qu.push(bomp(newX, newY, newRange)); // 推進新的位置和剩餘範圍
                }
            }
        }
    }

    return count;
}