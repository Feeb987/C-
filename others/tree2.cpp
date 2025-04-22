#include<bits/stdc++.h>

using namespace std;

struct Node{
    string name;
    vector<Node*> child;

    int next(int index){
        int allChild = 0;
        if(index > 0) for(auto i : this->child) allChild += (*i)->next(index-1);
        else if (index == 1 && !this->child.empty()) return this->childNum();
        else return 0;
        return allChild;
    }

    int childNum(){
        return this->child.size();
    }
};

struct Max3{
    int num;
    Max3 *next; 
}


int main(){

    int round, n, index, childNum;
    string name;
    cin >> round;
    map<string, Node*> tree;
    Node *node = nullptr;
    while(round--){
        cin >> n >> index;
        for(int i = 0;i < n;i++){
            cin >> name >> childNum;
            node->name = name;
            for(int l = 0;l < childNum;l++){
                Node *child = nullptr;
                cin >> name;
                if(tree.find(name)) child = tree.at(name);
                else{
                    child->name = name;
                    tree.insert({name, child});
                    node->child.push_back()
                }
                node->child.push_back(child);
            }
        }
    }


    return 0;

}