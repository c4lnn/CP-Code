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
    string s;
    cin>>s;
    int t=0,a=0,b=0;
    for(;s[t];t++) {
        if(s[t]=='0') ++a;
        else if(s[t]=='1') ++b;
        else break;
    }
    for(int i=0;i<a;i++) cout<<0;
    for(int i=0;i<b;i++) cout<<1;
    for(int i=t;s[i];i++) if(s[i]=='1') cout<<1;
    for(int i=t;s[i];i++) if(s[i]!='1') cout<<s[i];
    cout<<'\n';
    return 0;
}