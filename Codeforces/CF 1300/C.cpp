#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5;

int n;
int a[N];

int main() {
    //freopen("in.txt","in",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int x=1;
    for(int i=30;i>=0;i--) {
        int cnt=0;
        for(int j=1;j<=n;j++)
            if(a[j]&(1<<i)) x=j,cnt++;
        if(cnt==1) break;
    }
    cout<<a[x]<<" ";
    for(int i=1;i<=n;i++) if(i!=x) cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}