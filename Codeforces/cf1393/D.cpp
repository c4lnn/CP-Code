#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
//head
const int N=2005;
int n,m,dp[N][N],res;
char s[N][N];
bool valid(int x,int y) {
    if(x>=1&&x<=n&&y>=1&&y<=m) return true;
    return false;
}
int judge(int x,int y,char c) {
    if(!valid(x,y)) return 0;
    if(s[x][y]!=c) return 0;
    return dp[x][y];
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) {
            char c=s[i][j];
            int now=judge(i-1,j-1,c);
            now=min(now,judge(i-1,j,c));
            now=min(now,judge(i-1,j+1,c));
            now=min(now,judge(i-2,j,c));
            now++;
            dp[i][j]=now;
            res+=now;
        }
    printf("%d\n",res);
    return 0;
}