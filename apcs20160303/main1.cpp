#include<bits/stdc++.h>

using namespace std;

bool rule(int a, int b){
    return a < b;
}

int main(){

    vector<int> all, pass, noPass;
    int round, input;
    cin >> round;
    while(round--){
        cin >> input;
        all.push_back(input);
        if(input > 59) pass.push_back(input);
        else noPass.push_back(input);
    }
    sort(all.begin(), all.end(), rule);
    sort(pass.begin(), pass.end(), rule);
    sort(noPass.begin(), noPass.end(), rule);
    for(int i : all) cout << i << " ";
    cout << endl;
    if(noPass.empty()) cout << "best case";
    else cout << noPass.back();
    cout << endl;
    if(pass.empty()) cout << "worst case";
    else cout << pass.front();

    return 0;

}
/*
10
0 11 22 33 55 66 77 99 88 44
*/