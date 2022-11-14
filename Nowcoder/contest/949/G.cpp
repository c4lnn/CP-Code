#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fi first
#define se second

#define lowbit(x) x&(-x)
#define mem(arr,val) memset(arr,val,sizeof arr)

typedef pair<int,int>pii;
const double pi=3.14159265;
int main()
{
    int n;
    scanf("%d",&n);
    double r=(double)n/pi;
    double ans=0.5*r*r*pi;
    printf("%.3lf",ans);
    return 0;
}