#include<bits/stdc++.h>
using namespace std;
const int N=300;
char s[4][20];
int a[N][4];
map<string,int>mp;
void init() {
    mp["one"]=0,mp["two"]=1,mp["three"]=2;
    mp["diamond"]=0,mp["squiggle"]=1,mp["oval"]=2;
    mp["solid"]=0,mp["striped"]=1,mp["open"]=2;
    mp["red"]=0,mp["green"]=1,mp["purple"]=2;
    mp["*"]=3;
}
void solve(int x) {
    int n;
    scanf("%d",&n);
    string t;
    for(int i=1;i<=n;i++) {
        scanf(" [%[^]]][%[^]]][%[^]]][%[^]]]",s[0],s[1],s[2],s[3]);
        for(int j=0;j<4;j++) a[i][j]=mp[t=s[j]];
    }
    printf("Case #%d: ",x);
    for(int i=1;i<=n;i++)
        for(int j=1;j<i;j++)
            for(int k=1;k<j;k++) {
                int l;
                for(l=0;l<4;l++) {
                    if(a[i][l]==3||a[j][l]==3||a[k][l]==3) continue;
                    if((a[i][l]+a[j][l]+a[k][l])%3!=0) break;
                }
                if(l==4) {printf("%d %d %d\n",i,j,k);return;}
            }
    puts("-1");
}
int main() {
    init();
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++) solve(i);
    return 0;
}