#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    int tt;
    int n;
    while(cin>>n&&n)
    {
        
        int s=pow(2,n);
        int v[s]={0};
        vector<int>ans;
        for(int i=0;i<n;i++)
            ans.push_back(0);
        v[0]=1;
        while(1)
        {
            t=0;
            for(int i=1;i<n;i++)
                if(ans[ans.size()-i])
                    t+=pow(2,i);
            if(v[t])
                ans.push_back(1);
            else
                ans.push_back(0);
            tt=0;
            v[t+ans[ans.size()-1]]=1;
            for(int i=1;i<n;i++)
                if(ans[ans.size()-i])
                    tt+=pow(2,i);
            if(t+ans[ans.size()-1]==s-1)
                break;
            if(v[tt]&&v[tt+1])
                ans.pop_back();
        }    
        cout<<ans.size()<<" ";
        for(int i=0;i<ans.size();i++)
            cout<<ans[i];
        cout<<endl;    
    }
    return 0;
} 