#include<bits/stdc++.h>
using namespace std;

int main(){

    map<int, int, greater<int> > arr;
    int in, m = 1;
    for(int i = 0;i < 3;i++){
        cin >> in;
        if(!arr.count(in)) arr[in] = 1;
        else{
            arr[in]++;
            m = max(arr[in], m);
        }
    }
    cout << m << " ";
    for(auto p : arr){
        cout << p.first << " ";
    }
    cout << endl;

    return 0;

}