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
const int N=1e5+5;
int id[N],tot[N];
int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        int n;
        scanf("%d",&n);
        int cnt=0;
        memset(id,0,sizeof id);
        for(int i=1;i<=n;i++) {
            int x;
            scanf("%d",&x);
            if(!id[x]) id[x]=++cnt;
            tot[id[x]]++;
        }
        sort(tot+1,tot+1+cnt);
        int mx=tot[cnt]-1;
        int res=0;
        int sum=0;
        for(int i=1;i<=cnt;i++) {
            if(tot[i]<=mx) sum+=tot[i];
            else res++;
        }
        printf("%d\n",res+sum/mx-1);
        for(int i=1;i<=cnt;i++) tot[i]=0;
    }
    return 0;
}