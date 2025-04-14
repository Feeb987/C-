#include<iostream>
#include<set>
using namespace std;
set<int> s;

int main(){

    int n, in, index = 2;
    cin >> n;
    if(n > 1){
        int ans[2][n];
        for(int i = 0;i < (n*(n-1))/2;i++){
            cin >> in;
            if(i < (n*(n-1))/2-1) s.insert(in);
        }
        int min = *s.begin(), max = in - *s.rbegin();
        for(int i = 0;i < n;i++){
            ans[0][i] = min;
            ans[1][n-3-i] = in - max;
            min += index;
            max += index++;
        }
        for(int i = 0;i < 2;i++){
            cout << "0 ";
            for(int l = 0;l < n-2;l++)
                cout << ans[i][l] << " ";
            cout << in << endl;
        }
    }
    else{
        cin >> in;
        for(int i = 0;i < 2;i++)
            cout << "0 " << in << endl;
    }

    return 0;

}