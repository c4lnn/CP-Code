#include<iostream>
using namespace std;
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;

int n,m;
bool st[1<<11];
ll f[12][1<<11];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>n>>m&&n) {
        for(int i=0;i<1<<m;i++) {
            int cnt=0;
            int fg=0;
            for(int j=0;j<m;j++) {
                if(i&(1<<j)) {
                    if(cnt&1) fg=1,cnt=0;
                    if(fg) break;
                }
                else cnt^=1;
            }
            st[i]=fg|cnt?false:true;
        }
        f[0][0]=1;
        for(int i=1;i<=n;i++)
            for(int j=0;j<1<<m;j++) {
                f[i][j]=0;
                for(int k=0;k<1<<m;k++)
                    if(!(k&j)&&st[k|j])
                        f[i][j]+=f[i-1][k];
            }
        cout<<f[n][0]<<endl;
    }
    return 0;
}