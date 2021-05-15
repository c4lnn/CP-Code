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
const int N=30;
int n,match[N],a[N],b[N];
bool f[N][N],st[N];
int get(string s) {
    int x;
    if(s[0]>='2'&&s[0]<='9') x=s[0]-'0';
    else if(s[0]=='T') x=10;
    else if(s[0]=='J') x=11;
    else if(s[0]=='Q') x=12;
    else if(s[0]=='K') x=13;
    else if(s[0]=='A') x=14;
    x*=4;
    if(s[1]=='C') x-=3;
    else if(s[1]=='D') x-=2;
    else if(s[1]=='S') x--;
    return x;
}
bool dfs(int u) {
    for(int v=1;v<=n;v++) {
        if(!f[u][v]||st[v]) continue;
        st[v]=true;
        if(match[v]==-1||dfs(match[v])) {
            match[v]=u;
            return true;
        }
    }
    return false;
}
int main() {
    //freopen("E:/OneDrive/Practice/in.txt","r",stdin);
    int tt;
    scanf("%d",&tt);
    while(tt--) {
        scanf("%d",&n);
        string s;
        for(int i=1;i<=n;i++) {
            cin>>s;
            a[i]=get(s);
        }
        for(int i=1;i<=n;i++) {
            cin>>s;
            b[i]=get(s);
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                f[i][j]=false;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(b[i]>a[j])
                    f[i][j]=true;
        int res=0;
        for(int i=1;i<=n;i++) match[i]=-1;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) st[j]=false;
            if(dfs(i)) res++;
        }
        printf("%d\n",res);
    }
    return 0;
}