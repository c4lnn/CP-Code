#include<bits/stdc++.h>

using namespace std;

int main() {
    //freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,d;
    while(cin>>n>>d) {
        cout<<n;
        for(int i=1;i<=d;i++) cout<<"00";
        cout<<endl;
    }
    return 0;
}