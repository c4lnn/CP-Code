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
const int N=2e5+5;
int t[30],tt[30];
char s[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;cin>>n>>k;
    for(int i=0;i<k;i++) t[i]=k-1;
    int i=0;
    s[++i]='a';
    int u=0;
    while(i<n) {
        for(int i=0;i<k;i++) tt[i]=0;
        u=tt[u]++;
        while(i<n) {
            s[++i]=(u+'a');
            while(tt[u]<k&&tt[tt[u]]==k) ++tt[u];
            if(tt[u]==k) break;
            u=tt[u]++;
        }
        if(i<n) s[++i]='a',u=0;
    }
    cout<<s+1<<'\n';
    return 0;
}