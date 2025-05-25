#include<bits/stdc++.h>
using namespace std;
queue<int> ch;

int main(){
	
	int a, b, n, in, ans = 0;
	cin >> a >> b >> n;
	for(int i = 0;i < n;i++){
		cin >> in;
		ch.push(in);
	}
	while(!ch.empty()){
		in = ch.front();
		in %= a + b;
		if(in >= a) ans += b - (in - a);
		ch.pop();
	}
	cout << ans;
	
	return 0;
	
}