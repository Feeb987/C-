#include<bits/stdc++.h>
#define f first
#define s second

using namespace std;

string input;
int inx = 0, hightest = 0, stackCount = 0;

struct Node{
    int candy;
    struct Node *l, *r;
};

stack<pair<Node*, int> > nodeStack;

Node *BuildTree(int deep){

    Node *node = new Node();
    if(input[inx] == '('){
        inx++;
        node->l = BuildTree(deep+1);
        inx++;
        node->r = BuildTree(deep+1);
        inx++;
        node->candy = -1;
        hightest = max(hightest, deep+1);
        return node;
    }
    else{
        if(input[inx] == ' ') inx++;
        cout << input[inx] << endl;
        int num = 0;
        while(input[inx] >= '0' && input[inx] <= '9') num = num * 10 + (int)input[inx++] - '0';
        cout << "candyin:" << num << endl;
        node->l = node->r = nullptr;
        node->candy = num;
        return node;
    }
}
int allStep(Node *node, int fo){

    cout << "fo:" << fo << endl;
    if(node->l && node->r){
        pair<Node*, int> nodePair;
        nodePair.f = node->r;
        nodePair.s = fo+1;
        cout << "in:" << nodePair.s << endl;
        nodeStack.push(nodePair);
        return 1 + allStep(node->l, fo+1);
    }
    if(!node->l && !node->r){
        cout << "candy:" << node->candy << endl;
        if(!nodeStack.empty()){
            pair<Node*, int> nodePair = nodeStack.top();
            cout << "out:" << nodePair.s << "," << fo << endl;
            nodeStack.pop();
            return 2 + abs(fo - nodePair.s) + allStep(nodePair.f, nodePair.s);
        }
        return 1;
    }
    
}


int main(){

    getline(cin, input);
    Node *node = BuildTree(0);
    cout << allStep(node, 0) << " " << hightest;

    return 0;
}

// (((72 3) (6 (((4 9) 15) 2))) (7 41))