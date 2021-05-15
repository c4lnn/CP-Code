#include<iostream>
#include<cstring>

using namespace std;

const int N=1e5+5;

int n,m;
int a[N];
int c[N];
bool f[N];
int used[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>n>>m&&n&&m) {
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) cin>>c[i];
        memset(f,false,sizeof f);
        f[0]=true;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) used[j]=0;
            for(int j=a[i];j<=m;j++) {
                if(f[j]==false&&f[j-a[i]]==true&&used[j-a[i]]<c[i]) {
                    f[j]=true;
                    used[j]=used[j-a[i]]+1;
                }
            }
        }
        int ans=0;
        for(int i=1;i<=m;i++) {
            if(f[i]==true) {
                ans++;
            }   
        }
        cout<<ans<<endl;
    } 
    return 0;
}