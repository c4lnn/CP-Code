#include<iostream>
#include<cstring>

using namespace std;


const int N=210;

int sg[N][N];
bool vis[1456];

int main() {
     //freopen("in.txt","r",stdin);
     ios::sync_with_stdio(false);
     cin.tie(0);
    memset(sg,-1,sizeof sg);
    for(int i=2;i<=N;i++)
        for(int j=2;j<=N;j++) {
            if(sg[i][j]<0) {
                memset(vis,false,sizeof vis);
                for(int k=2;k<=i/2;k++) {
                    vis[sg[k][j]^sg[i-k][j]]=true;
                }
                for(int k=2;k<=j/2;k++) {
                    vis[sg[i][k]^sg[i][j-k]]=true;
                }
                for(int k=0;;k++) if(!vis[k]) {sg[i][j]=sg[j][i]=k;break;}
            }
        }
    int n,m;
    while(cin>>n>>m) {
        if(sg[n][m]) cout<<"WIN"<<endl;
        else cout<<"LOSE"<<endl;
    }
     return 0;
}