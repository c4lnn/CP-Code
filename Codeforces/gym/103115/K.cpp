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
typedef vector<LL> VLL;
typedef vector<PII> VPII;
// head
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    string s;cin>>s;
    string t1=s,t2=s;
    int a,b,c;cin>>a>>b>>c;
    --a,--b;
    for(int i=0;i<c;i++) t1[b+i]=t1[a+i];
    for(int i=0;i<c;i++) t2[b+i]=s[a+i];
    cout<<t1<<'\n';
    cout<<t2<<'\n';
    return 0;
}