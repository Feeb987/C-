#include<iostream>
#include<vector>
#include<set>
using namespace std;
long long int h = 0;
set<int> leaf;

int dfs(vector<vector<int> > &tree, int index);

int main(){

    int n, ch, p, root;
    cin >> n;
    set<int> node;
    vector<vector<int> > tree(n);
    for(int i = 0;i < n;i++){
        cin >> ch;
        for(int l = 0;l < ch;l++){
            cin >> p;
            node.insert(p);
            tree[i].push_back(p);
        } 
    }
    for(int i = 1;i <= n;i++){
        if(!node.count(i)) {
            cout << i << endl;
            root = i;
        }
        if(tree[i].empty) leaf.insert(i);
    }
    dfs(tree, root-1);
    cout << h;

    
    return 0;
}

int dfs(vector<vector<int> > &tree, int index){
    
    int num = 0;
    for(int i : tree[index])
        num = max(dfs(tree, i-1), num);
    h += num;
    return ++num;

}
/*

7 
0 
2 6 7 
2 1 4 
0 
2 3 2 
0 
0 

9 
1 6 
3 5 3 8 
0 
2 1 7 
1 9 
0 
1 2 
0 
0

*/