#include<iostream>
using namespace std;

int main(){

    int x, y, nowAdd, to;
    cin >> y >> x;
    int card[y][x], ans = 0;
    for(int i = 0;i < y;i++)
        for(int l = 0;l < x;l++)
            cin >> card[i][l];
    while(1){
        nowAdd = 0;
        for(int i = 0;i < y;i++){
            for(int l = 0;l < x -1;l++){
                to = 1;
                while (card[i][l+to] < 0 && to < x - l - 1) to++;
                if(card[i][l] == card[i][l+to] && card[i][l] > -1){
                    ans += card[i][l];
                    card[i][l] = -1;
                    card[i][l+to] = -1;
                    nowAdd++;
                }
            }
        }
        for(int l = 0;l < x;l++){
            for(int i = 0;i < y - 1;i++){
                to = 1;
                while (card[i+to][l] < 0 && to < y - i - 1) to++;
                if(card[i][l] == card[i+to][l] && card[i][l] > -1){
                    ans += card[i][l];
                    card[i][l] = -1;
                    card[i+to][l] = -1;
                    nowAdd++;
                }
            }
        }
        if(nowAdd == 0) break;
    }
    cout << ans;
    return 0;

}