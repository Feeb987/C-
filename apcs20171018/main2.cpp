#include<iostream>
#include<string>
using namespace std;

int sub(string str, int k, bool bs, int index);

int main(){

    int k, ans = 0, ians = 0;
    string str;
    cin >> k >> str;
    for(int i = 0;i < str.length();i++){
        ans = max(ians, sub(str, k, ((str[i] <= 'Z')? true:false), i));
        ians = ans;
    }
    cout << ans;

    return 0;

}

int sub(string str, int k, bool bs, int index){

    int count = 0, ans = 0;
    while (1){
        if(index >= str.length()) break;
        for(int i = index;i < k+index;i++){
            if((str[i] <= 'Z') == bs && i < str.length()){
                count++;
            }
            else{
                return ans;
            }
        }
        bs = !bs;
        index += count;
        ans += count;
        count = 0;
    }
    

    return ans;

}