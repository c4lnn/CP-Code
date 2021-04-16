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
int cnt[30];
VI a;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;cin>>s;
    for(int i=0;i<SZ(s);i++) ++cnt[s[i]-'a'];
    for(int i=0;i<26;i++) if(cnt[i]&1) a.PB(i);
    for(int i=0;i<SZ(a)>>1;i++) {
        ++cnt[a[i]];
        --cnt[a[SZ(a)-i-1]];
    }
    for(int i=0;i<26;i++)
        for(int j=0;j<cnt[i]/2;j++)
            cout<<(char)('a'+i);
    if(SZ(a)&1) cout<<(char)('a'+a[SZ(a)>>1]);
    for(int i=25;~i;i--)
        for(int j=0;j<cnt[i]/2;j++)
            cout<<(char)('a'+i);
    cout<<'\n';
    return 0;
}