#include<bits/stdc++.h>

using namespace std;

int main() {
    //freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int mn=INT_MAX,mx=INT_MIN;
    for(int i=1;i<=n;i++) {
        int a;
        cin>>a;
        mn=min(mn,a);
        mx=max(mx,a);
    }
    cout<<mx-mn<<endl;
    return 0;
}