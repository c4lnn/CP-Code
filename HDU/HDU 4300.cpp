#include <bits/stdc++.h>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
using namespace std;
typedef double DB;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
const int N=1e5+5;
const LL HASH_MOD[2]={1000000007,1000000009};
const LL HASH_BASE=13331;
LL ha1[2][N],ha2[2][N],power[2][N];
char a[N],b[N],s1[N],s2[N];
int n;
void init_hash() {
    power[0][0]=power[1][0]=1;
    for(int i=0;i<2;i++)
        for(int j=1;j<=n;j++) {
            ha1[i][j]=(ha1[i][j-1]*HASH_BASE%HASH_MOD[i]+s1[j])%HASH_MOD[i];
            ha2[i][j]=(ha2[i][j-1]*HASH_BASE%HASH_MOD[i]+s2[j])%HASH_MOD[i];
            power[i][j]=power[i][j-1]*HASH_BASE%HASH_MOD[i];
        }
}
pair<LL,LL> get_hash(int l,int r,LL ha[2][N]) {
    pair<LL,LL> res;
    res.FI=(ha[0][r]+HASH_MOD[0]-ha[0][l-1]*power[0][r-l+1]%HASH_MOD[0])%HASH_MOD[0];
    res.SE=(ha[1][r]+HASH_MOD[1]-ha[1][l-1]*power[1][r-l+1]%HASH_MOD[1])%HASH_MOD[1];
    return res;
}
int main() {
    freopen("E:/OneDrive/IO/in.txt","r",stdin);
    int tt;
    scanf("%d",&tt);
    while(tt--) {
        scanf("%s%s",a,s1+1);
        n=strlen(s1+1);
        for(int i=0;i<26;i++) b[a[i]-'a']='a'+i;
        for(int i=1;i<=n;i++) s2[i]=b[s1[i]-'a'];
        init_hash();
        int res=0;
        for(int i=(n+1>>1)+1;i<=n;i++) if(get_hash(1,n-i+1,ha2)==get_hash(i,n,ha1)) {res=i;break;}
        if(!res) res=n+1;
        for(int i=1;i<res;i++) printf("%c",s1[i]);
        for(int i=1;i<res;i++) printf("%c",s2[i]);
        puts("");
    }
    return 0;
}