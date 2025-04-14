#include<bits/stdc++.h>
#define SIZE 100000

using namespace std;

struct snowFlakesNode{
    int snowFlakes[6];
    struct snowFlakesNode *next;
};

int code(int snowFlakes[]){
    return (snowFlakes[0] + snowFlakes[1] + snowFlakes[2] + snowFlakes[3] + snowFlakes[4] + snowFlakes[5]) % SIZE;
}

bool r(int flakes1[], int flakes2[], int start){

    for(int end = 0;end <  6;end++) if(flakes1[end] != flakes2[(start+end)%6]) return false;
    return true;

}

bool l(int flakes1[], int flakes2[], int start){

    for(int end = 0;end <  6;end++) if(flakes1[end] != flakes2[(start-end+6)%6]) return false;
    return true;

}

bool isTheyEqual(int flake1[], int flakes2[]){
    for(int i = 0;i < 6;i++){
        if(r(flake1, flakes2, i)) return true;
        if(l(flake1, flakes2, i)) return true;
    }
    return false;
}

void areEqual(snowFlakesNode *snowFlakes[]){
    snowFlakesNode *node1, *node2;
    for(int i = 0;i < SIZE;i++){
        node1 = snowFlakes[i];
        while (node1 != NULL){
            node2 = node1->next;
            while (node2 != NULL){
                if(isTheyEqual(node1->snowFlakes, node2->snowFlakes)){
                    cout << "Twin integers found." << endl;
                    return;
                }
                node2 = node2->next;
            }
            node1 = node1->next;
        }
    }
    cout << "No two snowflakes are alike." << endl;
}

int main(){

    snowFlakesNode *snow;
    static snowFlakesNode *snowFlakes[SIZE] = {NULL};
    int n, snowCode;
    cin >> n;
    for(int i = 0;i < n;i++){
        snow = new snowFlakesNode;
        if(snow == NULL) break;
        for(int j = 0;j < 6;j++) cin >> snow->snowFlakes[j];
        snowCode = code(snow->snowFlakes);
        snow->next = snowFlakes[snowCode];
        snowFlakes[snowCode] = snow;
    }
    areEqual(snowFlakes);

    return 0;
}