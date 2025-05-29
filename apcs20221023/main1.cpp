#include<bits/stdc++.h>

using namespace std;

int main(){
	
	int n, t, s, max = -10, maxt, f = 0, ans;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> t >> s;
		if(s > max){
			max = s;
			maxt = t;
		}
		if(s == -1) f++;
	}
	ans = max - n - f*2;
	if(ans>0) cout << ans << " " << maxt;
	else cout << 0 << " " << maxt;
	
	return 0;
	
}
