#include<bits/stdc++.h>

using namespace std;

int main() {
    //freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n,m,r,c;
    while(cin>>n>>m>>r>>c) {
        cout<<(n-r)*(m-c)<<endl;
    }
    return 0;
}