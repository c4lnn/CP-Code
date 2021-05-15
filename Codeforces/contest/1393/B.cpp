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
int b[100005],st[10],tot[100005];
int main() {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        int x;
        scanf("%d",&x);
        tot[x]++;
        if(tot[x]==2) st[2]++;
        else if(tot[x]==4) st[2]--,st[4]++;
        else if(tot[x]==6) st[4]--,st[6]++;
        else if(tot[x]==8) st[6]--,st[8]++;
    }
    int m;
    scanf("%d",&m);
    for(int i=1;i<=m;i++) {
        char s[3];
        scanf("%s",s);
        int x;
        scanf("%d",&x);
        if(s[0]=='+') {
            tot[x]++;
            if(tot[x]==2) st[2]++;
            else if(tot[x]==4) st[2]--,st[4]++;
            else if(tot[x]==6) st[4]--,st[6]++;
            else if(tot[x]==8) st[6]--,st[8]++;
        }
        else {
            tot[x]--;
            if(tot[x]==1) st[2]--;
            else if(tot[x]==3) st[4]--,st[2]++;
            else if(tot[x]==5) st[6]--,st[4]++;
            else if(tot[x]==7) st[8]--,st[6]++;
        }
        if(st[4]>=2||st[6]>=2||st[8]) puts("YES");
        else if(st[2]>=2&&st[4]||st[2]&&st[6]||st[4]&&st[6]) puts("YES");
        else puts("NO");
    }
    return 0;
}