#include <bits/stdc++.h>
using namespace std;

int n, lastPoint;
vector<int> bestMin, bestMax;
bool firstSolution = true;

// DFS 回溯函式：points 保存目前選定的點，diffs 保存剩餘的距離差 multiset
void dfs(vector<int>& points, multiset<int>& diffs) {
    // 如果沒有剩餘距離，找到一組解
    if (diffs.empty()) {
        // 將 points 排序並更新字典序最小/最大結果
        vector<int> sol = points;
        sort(sol.begin(), sol.end());
        if (firstSolution) {
            bestMin = bestMax = sol;
            firstSolution = false;
        }
        else {
            if (sol < bestMin) bestMin = sol;
            if (sol > bestMax) bestMax = sol;
        }
        return;
    }
    // 取出剩餘距離中的最大值作為候選點
    int dmax = *prev(diffs.end());
    int q = dmax;
    // 嘗試將 q 作為新點加入
    
    vector<int> removed;
    bool ok = true;
    // 檢查並移除 q 與現有點的距離
    for (int x : points) {
        int dist = abs(x - q);
        auto it = diffs.find(dist);
        if (it == diffs.end()) { ok = false; break; }
        removed.push_back(dist);
        diffs.erase(it);
    }
    if (ok) {
        points.push_back(q);
        // 繼續遞迴
        dfs(points, diffs);
        points.pop_back();
    }
    // 回溯：將已移除的距離放回 multiset
    for (int d : removed) diffs.insert(d);
    
    // 嘗試將 q2 = lastPoint - dmax 作為新點（避免與 q 相同或非正的重複嘗試）
    int q2 = lastPoint - dmax;
    if (q2 > 0 && q2 != q) {
        vector<int> removed;
        bool ok = true;
        for (int x : points) {
            int dist = abs(x - q2);
            auto it = diffs.find(dist);
            if (it == diffs.end()) { ok = false; break; }
            removed.push_back(dist);
            diffs.erase(it);
        }
        if (ok) {
            points.push_back(q2);
            dfs(points, diffs);
            points.pop_back();
        }
        for (int d : removed) diffs.insert(d);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    if (n == 1) {
        // 序列只有一個元素 0
        cout << "0\n0\n";
        return 0;
    }
    int m = n * (n - 1) / 2;
    multiset<int> diffs;
    for (int i = 0; i < m; i++) {
        int x; 
        cin >> x;
        diffs.insert(x);
    }
    // 最大距離即為序列最大元素
    lastPoint = *prev(diffs.end());
    vector<int> points;
    points.push_back(0);  // 已知最小點為 0
    dfs(points, diffs);

    // 輸出最小與最大字典序序列
    for (int i = 0; i < n; i++) {
        cout << bestMin[i] << (i+1<n ? ' ' : '\n');
    }
    for (int i = 0; i < n; i++) {
        cout << bestMax[i] << (i+1<n ? ' ' : '\n');
    }
    return 0;
}