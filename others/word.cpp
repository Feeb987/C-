#include<bits/stdc++.h>

using namespace std;

struct Word{
    string word;
    struct Word *next;
};

void isTheyEqual(Word *wordArr[]);

bool isEqual(string str, Word *wordArr[], int len);

int HashFun(string str);

int minLen = INT16_MAX, maxLen = INT16_MIN;

int main(){

    Word *wordArr[100] = {NULL};
    string input, tem = "";
    getline(cin, input);
    for(char str : input){
        if(str == ' '){
            Word *word = new Word;
            int key = HashFun(tem);
            word->word = tem;
            word->next = wordArr[key];
            wordArr[key] = word;
            minLen = min(key, minLen);
            maxLen = max(key+1, maxLen);
            tem.clear();
        }
        else tem += str;
    }
    if(!tem.empty()){
        Word *word = new Word;
        word->word = tem;
        word->next = wordArr[tem.length()];
        wordArr[tem.length()] = word;
    }
    isTheyEqual(wordArr);

    return 0;
}

void isTheyEqual(Word *wordArr[]){
    for(int i = 1;i < maxLen;i++){
        Word *node = wordArr[i];
        while(node != NULL){
            int len = node->word.length();
            if(isEqual(node->word, wordArr, len) && len >= minLen * 2){
                cout << node->word << endl;
            }
            node = node->next;
        }
    }
}

bool isEqual(string str, Word *wordArr[], int len){
    for(int i = 1;i < len;i++){
        int a = len - i;
        Word *node1 = wordArr[i];
        while(node1 != NULL){
            Word *node2 = wordArr[a];
            while(node2 != NULL){
                if(node1->word + node2->word == str || node2->word + node1->word == str) return true;
                node2 = node2->next;
            }
            node1 = node1->next;
        }
    }
    return false;
}

int HashFun(string str){
    return str.length();
}
/*
as sd df asdf sddf
*/