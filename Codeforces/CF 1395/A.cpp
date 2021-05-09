#include<bits/stdc++.h>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
using namespace std;
typedef double DB;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        int a[4];
        for(int i=0;i<4;i++) scanf("%d",&a[i]);
        sort(a,a+3);
        int cnt=0;
        for(int i=0;i<4;i++) if(a[i]&1) cnt++;
        if(cnt<=1||(a[0]>0&&cnt>=3)) puts("Yes");
        else puts("No");
    }
    return 0;
}