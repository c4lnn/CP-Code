#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;

int a[1005],b[1005],c[1005];
int cnt;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    int n;
    while(T--) {
        cin>>n;
        cnt=0;
        for(int i=1;i<=n;i++) c[i]=0;
        for(int i=1;i<=n;i++) {
            cin>>a[i];
            for(int j=1;j<=cnt;j++)
                if(a[i]%b[j]==0) {
                    c[i]=j;
                    break;
                }
            if(!c[i]) {
                for(int j=2;;j++)
                    if(a[i]%j==0) {
                        b[++cnt]=j;
                        c[i]=cnt;
                        break;
                    }
            }
        }
        cout<<cnt<<endl;
        for(int i=1;i<=n;i++) cout<<c[i]<<" ";
        cout<<endl;
    }
    return 0;
}