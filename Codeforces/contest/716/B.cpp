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
const int N=5e4+5;
char s[N];
int cnt[N][30];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>s+1;
    int n=strlen(s+1);
    for(int i=1;i<=n;i++) {
        for(int j=0;j<=26;j++) cnt[i][j]=cnt[i-1][j];
        if(s[i]=='?') ++cnt[i][26];
        else ++cnt[i][s[i]-'A'];
        if(i<26) continue;
        int t=0;
        for(int j=0;j<26;j++) if(cnt[i][j]-cnt[i-26][j]>0) ++t;
        if(t+cnt[i][26]-cnt[i-26][26]==26) {
            VI v;
            for(int j=0;j<26;j++) if(cnt[i][j]-cnt[i-26][j]<=0) v.PB(j);
            for(int j=i-25;j<=i;j++) if(s[j]=='?') {
                s[j]=char(v[SZ(v)-1]+'A');
                v.pop_back();
            }
            for(int j=1;j<=n;j++) {
                if(s[j]=='?') cout<<'A';
                else cout<<s[j];
            }
            cout<<'\n';
            return 0;
        }
    }
    cout<<-1<<'\n';
    return 0;
}