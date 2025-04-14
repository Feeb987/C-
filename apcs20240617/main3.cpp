#include <iostream>
#include<vector>
#include<queue>
using namespace std;

int p, q, r, m;

struct logic{
    int type, state;
}

vector<logic> arr;

int main() {

    cin >> p >> q >> r >> m;
    for(int i = 0;i < p;i++){
        int a;
        cin >> a;
        arr.push({5, a});
    }


    return 0;

}