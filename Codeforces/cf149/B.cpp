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
string a,b;
VI res;
int get(char c) {
    if(isdigit(c)) return c-'0';
    return c-'A'+10;
}
int main() {
    string s;cin>>s;
    bool f=false;
    for(int i=0;i<SZ(s);i++) {
        if(s[i]==':') {f=true;continue;}
        if(!f) a+=s[i];
        else b+=s[i];
    }
    int mn=0;
    for(int i=0;i<SZ(a);i++) mn=max(mn,get(a[i]));
    for(int i=0;i<SZ(b);i++) mn=max(mn,get(b[i]));
    for(int i=mn+1;i<=60;i++) {
        int t=0,tt=1;
        for(int j=SZ(a)-1;~j;j--) {
            t+=get(a[j])*tt;
            tt*=i;
            if(t>=24) {
                if(!SZ(res)) cout<<0<<'\n';
                else for(int k=0;k<SZ(res);k++) cout<<res[k]<<" \n"[k==SZ(res)-1];
                return 0;
            }
        }
        t=0,tt=1;
        for(int j=SZ(b)-1;~j;j--) {
            t+=get(b[j])*tt;
            tt*=i;
            if(t>=60) {
                if(!SZ(res)) cout<<0<<'\n';
                else for(int k=0;k<SZ(res);k++) cout<<res[k]<<" \n"[k==SZ(res)-1];
                return 0;
            }
        }
        res.PB(i);
    }
    cout<<-1<<'\n';
    return 0;
}