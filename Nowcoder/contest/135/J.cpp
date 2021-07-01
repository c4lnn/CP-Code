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
int T[]={0,110,220,330,440,550,1001,1111,1221,1331,1441,1551,2002,2112,2222,2332};
int main() {
    int h,m;scanf("%d:%d",&h,&m);
    int pos=lower_bound(T,T+16,h*100+m)-T;
    if(pos==0) cout<<"23:32"<<'\n';
    else cout<<T[pos-1]/100<<':'<<T[pos-1]%100<<'\n';
    pos=upper_bound(T,T+16,h*100+m)-T;
    if(pos==16) cout<<"0:0"<<'\n';
    else cout<<T[pos]/100<<':'<<T[pos]%100<<'\n';
    return 0;
}