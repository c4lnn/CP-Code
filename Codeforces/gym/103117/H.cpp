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
#ifdef DEBUG
    freopen("E:/IO/data.in","r",stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    for(int i=1;i<=n;i++) {
        string s;cin>>s;
        if(s=="ikimasu") cout<<"itte"<<'\n';
        else if(SZ(s)>=7&&s.substr(SZ(s)-7,7)=="shimasu") cout<<s.substr(0,SZ(s)-7)<<"shite"<<'\n';
        else if(SZ(s)>=7&&s.substr(SZ(s)-7,7)=="chimasu") cout<<s.substr(0,SZ(s)-7)<<"tte"<<'\n';
        else if(SZ(s)>=6&&s.substr(SZ(s)-6,6)=="rimasu") cout<<s.substr(0,SZ(s)-6)<<"tte"<<'\n';
        else if(SZ(s)>=6&&s.substr(SZ(s)-6,6)=="mimasu") cout<<s.substr(0,SZ(s)-6)<<"nde"<<'\n';
        else if(SZ(s)>=6&&s.substr(SZ(s)-6,6)=="bimasu") cout<<s.substr(0,SZ(s)-6)<<"nde"<<'\n';
        else if(SZ(s)>=6&&s.substr(SZ(s)-6,6)=="nimasu") cout<<s.substr(0,SZ(s)-6)<<"nde"<<'\n';
        else if(SZ(s)>=6&&s.substr(SZ(s)-6,6)=="kimasu") cout<<s.substr(0,SZ(s)-6)<<"ite"<<'\n';
        else if(SZ(s)>=6&&s.substr(SZ(s)-6,6)=="gimasu") cout<<s.substr(0,SZ(s)-6)<<"ide"<<'\n';
    }
    return 0;
}