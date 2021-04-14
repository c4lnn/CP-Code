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
const int N=1005;
int n;
bool st[N];
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    scanf("%d",&n);
    st[0]=true;
    for(int k=1,j=0;k<=n;k++) {
        for(int i=1;i<=n;i++) {
            st[j=(j+i)%n]=true;
        }
    }
    bool f=false;
    for(int i=0;i<n;i++) if(!st[i]) {f=true;break;}
    puts(f?"NO":"YES");
    return 0;
}