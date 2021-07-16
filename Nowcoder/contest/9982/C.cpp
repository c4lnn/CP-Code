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
int n,l,tot[26];
string s;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--) {
        cin>>n>>l>>s;
        int d=0;
        for(int i=l;i<n;i+=l) d=__gcd(d,n-i);
        for(int i=0;i<d;i++) {
            memset(tot,0,sizeof tot);
            int mx=0;
            for(int j=i;j<n;j+=d) ++tot[s[j]-'a'];
            for(int j=0;j<26;j++) if(tot[j]>tot[mx]) mx=j;
            for(int j=i;j<n;j+=d) s[j]=mx+'a';
        }
        cout<<s<<'\n';
    }
    return 0;
}