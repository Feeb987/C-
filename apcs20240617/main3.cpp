#include<iostream>
#include<set>
#include<string>
using namespace std;
set<string> st;
string w, t, str;
int r;

void dfs(int index);

int main(){

    cin >> w >> r >> t;
    str = string(r, w[0]);
    for(int i = 0;i < t.size();i++){
        st.insert(t.substr(i, r));
    }
    dfs(0);

    return 0;

}

void dfs(int index){
    if(index >= r){
        if(st.count(str)) return;
        cout << str;
        exit(0);
    }
    for(int i = 0;i < w.size();i++){
        str[index] = w[i];
        dfs(index+1);
    }
}