#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int n;
    while(t--)
    {
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        int l=0,r=0;
        int ans=0;
        set<int>s;
        while(r<n)
        {
            while(r<n&&!s.count(a[r])) s.insert(a[r++]);
            ans=max(ans,r-l);
            s.erase(a[l++]);
        }
        cout<<ans<<endl;
    }
    return 0;
}