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
const int N=1e3+5;
int n,a[N],b[N],w[N];
void update(int x,int v) {
    for(int i=x;i<=n;i+=i&-i) w[i]+=v;
}
int query(int x) {
    int ret=0;
    for(int i=x;i;i-=i&-i) ret+=w[i];
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        int k;cin>>n>>k;
        for(int i=1;i<=n;i++) cin>>a[i];
        if(is_sorted(a+1,a+1+n)) cout<<0<<'\n';
        else if(k==1) cout<<-2<<'\n';
        else if(k==2) {
            int cnt=0,pos=1;
            for(;pos<=n;pos++) if(a[pos]<a[pos-1]) {
                break;
            }
            if(a[n]>a[1]||!is_sorted(a+pos,a+1+n)) cout<<-2<<'\n';
            else {
                cout<<1<<'\n';
                cout<<2<<'\n';
                cout<<0<<' '<<pos-1<<' '<<n<<'\n';
                cout<<2<<' '<<1<<'\n';
            }
        }
        else {
            for(int i=1;i<=n;i++) b[i]=i;
            sort(b+1,b+1+n,[&](int x,int y) {return a[x]<a[y];});
            VI res;
            for(int i=1;i<=n;i++) w[i]=0;
            for(int i=1;i<=n;i++) {
                int pos=query(b[i])+b[i];
                if(pos==n) continue;
                res.PB(pos);
                update(b[i]+1,-1);
            }
            cout<<SZ(res)<<'\n';
            for(auto x:res) {
                if(x==1) {
                    cout<<2<<'\n';
                    cout<<0<<' '<<1<<' '<<n<<'\n';
                    cout<<2<<' '<<1<<'\n';
                }
                else {
                    cout<<3<<'\n';
                    cout<<0<<' '<<x-1<<' '<<x<<' '<<n<<'\n';
                    cout<<1<<' '<<3<<' '<<2<<'\n';
                }
            }
        }
    }
    return 0;
}