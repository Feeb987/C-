#include<iostream>
#include<set>
using namespace std;
set<int> st;

int main(){

    int n, h1, h2, m1, m2;
    cin >> n >> m1 >> m2 >> h1 >> h2;
    m1 *= m1;m2 *= m2;
    int d, count;
    for(int i = 0;i < n;i++){
        cin >> d;
        count = 0;
        if(h1 >0){
            if(d / m1 > h1){
                count += h1;
                d -= h1*m1;
                h1 = 0;
                int tem = d / m2;
                if(tem >= h2){
                    st.insert(count+h2);
                    h2 = 0;
                }
                else{
                    h2 -= tem;
                    st.insert(count+tem);
                }
            }
            else{
                count += d / m1;
                h1 -= count;
                st.insert(count);
            }
        }
        else if(h2 > 0){
            if(d / m2 > h2){
                st.insert(h2);
                h2 = 0;
            }
            else{
                count = d / m2;
                h2 -= count;
                st.insert(count);
            }
       }
    }
    cout << *st.rbegin();

    return 0;

}