#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;

const int N=1010;
bool res1[N][N];
bool res2[N][N];
bool res3[N][N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x,y,z,n;
    cin>>x>>y>>z>>n;
    for(int i=1;i<=n;i++) {
        int a,b,c;
        cin>>a>>b>>c;
        res1[a][b]=true;
        res2[b][c]=true;
        res3[a][c]=true;
    }
    for(int i=y;i>=1;i--) {
        for(int j=1;j<=x;j++) {
            if(res1[j][i]) cout<<'x';
            else cout<<'.';
        }
        cout<<" ";
        for(int j=1;j<=z;j++) {
            if(res2[i][j]) cout<<'x';
            else cout<<'.';
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=1;i<=z;i++) {
        for(int j=1;j<=x;j++) {
            if(res3[j][i]) cout<<'x';
            else cout<<'.';
        }
        cout<<endl;
    }
    return 0;
}