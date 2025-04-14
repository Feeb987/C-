#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
vector<string> tubeMap;

int dfs(int index);

int main(){

    int x, y;
    cin >> y >> x;
    string str;
    for(int i = 0;i < y;i++){
        cin >> str;
        tubeMap.push_back(str);
    }

    return 0;

}

int dfs(int index){

}