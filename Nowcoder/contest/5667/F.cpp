#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int n,m,k,a[N][N],gcd[N][N];
long long res;
deque<int> dq;
int main() {
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(!gcd[i][j])
                for(int k=1;i*k<=n&&j*k<=m;k++)
                    gcd[i*k][j*k]=k,a[i*k][j*k]=i*j*k;
    for(int i=1;i<=n;i++) {
        dq.clear();
        for(int j=1;j<=m;j++) {
            if(!dq.empty()&&j-dq.front()+1>k) dq.pop_front();
            while(!dq.empty()&&a[i][dq.back()]<=a[i][j]) dq.pop_back();
            dq.push_back(j);
            if(j-k+1>0) a[i][j-k+1]=a[i][dq.front()];
        }
    }
    for(int j=1;j<=m;j++) {
        dq.clear();
        for(int i=1;i<=n;i++) {
            if(!dq.empty()&&i-dq.front()+1>k) dq.pop_front();
            while(!dq.empty()&&a[dq.back()][j]<=a[i][j]) dq.pop_back();
            dq.push_back(i);
            if(i-k+1>0) a[i-k+1][j]=a[dq.front()][j];
        }
    }
    for(int i=1;i<=n-k+1;i++) {
        for(int j=1;j<=m-k+1;j++)
            res+=a[i][j];
    }
    printf("%lld\n",res);
    return 0;
}