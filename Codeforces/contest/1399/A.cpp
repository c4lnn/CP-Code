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
int n,a[100];
int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+1+n);
        int f=0;
        for(int i=2;i<=n;i++) {
            if(a[i]==a[i-1]||a[i]-a[i-1]==1) continue;
            else {f=1;break;}
        }
        puts(f?"NO":"YES");
    }
    return 0;
}