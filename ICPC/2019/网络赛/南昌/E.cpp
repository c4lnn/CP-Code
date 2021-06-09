#include<bits/stdc++.h>
using namespace std;
int a[40000001];
int main() {
    int T;
    scanf("%d",&T);
    int n,m,c;
    while(T--) {
        int t=0;
        scanf("%d%d%d",&n,&m,&c);
        a[++t]=1;
        queue<int>q;
        for(int i=2;i<=n;i++) q.push(i);
        while(!q.empty()) {
            int b=m;
            while(b) {
                q.push(q.front());
                q.pop();
                b--;
            }
            a[q.front()]=++t;
            q.pop();
        }
        int d;
        while(c--) {
            scanf("%d",&d);
            printf("%d\n",a[d]);
        }
    }
    return 0;
}