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
const int N=2e5+5;
int n,a[N];
void solve() {
    int l=1,r=n,pre=0;
    vector<char> res;
    while(l<=r) {
        if(a[l]>pre&&a[r]>pre) {
            if(a[l]<a[r]) res.PB('L'),pre=a[l++];
            else if(a[l]>a[r]) res.PB('R'),pre=a[r--];
            else {
                int x=l,y=r;
                int cnt1=0,cnt2=0;
                for(int i=x,t=0;i<=y;i++) {
                    if(a[i]>t) ++cnt1,t=a[i];
                    else break;
                }
                for(int i=y,t=0;i>=x;i--) {
                    if(a[i]>t) ++cnt2,t=a[i];
                    else break;
                }
                if(cnt1>cnt2) {
                    for(int i=x,t=0;i<=y;i++) {
                        if(a[i]>t) res.PB('L'),t=a[i];
                        else break;
                    }
                }
                else {
                    for(int i=y,t=0;i>=x;i--) {
                        if(a[i]>t) res.PB('R'),t=a[i];
                        else break;
                    }
                }
                break;
            }
        }
        else if(a[l]>pre) res.PB('L'),pre=a[l++];
        else if(a[r]>pre) res.PB('R'),pre=a[r--];
        else break;
    }
    cout<<SZ(res)<<'\n';
    for(auto c:res) cout<<c;
    cout<<'\n';
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    solve();
    return 0;
}