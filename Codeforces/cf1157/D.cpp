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
    LL n,k;
    cin>>n>>k;
    LL sum=k*(k+1)/2;
    if(n-sum<0||n==4&&k==2||n==8&&k==3) return cout<<"NO"<<'\n',0;
    n-=sum;
    vector<LL> a(k+1);
    for(int i=1;i<=k;i++) a[i]=i+n/k;
    a[k]+=n%k;
    if(k!=1&&n==k-1) {
        ++a[k-1];
        --a[k];
    }
    cout<<"YES"<<'\n';
    for(int i=1;i<=k;i++) cout<<a[i]<<" \n"[i==k];
    return 0;
}