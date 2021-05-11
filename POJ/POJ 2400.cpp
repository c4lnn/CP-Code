#include <iostream>
#include <iomanip>
using namespace std;
const int N=20;
int n,t,a[N][N],b[N][N],w[N][N],la[N],lb[N],ma[N],mb[N],vb[N],slk[N],pre[N],mm[N],res;
bool st[N];
int km(int n) {
    for(int i=1;i<=n;i++) {
        la[i]=0xc0c0c0c0;
        lb[i]=ma[i]=mb[i]=0;
        for(int j=1;j<=n;j++) la[i]=max(la[i],w[i][j]);
    }
    for(int i=1;i<=n;i++) {
        for(int j=0;j<=n;j++) vb[j]=pre[j]=0,slk[j]=0x3f3f3f3f;
        int b=0,p=-1;
        for(mb[b]=i;mb[b];b=p) {
            int d=0x3f3f3f3f,a=mb[b];
            vb[b]=1;
            for(int j=1;j<=n;j++)
                if(!vb[j]) {
                    int t=la[a]+lb[j]-w[a][j];
                    if(t<slk[j]) slk[j]=t,pre[j]=b;
                    if(slk[j]<d) d=slk[j],p=j;
                }
            for(int j=0;j<=n;j++) {
                if(vb[j]) la[mb[j]]-=d,lb[j]+=d;
                else slk[j]-=d;
            }
        }
        for(;b;b=pre[b]) mb[b]=mb[pre[b]],ma[mb[b]]=b;
    }
    int res=0;
    for(int i=1;i<=n;i++) res+=w[i][ma[i]];
    return res;
}
void dfs(int x,int sum) {
    if(sum>res) return;
    if(x==n+1) {
        if(sum==res) {
            cout<<"Best Pairing "<<++t<<'\n';
            for(int i=1;i<=n;i++) {
                cout<<"Supervisor "<<i<<" with Employee "<<mm[i]<<'\n';
            }
        }
        return;
    }
    for(int i=1;i<=n;i++) if(!st[i]) {
        st[i]=true;
        mm[x]=i;
        dfs(x+1,sum+a[x][i]-1+b[i][x]-1);
        st[i]=false;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;cin>>T;
    for(int cs=1;cs<=T;cs++) {
        cin>>n;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                int x;cin>>x;
                b[i][x]=j;
            }
        }
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                int x;cin>>x;
                a[i][x]=j;
            }
        }
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                w[i][j]=a[i][j]-1+b[j][i]-1;
                if(w[i][j]>0) w[i][j]=-w[i][j];
            }
        }
        res=-km(n);
        cout<<"Data Set "<<cs<<", Best average difference: "<<fixed<<setprecision(6)<<res/2.0/n<<'\n';
        t=0;
        dfs(1,0);
        cout<<'\n';
    }
    return 0;
}