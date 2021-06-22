#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;

const int N=510;
int n,m;
int a[N],b[N];
int cnt[N+N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<=n;i++) cin>>a[i];
    for(int i=0;i<=m;i++) cin>>b[i];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++) {
            cnt[i+j]+=a[i]*b[j];
        }
    for(int i=0;i<=n+m;i++) cout<<cnt[i]<<" ";
    cout<<endl;
    return 0;
}