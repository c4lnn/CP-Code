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
//head
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    VI a(1<<n),b,c;
    for(int i=0;i<1<<n;i++) cin>>a[i],b.PB(i+1);
    if(SZ(b)!=2) {
        for(int i=0;i<n-1;i++) {
            for(int j=0;j<SZ(b)-1;j+=2) {
                c.PB(a[b[j]-1]>a[b[j+1]-1]?b[j]:b[j+1]);
            }
            b.clear();
            swap(b,c);
        }
    }
    cout<<(a[b[0]-1]<a[b[1]-1]?b[0]:b[1])<<'\n';
    return 0;
}