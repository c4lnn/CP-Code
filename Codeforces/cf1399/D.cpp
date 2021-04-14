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
const int N=2e5+5;
int n,vis[N];
char s[N];
set<int> a,b;
int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        scanf("%s",s+1);
        a.clear(),b.clear();
        for(int i=1;i<=n;i++) {
            if(s[i]=='0') a.insert(i);
            else b.insert(i);
        }
        int cnt=0;
        for(int i=1;i<=n;i++) vis[i]=0;
        for(int i=1;i<=n;i++) {
            if(vis[i]) continue;
            vis[i]=++cnt;
            for(int j=(s[i]=='0'?0:1),t=i;;j^=1) {
                if(j==0) {
                    auto pos=b.lower_bound(t);
                    if(pos==b.end()) break;
                    vis[*pos]=cnt;
                    t=*pos;
                    b.erase(pos);
                }
                else {
                    auto pos=a.lower_bound(t);
                    if(pos==a.end()) break;
                    vis[*pos]=cnt;
                    t=*pos;
                    a.erase(pos);
                }
            }
        }
        printf("%d\n",cnt);
        for(int i=1;i<=n;i++) printf("%d ",vis[i]);
        puts("");
    }
    return 0;
}