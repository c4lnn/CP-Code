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
const int N=1e3+5;
int n,a[N][N],c[N],r[N];
string s;
bool check() {
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if((r[i]+c[j]+a[i][j])&1)
                return false;
    return true;
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--) {
        cin>>n;
        for(int i=1;i<=n;i++) {
            cin>>s;
            for(int j=1;j<=n;j++) a[i][j]=s[j-1]-'0';
        }
        for(int i=1;i<=n;i++) {
            cin>>s;
            for(int j=1;j<=n;j++) a[i][j]^=s[j-1]-'0';
        }
        r[1]=0;
        for(int i=1;i<=n;i++) c[i]=a[1][i];
        for(int i=2;i<=n;i++) r[i]=c[1]^a[i][1];
        if(check()) cout<<"YES"<<'\n';
        else {
            r[1]=1;
            for(int i=1;i<=n;i++) c[i]=1^a[1][i];
            for(int i=2;i<=n;i++) r[i]=c[1]^a[i][1];
            if(check()) cout<<"YES"<<'\n';
            else cout<<"NO"<<'\n';
        }
    }
    return 0;
}