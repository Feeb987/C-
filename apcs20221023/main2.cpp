#include<bits/stdc++.h>
using namespace std;

int block[5][4][3] = {
    {
        {1, 0, 0},
        {1, 0, 0},
        {1, 0, 0},
        {1, 0, 0}
    },
    {
        {1, 1, 1},
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    },
    {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 0},
        {0, 0, 0}
    },
    {
        {0, 0, 1},
        {1, 1, 1},
        {0, 0, 0},
        {0, 0, 0}
    },
    {
        {0, 1, 0},
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 0}
    }
}

int toBlock(char type){
    if(type == 'A') return 1;
    if(type == 'B') return 2;
    if(type == 'C') return 3;
    if(type == 'D') return 4;
    if(type == 'E') return 5;
}

int main(){

    int r, c, n, h;
    cin >> r >> c >> n;
    int base[r][c] = {0}, base2[r][c] = {0};
    char type;
    while(n--){
        cin >> type >> h;
        int t = toBlock(type);
        for(int i = c-1;i >= 0;i--){
            for(int l = h, index = 0;l < 4+h;l++, index++){
                
            }
        }
    }

    return 0;

}