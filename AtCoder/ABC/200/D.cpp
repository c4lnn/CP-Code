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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    VI a(n),s[200];
    for(int i=0;i<n;i++) cin>>a[i];
    int lim=min(n,8);
    for(int i=0;i<1<<lim;i++) {
        VI t;
        int sum=0;
        for(int j=0;j<lim;j++) if(i&(1<<j)) {
            t.PB(j+1);
            sum=(sum+a[j])%200;
        }
        if(SZ(s[sum])) {
            cout<<"YES"<<'\n';
            cout<<SZ(s[sum])<<' ';
            for(int j=0;j<SZ(s[sum]);j++) cout<<s[sum][j]<<" \n"[j==SZ(s[sum])-1];
            cout<<SZ(t)<<' ';
            for(int j=0;j<SZ(t);j++) cout<<t[j]<<" \n"[j==SZ(t)-1];
            return 0;
        }
        else s[sum]=t;
    }
    cout<<"NO"<<'\n';
    return 0;
}