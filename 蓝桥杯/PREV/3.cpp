#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
using namespace std;
typedef double DB;
typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
// head
int n,power[10],pre[10],a[10],res;
bool st[10];
void dfs(int x) {
    if(x==10) {
        for(int i=1;i<=9;i++) pre[i]=pre[i-1]*10+a[i];
        for(int i=8;i>=1;i--) {
            for(int j=i-1;j>=1;j--) if((pre[i]-pre[j]*power[i-j])%(pre[9]%power[9-i])==0) {
                if(pre[j]+(pre[i]-pre[j]*power[i-j])/(pre[9]%power[9-i])==n) {
                    ++res;
                }
            }
        }
        return;
    }
    for(int i=1;i<=9;i++) if(!st[i]) {
        st[i]=true;
        a[x]=i;
        dfs(x+1);
        st[i]=false;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    power[0]=1;
    for(int i=1;i<=9;i++) power[i]=power[i-1]*10;
    cin>>n;
    dfs(1);
    cout<<res<<'\n';
    return 0;
}