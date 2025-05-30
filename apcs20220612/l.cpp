#include <bits/stdc++.h>
using namespace std;

// 將座標 (x,y) 編碼成 64 位元的唯一鍵值
inline long long toKey(int x, int y) {
    return ((long long)x << 32) | (unsigned int)y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    // sameX[x] 存放同一垂直線 (同一 x) 上鏡子的 y 座標列表
    unordered_map<int, vector<int> > sameX;
    // sameY[y] 存放同一水平線 (同一 y) 上鏡子的 x 座標列表
    unordered_map<int, vector<int> > sameY;
    // mirrorType 儲存每個鏡子的位置與類型 (0 表示 '/', 1 表示 '\')
    unordered_map<long long, int> mirrorType;

    sameY[0];  // 確保水平線 y=0 的 key 存在（如果沒有鏡子在 y=0，直接輸出 0）

    // 讀入鏡子資料，插入對應的列表並記錄鏡子類型
    for (int i = 0; i < n; i++) {
        int x, y, t;
        cin >> x >> y >> t;
        sameX[x].push_back(y);
        sameY[y].push_back(x);
        mirrorType[toKey(x, y)] = t;
    }

    // 對每條水平線/垂直線上的鏡子座標排序，以便二分搜尋
    for (auto& kv : sameX) {
        auto& vec = kv.second;
        sort(vec.begin(), vec.end());
    }
    for (auto& kv : sameY) {
        auto& vec = kv.second;
        sort(vec.begin(), vec.end());
    }

    int x = 0, y = 0;
    // 方向: 1=西, 2=北, 3=東, 4=南；初始朝東 (3)
    int dir = 3;
    int ans = 0;

    // 模擬雷射光的運動和反射
    while (true) {
        if (dir == 3) {  // 向右 (東)
            auto it = sameY.find(y);
            if (it == sameY.end()) break;  // 該水平線無鏡子，結束
            auto& vec = it->second;
            // 找到第一個大於當前 x 的鏡子 (upper_bound)
            auto itr = upper_bound(vec.begin(), vec.end(), x);
            if (itr == vec.end()) break;    // 右邊無鏡子，結束
            x = *itr;
            ans++;
            int t = mirrorType[toKey(x, y)];
            // '\' (1) -> 向下 (4), '/' (0) -> 向上 (2)
            dir = (t == 1) ? 4 : 2;
        }
        else if (dir == 1) {  // 向左 (西)
            auto it = sameY.find(y);
            if (it == sameY.end()) break;
            auto& vec = it->second;
            // 找到第一個小於當前 x 的鏡子 (lower_bound 再往前一格)
            auto itr = lower_bound(vec.begin(), vec.end(), x);
            if (itr == vec.begin()) break;  // 左邊無鏡子，結束
            itr--;
            x = *itr;
            ans++;
            int t = mirrorType[toKey(x, y)];
            // '\' (1) -> 向上 (2), '/' (0) -> 向下 (4)
            dir = (t == 1) ? 2 : 4;
        }
        else if (dir == 2) {  // 向上 (北)
            auto it = sameX.find(x);
            if (it == sameX.end()) break;
            auto& vec = it->second;
            // 找到第一個大於當前 y 的鏡子
            auto itr = upper_bound(vec.begin(), vec.end(), y);
            if (itr == vec.end()) break;    // 上方無鏡子，結束
            y = *itr;
            ans++;
            int t = mirrorType[toKey(x, y)];
            // '\' (1) -> 向左 (1), '/' (0) -> 向右 (3)
            dir = (t == 1) ? 1 : 3;
        }
        else if (dir == 4) {  // 向下 (南)
            auto it = sameX.find(x);
            if (it == sameX.end()) break;
            auto& vec = it->second;
            // 找到第一個小於當前 y 的鏡子
            auto itr = lower_bound(vec.begin(), vec.end(), y);
            if (itr == vec.begin()) break;  // 下方無鏡子，結束
            itr--;
            y = *itr;
            ans++;
            int t = mirrorType[toKey(x, y)];
            // '\' (1) -> 向右 (3), '/' (0) -> 向左 (1)
            dir = (t == 1) ? 3 : 1;
        }
    }

    cout << ans << "\n";
    return 0;
}