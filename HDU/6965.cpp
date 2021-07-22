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
// head
const int MOD=1e9+7;
const int N=1e5+5;
bool f[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        int n;cin>>n;
        for(int i=0;i<n;i++) f[i]=false;
        string s;cin>>s;
        char l,r;
        for(int i=0;i<n;i++) {
            if(i==0) l=r=s[i];
            else {
                if(s[i]<=l) {
                    l=s[i];
                    if(r==s[i]) f[i]=true;
                }
                else r=s[i];
            }
        }
        LL res=1;
        for(int i=n-1;~i;i--) if(f[i]) res=res*2%MOD;
        cout<<res<<'\n';
    }
    return 0;
}