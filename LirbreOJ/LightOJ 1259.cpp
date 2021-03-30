#include <bits/stdc++.h>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
#define EB emplace_back
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
const int N=1e7+5;
int n;
bool st[N];
VI p;
void get_prime() {
    for(int i=2;i<=10000000;i++) {
        if(st[i]) continue;
        p.PB(i);
        for(int j=i*2;j<=10000000;j+=i) st[j]=true;
    }
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    get_prime();
    int tt;
    scanf("%d",&tt);
    for(int cs=1;cs<=tt;cs++) {
        scanf("%d",&n);
        int sum=0;
        for(auto x:p) {
            if(n-x<x) break;
            if(!st[n-x]) sum++;
        }
        printf("Case %d: %d\n",cs,sum);
    }
    return 0;
}