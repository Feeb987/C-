#include <iostream>
#include <cmath>
using namespace std;

void fun(int t, int* map, int r, int c);

int main() {

    int m, n, h, r, c, t;
    cin >> m >> n >> h;
    int map[m][n];
    for(int i = 0;i < h;i++){
        cin >> r >> c >> t;
        if(i == 0){
            map[r][c] = 1;
        }
        else{
            fun(t, map, r, c);
        }
    }
    return 0;

}

void fun(int t, int &map, int r, int c){

}