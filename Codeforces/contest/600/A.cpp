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
    string s;cin>>s;
    string t="";
    bool f=false;
    vector<string> a,b;
    for(int i=0;i<=SZ(s);i++) {
        if(i==SZ(s)||s[i]==','||s[i]==';') {
            if(SZ(t)&&!f||t=="0") a.PB(t);
            else b.PB(t);
            t="";
            f=false;
        }
        else {
            if(!SZ(t)&&s[i]=='0'||!isdigit(s[i])) f=true;
            t+=s[i];
        }
    }
    if(SZ(a)) {
        cout<<'\"';
        for(int i=0;i<SZ(a);i++) {
            cout<<a[i];
            if(i!=SZ(a)-1) cout<<',';
        }
        cout<<'\"'<<'\n';
    }
    else cout<<'-'<<'\n';
    if(SZ(b)) {
        cout<<'\"';
        for(int i=0;i<SZ(b);i++) {
            cout<<b[i];
            if(i!=SZ(b)-1) cout<<',';
        }
        cout<<'\"'<<'\n';
    }
    else cout<<'-'<<'\n';
    return 0;
}