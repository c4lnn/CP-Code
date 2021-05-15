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
        int n;cin>>n;
        VI a(n+1);
        int pos=-1;
        for(int i=2;i<=n;i+=2) {
            cout<<"? 2 "<<i-1<<' '<<i<<' '<<1<<endl;
            int ret;cin>>ret;
            if(ret==1) pos=i-1,a[i-1]=1;
            else if(ret==2) {
                cout<<"? 2 "<<i<<' '<<i-1<<' '<<1<<endl;
                int ret;cin>>ret;
                if(ret==1) pos=i,a[i]=1;
            }
            if(pos!=-1) break;
        }
        if(pos==-1) pos=n,a[n]=1;
        for(int i=1;i<=n;i++) if(i!=pos) {
            cout<<"? 1 "<<pos<<' '<<i<<' '<<n-1<<endl;
            int ret;cin>>ret;
            a[i]=ret;
        }
        cout<<"! ";
        for(int i=1;i<=n;i++) cout<<a[i]<<' ';
        cout<<endl;
    }
    return 0;
}