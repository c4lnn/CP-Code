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
const int N=1e5+5;
int a[N],q1[N],q2[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) {
        int k;cin>>k;
        LL res=0;
        int l1=1,r1=0,l2=1,r2=0,l=1;
        for(int j=1;j<=n;j++) {
            while(r1>=l1&&a[q1[r1]]>=a[j]) --r1;
            q1[++r1]=j;
            while(r2>=l2&&a[q2[r2]]<=a[j]) --r2;
            q2[++r2]=j;
            while(a[q2[l2]]-a[q1[l1]]>k) {
                res+=n-j+1,++l;
                if(q1[l1]<l) ++l1;
                if(q2[l2]<l) ++l2;
            }
        }
        cout<<res<<'\n';
    }
    return 0;
}