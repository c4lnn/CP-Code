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
typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
const int N=2e5+5;
int n,m,k;
int a[N],b[N],tot1[N],tot2[N],tot3[N];
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--) {
        cin>>n>>m>>k;
        for(int i=1;i<=n;i++) tot1[i]=0;
        for(int i=1;i<=m;i++) tot2[i]=tot3[i]=0;
        for(int i=1;i<=k;i++) {
            cin>>a[i];
            ++tot1[a[i]];
        }
        for(int i=1;i<=n;i++) tot1[i]+=tot1[i-1];
        for(int i=1;i<=k;i++) {
            cin>>b[i];
            ++tot2[b[i]];
        }
        LL res=0;
        for(int i=1;i<=k;i++) {
            res+=tot1[n]-tot1[a[i]]-tot2[b[i]]+tot3[b[i]]+1;
            tot3[b[i]]++;
        }
        cout<<res<<'\n';
    }
    return 0;
}