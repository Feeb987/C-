#include <bits/stdc++.h>

using namespace std;

int lines[100];
int n, m;

void minLine();

int main(){

    cin >> n >> m;
    for(int i = 0;i < n;i++) cin >> lines[i];
    for(int i = 0;i < m;i++) minLine();

    return 0;                           
}                                                                                                                                                                  
    
void minLine(){

    int minPel = 0;
    for(int i = 1;i < n;i++) if(lines[i] <= lines[minPel]) minPel = i;
    cout << lines[minPel]++ << endl;

}