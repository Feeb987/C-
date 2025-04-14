#include<iostream>
using namespace std;

class p{
    public:
        int x, y;
}p[105];

int main(){

    int r, f[3] = {0, 0, 0}, m = 0, x, y, ix, iy;
    cin >> r;
    p[0].x = 0;p[0].y = 0;
    for(int i = 0;i < r;i++) 
        cin >> p[i+1].x >> p[i+1].y;
    for(int i = 2;i < r + 1;i++){
        ix = p[i-1].x - p[i-2].x;
        x = p[i].x - p[i-1].x;
        iy = p[i-1].y - p[i-2].y;
        y = p[i].y - p[i-1].y;
        m = x * iy - ix * y;
        if(m < 0) f[0]++;
        else if(m > 0) f[1]++;
        else if(x * ix < 0 || y * iy < 0) f[2]++;
    }
    for(int i = 0;i < 3;i++)
        cout << f[i] << ((i == 2)? "" : " ");

    return 0;
    
}