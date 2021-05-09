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
int n,a[105],cnt[105],temp[105];
int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        int res=0;
        memset(cnt,0,sizeof cnt);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),cnt[a[i]]++;
        for(int i=2;i<=100;i++) {
            int sum=0;
            for(int j=1;j<=100;j++) temp[j]=cnt[j];
            for(int j=1;j<=i/2;j++) {
                if(!temp[j]) continue;
                if(j==i-j) sum+=temp[j]/2,temp[j]%=2;
                else {
                    int t=min(temp[j],temp[i-j]);
                    sum+=t;
                    temp[j]-=t,temp[i-j]-=t;
                }
                res=max(res,sum);
            }
        }
        printf("%d\n",res);
    }
    return 0;
}