#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
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
    cin.tie(0);
    string s,t;cin>>s>>t;
    VI a(SZ(s));
    for(int i=0;i<SZ(s);i++) a[i]=s[i]!=t[i];
    int pos=-1,res=0;
    for(int i=SZ(s)-1;~i;i--) if(a[i]) {
        if(pos!=-1) res+=pos-i,pos=-1;
        else pos=i;
    }
    cout<<res<<'\n';
    return 0;
}