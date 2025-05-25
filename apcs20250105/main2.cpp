#include<bits/stdc++.h>
using namespace std;
queue<int> q;

int main(){

	string str;
	int k, in;
	cin >> str >> k;
	int len = str.length();
	for(int i = 0;i < k;i++){
		cin >> in;
		q.push(in);
	}
	while(!q.empty()){
		switch(q.front()){
			case 0:
				for(int i = 0;i < len;i+=2){
					swap(str[i], str[i+1]);
				}
				break;
			case 1:
				for(int i = 0;i < len;i+=2){
					if(str[i] > str[i+1]) swap(str[i], str[i+1]);
				}
				break;
			case 2:
				int h = len / 2, index = 0;
				if (len % 2 == 1) h++;
                string sub1 = str.substr(0, h), sub2 = str.substr(h);
                str = "";
                for(int i = 0; i < len; i += 2) {
                    str += sub1[index];
                    str += sub2[index++];
                }
				break;
		}
		q.pop();	
	}
	cout << str;

	return 0;

}