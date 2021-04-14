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
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    string s;cin>>s;
    int mx=0,tot=0,cnt=0;
    bool f=false,ff=false;
    for(int i=0;i<n;i++) {
        if(s[i]=='_') {
            if(!f) cnt=0;
            if(f) ff=true;
        }
        else if(s[i]=='(') cnt=0,f=ff=true;
        else if(s[i]==')') f=false;
        else {
            if(!f) mx=max(mx,++cnt);
            else if(ff) ++tot,ff=false;
        }
    }
    cout<<mx<<' '<<tot<<'\n';
    return 0;
}