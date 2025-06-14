#include <iostream>
#include<vector>
#include<cmath>
#include <algorithm>
using namespace std;
#define f first
#define s second

bool cmp(pair<int, int> a, pair<int, int> b){
    return pow(a.f, 2) + pow(a.s, 2) > pow(b.f, 2) + pow(b.s, 2);
}

int main() {

    int n;
    cin >> n;
    vector<pair<int, int> > c(n);
    for(int i = 0;i < n;i++){
        cin >> c[i].f >> c[i].s;
    }
    sort(c.begin(), c.end(), cmp);
    cout << c[1].f << " " << c[1].s;

    return 0;

}
