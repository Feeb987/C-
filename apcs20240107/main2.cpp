#include<iostream>
#include<map>
using namespace std;

int main(){
	
	map<char, int> app;
	int m, n, k, rW = 0;
	int to[6][2] = {{0, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 0}, {-1, -1}};
	cin >> m >> n >> k;
	int x = 0, y = m - 1, w;
	string home[m], read;
	for(int i = 0;i < m;i++){
		cin >> home[i];
	}
	for(int i = 0;i < k;i++){
		cin >> w;
		if((x + to[w][0] < n && x + to[w][0] >= 0 ) && (y + to[w][1] < m && y + to[w][1] >= 0)){
			x += to[w][0];y += to[w][1];
			read += string(1, home[y][x]);
		}
		else{
			read += home[y][x];
		}
		if(app[home[y][x]] == 0) rW++;
		app[home[y][x]]++;
	}
	cout << read << endl << rW;
	
	return 0;
	
}
