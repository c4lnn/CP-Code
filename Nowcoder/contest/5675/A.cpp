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
const int N=1e6+5;
int a[N];
bool st[N];
void solve() {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) st[i]=false;
    st[1]=true;
    a[1]=1;
    for(int i=2;i<n;i++) {
        int x=0;
        if(!st[a[i-1]*2%n]) x=a[i-1]*2%n;
        else if(!st[a[i-1]*3%n]) x=a[i-1]*3%n;
        if(x) {
            st[x]=true;
            a[i]=x;
        }
        else {puts("-1");return;}
    }
    for(int i=1;i<n;i++) printf("%d ",a[i]);
    puts("");
}
int main() {
    int T;
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}