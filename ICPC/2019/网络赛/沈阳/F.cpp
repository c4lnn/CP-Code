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
const int N=5e5+5;
int n,k,a[N];
bool check1(int mid) {
    LL ret=0;
    for(int i=n;a[i]>mid;i--) ret+=a[i]-mid;
    return ret<=k;
}
bool check2(int mid) {
    LL ret=0;
    for(int i=1;a[i]<mid;i++) ret+=mid-a[i];
    return ret<=k;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(cin>>n>>k) {
        LL sum=0;
        for(int i=1;i<=n;i++) {
            cin>>a[i];
            sum+=a[i];
        }
        sort(a+1,a+1+n);
        int ll,rr;
        if(sum%n==0) ll=rr=sum/n;
        else ll=sum/n,rr=ll+1;
        int l=rr,r=a[n];
        while(l<r) {
            int mid=l+r>>1;
            if(check1(mid)) r=mid;
            else l=mid+1;
        }
        int res=l;
        l=a[1],r=ll;
        while(l<r) {
            int mid=l+r+1>>1;
            if(check2(mid)) l=mid;
            else r=mid-1;
        }
        cout<<res-l<<'\n';
    }
    return 0;
}