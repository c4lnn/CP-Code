#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;
//head
const int N=2e5+4;
int a[N],b[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    b[1]=1;
    while(T--) {
        int n;
        cin>>n;
        bool f=0;
        cin>>a[1];
        int t=0;
        for(int i=2;i<=n;i++) {
            cin>>a[i];
            if(a[i]==a[i-1]) t=i;
            if(i<=n) {
                if(a[i]==a[i-1]) b[i]=b[i-1];
                else f=1,b[i]=3-b[i-1];
            }
            if(i==n) {
              if(a[i]!=a[1]&&b[i]==b[1]) b[i]=3;
            }
        }
        if(b[n]==3&&t) {
            b[t]=3-b[t-1];
            for(int i=t+1;i<=n;i++) {
                if(a[i]==a[i-1]) b[i]=b[i-1];
                else b[i]=3-b[i-1];
            }
        }
        if(b[n]==3) cout<<3<<endl;
        else if(f) cout<<2<<endl;
        else cout<<1<<endl;
        for(int i=1;i<=n;i++) cout<<b[i]<<" ";
        cout<<endl;
    }
    return 0;
}