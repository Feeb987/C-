#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b){
    return a.f < b.f;
}

int main(){

    int n;
    cin >> n;
    vector<pair<int, int> > line(n);
    for(int i = 0;i < n;i++) cin >> line[i].f >> line[i].s;
    sort(line.begin(), line.end(), comp);

    long long lm = 0, nf = line[0].f, ns = line[0].s;
    for(int i = 1;i < n;i++){
        if(ns >= line[i].f && nf <= line[i].f && ns < line[i].s) ns = line[i].s;
        if(ns < line[i].f){
            lm += ns - nf;
            nf = line[i].f; ns = line[i].s;
        }
    }
    cout << lm + (ns - nf);

    return 0;

}