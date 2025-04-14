#include<bits/stdc++.h>

using namespace std;

struct Word{
    string word;
    struct Word *next;
};

void isTheyEqual(Word *wordArr[]);

bool isEqual(string str, Word *wordArr[], int len);

int main(){

    Word *wordArr[100] = {NULL};
    string input, tem = "";
    getline(cin, input);
    for(char str : input){
        if(str == ' '){
            Word *word = new Word;
            word->word = tem;
            word->next = wordArr[tem.length()];
            wordArr[tem.length()] = word;
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
    for(int i = 1;i < 100;i++){
        Word *node = wordArr[i];
        while(node != NULL){
            //cout << node->word << ":" << endl;
            int len = node->word.length();
            if(isEqual(node->word, wordArr, len)){
                //cout << "2" << endl;
                cout << node->word << endl;
            }
            node = node->next;
        }
    }
}

bool isEqual(string str, Word *wordArr[], int len){
    // cout << str << ":" << endl;
    for(int i = 1;i < len;i++){
        int a = len - i;
        Word *node1 = wordArr[i];
        while(node1 != NULL){
            Word *node2 = wordArr[a];
            while(node2 != NULL){
                if(node1->word + node2->word == str || node2->word + node1->word == str) return true;
                //cout << node1->word << " " << node2->word << endl;
                node2 = node2->next;
            }
            node1 = node1->next;
        }
    }
    return false;
}
/*
as sd df asdf sddf
*/