#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;

const int N=2e5+5;
int n,k;
char s[N];
int cnt[N][30];
int check(int x,int y) {
    int mx=0;
    int tot=0;
    for(int i=0;i<26;i++) {
        tot+=cnt[x][i]+cnt[y][i];
        mx=max(mx,cnt[x][i]+cnt[y][i]);
    }
    return tot-mx;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--) {
        cin>>n>>k;
        cin>>s+1;
        for(int i=0;i<k;i++)
            for(int j=0;j<26;j++)
                cnt[i][j]=0;
        for(int i=1;i<=n;i++) cnt[i%k][s[i]-'a']++;
        int res=0;
        for(int i=0;i<k;i++) res+=check(i,(n-i+1)%k);
        cout<<res/2<<endl;
    }
    return 0;
}