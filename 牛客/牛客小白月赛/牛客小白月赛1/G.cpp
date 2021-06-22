#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;

const int N=810;
int a[N][N];
int f[N<<1][N<<1];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int k=1;k<=n;k++)
        for(int i=k,j=1;i>=1;i--,j++)
            cin>>a[i][j];
    int x=n,y=1;
    for(int k=1;k<=n+n-3;k++) {
        if(k&1) y++;
        else x++;
        for(int i=x,j=y,t=(k&1?n-1:n);t;i--,j++) {
            cin>>a[i][j];
            t--;
        }
    }
    for(int k=n;k<=n+n-1;k++) {
        for(int i=n+n-1,j=k;j<=n+n-1;i--,j++) {
            cin>>a[i][j];
        }
    }
    memset(f,-0x3f,sizeof f);
    for(int i=1;i<=n+n-1;i++)
        for(int j=1;j<=n+n-1;j++) {
            if(i==1&&j==1){f[i][j]=a[i][j];continue;}
            f[i][j]=max(f[i-1][j-1],max(f[i-1][j],f[i][j-1]))+a[i][j];

        }
    cout<<f[n+n-1][n+n-1]<<endl;
    return 0;
}