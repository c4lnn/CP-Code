#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c[200001];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        cin>>c[i];
    sort(c,c+n);
    int ans=0;
    for(int i=0;i<n;i++)
        if(c[i]>ans)
            ++ans;
    cout<<ans;
    return 0;
}