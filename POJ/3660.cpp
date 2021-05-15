#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <climits>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
using namespace std;
typedef double DB;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
const int N=105;
int n,m,in[N],out[N];
bool f[N][N];
void floyd() {
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                f[i][j]|=(f[i][k]&f[k][j]);
}
int main() {
    //freopen("E:/OneDrive/Practice/in.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) {
        int u,v;
        scanf("%d%d",&u,&v);
        f[u][v]=true;
    }
    floyd();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(f[i][j])
                out[i]++,in[j]++;
    int res=0;
    for(int i=1;i<=n;i++) if(out[i]+in[i]==n-1) res++;
    printf("%d\n",res);
    return 0;
}