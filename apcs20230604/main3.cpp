#include<bits/stdc++.h>
using l = long long;
using namespace std;
l i = 0;
string in;

l s(int &h, int &t){
    l num = 0;
    h = t = -1;
    while (i < in.size()){
        char c = in[i];
        if(c == 'T'){
            int n = stoi(in.substr(i+1, 2));
            i += 3;
            if(t < 0) h = n;
            else num += abs(t - n);
            t = n;
        }
        else if(c == 'L'){
            int r = in[i+1] - '0';
            i += 2;
            int h2, t2;
            l c = s(h2, t2);
            if(t < 0) h = h2;
            else num += abs(t - h2);
            t = t2;
            num += c*r + (r-1)*(abs(h2-t2));
        }
        else if(c == 'E'){
            i++;
            return num;
        }
    }
    return num;
}

int main(){

    cin >> in;
    int h, t;
    l ans = s(h, t);
    ans += abs(10 - h);
    cout << ans;

    return 0;

}