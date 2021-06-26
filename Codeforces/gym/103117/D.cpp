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
    int T;cin>>T;
    while(T--) {
        VI a(6);
        for(int i=0;i<6;i++) cin>>a[i];
        LL res=0;
        if(a[4]>=a[0]) res+=a[0],a[4]-=a[0],a[0]=0;
        else res+=a[4],a[0]-=a[4],a[4]=0;
        if(a[5]>=a[1]) res+=a[1],a[5]-=a[1],a[1]=0;
        else res+=a[5],a[1]-=a[5],a[5]=0;
        if(a[3]>=a[2]) res+=a[2],a[3]-=a[2],a[2]=0;
        else res+=a[3],a[2]-=a[3],a[3]=0;
        if(a[3]>=a[0]) a[3]-=a[0],a[0]=0;
        else a[0]-=a[3],a[3]=0;
        if(a[4]>=a[1]) a[4]-=a[1],a[1]=0;
        else a[1]-=a[4],a[4]=0;
        if(a[5]>=a[2]) a[5]-=a[2],a[2]=0;
        else a[2]-=a[5],a[5]=0;
        if(a[5]>=a[0]) res-=a[0],a[5]-=a[0],a[0]=0;
        else res-=a[5],a[0]-=a[5],a[5]=0;
        if(a[3]>=a[1]) res-=a[1],a[3]-=a[1],a[1]=0;
        else res-=a[3],a[1]-=a[3],a[3]=0;
        if(a[4]>=a[2]) res-=a[2],a[4]-=a[2],a[2]=0;
        else res-=a[4],a[2]-=a[4],a[4]=0;
        cout<<res<<'\n';
    }
    return 0;
}