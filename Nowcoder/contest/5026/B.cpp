#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
//head
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--) {
        int n,m;
        cin>>n>>m;
        if(n>m) swap(n,m);
        int res=0;
        while(2*n<=m) res++,n*=2;
        if(n==m) cout<<res+m<<endl;
        else cout<<res+m+1<<endl;
    }
    return 0;
}