#include <iostream>
#include <cmath>
using namespace std;

int main() {

    int n, ans = 0, w = 1;
    cin >> n;
    int num[n];
    cin >> num[0];
    for(int i = 1;i < n;i++){
        cin >> num[i];
        if(num[i-1] > num[i]){
            w++;
        }
        else{
            ans = max(ans, w);
            w = 1;
        }
    }
    cout << max(ans, w);;


    return 0;
}