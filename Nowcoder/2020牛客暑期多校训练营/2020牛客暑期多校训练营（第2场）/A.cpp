#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int M=1e6+5;
const long long MOD=998244353;
const long long HASH_BASE=131;
const long long HASH_MOD[2]={1000173169,1000000007};
string s[N];
long long power[M][2],ha[M][2],res[M],ans;
int nxt[M];
map<pair<long long,long long>,int>mp;
void init() {
    power[0][0]=power[0][1]=1;
    for(int i=1;i<M;i++)
        for(int j=0;j<2;j++) {
        power[i][j]=power[i-1][j]*HASH_BASE%HASH_MOD[j];
    }
}
void init_hash(string &s) {
    int len=s.length();
    ha[len][0]=ha[len][1]=0;
    for(int i=len-1;i>=0;i--) {
        for(int j=0;j<2;j++)
            ha[i][j]=(s[i]*power[len-i-1][j]%HASH_MOD[j]+ha[i+1][j])%HASH_MOD[j];
        mp[make_pair(ha[i][0],ha[i][1])]++;
    }
}
void kmp(string &s) {
    int len=s.length();
    int i=0,j=-1;
    nxt[0]=-1;
    while(i<len) {
        if(j==-1||s[i]==s[j]) i++,j++,nxt[i]=j;
        else j=nxt[j];
    }
}
void cal(string &s) {
    int len=s.length();
    for(int i=0;i<len;i++) {
        for(int j=0;j<2;j++) {
            if(i==0) ha[i][j]=s[i];
            else ha[i][j]=(ha[i-1][j]*HASH_BASE%HASH_MOD[j]+s[i])%HASH_MOD[j];
        }
        res[i]=mp[make_pair(ha[i][0],ha[i][1])];
    }
    kmp(s);
    for(int i=0;i<len;i++) if(nxt[i+1]>0) res[nxt[i+1]-1]-=res[i];
    for(int i=0;i<len;i++) if(res[i]>0) ans=(ans+1ll*(i+1)*res[i]%MOD*(i+1)%MOD)%MOD;
}
int main() {
    init();
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        cin>>s[i];
        init_hash(s[i]);
    }
    for(int i=1;i<=n;i++) cal(s[i]);
    printf("%lld\n",ans);
    return 0;
}