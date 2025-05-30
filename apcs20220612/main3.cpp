#include<bits/stdc++.h>
#define SIZE 30001
using namespace std;
int ans = 0;
unordered_map<int, vector<int> > xMap, yMap;
unordered_map<long long, int> type;

inline long long toKey(int x, int y){
    return ((long long)x<<32) | (unsigned int)y;
}

// void shoot(bool to, bool xy, int lo, int oldP) {
    //     shoot(to, !xy, newP, lo);
    // }
    
    int main(){
        
        int n, x, y, t;
        cin >> n;
        while(n--){
            cin >> x >> y >> t;
            type[toKey(x, y)] = t;
            xMap[x].push_back(y);
            yMap[y].push_back(x);
        }
        for (auto& kv : xMap) {
            auto& vec = kv.second;
            sort(vec.begin(), vec.end());
        }
        for (auto& kv : yMap) {
            auto& vec = kv.second;
            sort(vec.begin(), vec.end());
        }
        bool to = true, xy = false;
        int lo = 0, oldP = 0, newP = 0, t, x, y;
        vector<int> MAP = (xy? xMap[lo] : yMap[lo]);
        while(!MAP.empty()){
            if(MAP.empty()) break;
            if(to){
                auto it = upper_bound(MAP.begin(), MAP.end(), oldP);
                if(it == MAP.end()) break;
            }
            else{
                auto it = lower_bound(MAP.begin(), MAP.end(), oldP);
                if(it == MAP.begin()) break;
                --it;
            }
            newP = *it;
            if (xy) {
                x = lo; y = newP;
            }
            else {
                x = newP; y = lo;
            }
            ans++;
            t = type[toKey(x, y)];
            if(t) to = !to;
            xy = !xy;
            oldP = lo;
            lo = newP;
            MAP = (xy? xMap[lo] : yMap[lo]);
    }
    cout << ans;
    
    return 0;
    
}