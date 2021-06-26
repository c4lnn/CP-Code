#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
int num[maxn];
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>num[i];
    sort(num,num+n);
    cout<<num[k-1];
    return 0;
}
