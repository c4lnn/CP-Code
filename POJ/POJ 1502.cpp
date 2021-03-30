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
int n,w[N][N],dist[N];
bool st[N];
int get(const string &s) {
    if(s[0]=='x') return 0x3f3f3f3f;
    int res=0;
    for(int i=0;i<s.length();i++) {
        res*=10;
        res+=s[i]-'0';
    }
    return res;
}
void dijkstra() {
    for(int i=2;i<=n;i++) dist[i]=0x3f3f3f3f;
    priority_queue<PII,VPII,greater<PII> > q;
    q.push(MP(0,1));
    while(SZ(q)) {
        int u=q.top().SE;
        q.pop();
        if(st[u]) continue;
        st[u]=true;
        for(int v=1;v<=n;v++) {
            if(dist[v]>dist[u]+w[u][v]) {
                dist[v]=dist[u]+w[u][v];
                if(!st[v]) q.push(MP(dist[v],v));
            }
        }
    }
}
int main() {
    //freopen("E:/OneDrive/Practice/in.txt","r",stdin);
    scanf("%d",&n);
    string s;
    for(int i=2;i<=n;i++)
        for(int j=1;j<i;j++) {
            cin>>s;
            w[i][j]=w[j][i]=get(s);
        }
    dijkstra();
    int res=0;
    for(int i=2;i<=n;i++) res=max(res,dist[i]);
    printf("%d\n",res);
    return 0;
}