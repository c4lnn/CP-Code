#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
typedef long long ll;

char s[21][100001];
int cnt[1100000];

int main() {
    //freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;cin>>T;
    while(T--) {
        int n,m,a,b;
        cin>>n>>m>>a>>b;
        for(int i=0;i<1<<n;i++) cnt[i]=0;
        for(int i=1;i<=n;i++) cin>>s[i]+1;
        for(int j=1;j<=m;j++) {
            int t=0;
            for(int i=1;i<=n;i++)
                if(s[i][j]=='*')
                    t|=1<<i-1;
            cnt[t]++;
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<(1<<n);j++)
                if(j&1<<i)
                    cnt[j]+=cnt[j-(1<<i)];
        bool f=false;
        for(int i=0;i<1<<n;i++)
            if(__builtin_popcount(i)<=a&&m-cnt[i]<=b) {
                f=true;
                break;
            }
        if(f==true) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}