#include<bits/stdc++.h>
using namespace std;
queue<int> num;

int sub(int round);

int main(){

    string in;
    cin >> in;
    for(int i = 0;i < in.size();i++){
        if(in[i] == 'T') num.push((int(in[i+1])-48) * 10 + (int(in[i+2])-48));
        else if(in[i] == 'L') num.push(int(in[i+1])-48);
        else if(in[i] == 'E') num.push(-1);
    }
    cout << sub(1);

    return 0;

}

int sub(int round){
    
    num.pop();
    int sum = 0, head = num.front(), last = num.front();
    while(!num.empty() || num.front() == -1){
        if(num.front() > 9){
            sum += abs(last - num.front());
            last = num.front();
            num.pop();
        }
        else if(num.front() < 10 && num.front() > 0){
            sum += sub(last + num.front());
        }
        else{
            sum = (sum + abs(last - head));
            return sum;
        }
    }

    return sum;

}

//T10T15T23T23T22T22T44 36
//T10L2T15T22L2T15ET23ET44 78