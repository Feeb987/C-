#include<bits/stdc++.h>

using namespace std;

string checkAns(int arr[2][7]){
    string ans = "";
    if(arr[0][1] == arr[0][3] || arr[0][1] != arr[0][5] || arr[1][1] == arr[1][3] || arr[1][1] != arr[1][5]) ans += "A";
    if(!arr[0][6] || arr[1][6]) ans += "B";
    if(arr[0][1] == arr[1][1] || arr[0][3] == arr[1][3] || arr[0][5] == arr[1][5]) ans += "C";
    return (ans!="")? ans : "None";
}

int main(){

    int r;
    cin >> r;
    vector<string> err;
    int arr[2][7];
    for(int i = 0;i < r;i++){
        for(int l = 0;l < 2;l++) 
            for(int j = 0;j < 7;j++) cin >> arr[l][j];
        err.push_back(checkAns(arr));
    }
    for(auto it = err.begin(); it != err.end();it++) cout << *it << endl;

    return 0;
    
}