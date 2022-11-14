#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
using namespace std;
int main()
{
    int n,k;
    vector<int>ans[16];
    for(int j=1;j<=15;j++)
    {
        int v[50000]={0};
        for(int i=0;i<j;i++)
            ans[j].push_back(0);
        v[0]=1;
        while(1)
        {
            int t=0;
            for(int i=1;i<j;i++)
                if(ans[j][ans[j].size()-i])
                    t+=pow(2,i);
            if(v[t])
                ans[j].push_back(1);
            else
                ans[j].push_back(0);
            int tt=0;
            v[t+ans[j][ans[j].size()-1]]=1;
            for(int i=1;i<j;i++)
                if(ans[j][ans[j].size()-i])
                    tt+=pow(2,i);
            if(t+ans[j][ans[j].size()-1]==pow(2,j)-1)
                break;
            if(v[tt]&&v[tt+1])
                ans[j].pop_back();
        }
    }
    while(cin>>n>>k&&n)
    {
        int kk=0;
        for(int i=k,a=n-1;i<k+n;i++)
        {
            kk+=ans[n][i%ans[n].size()]*pow(2,a);
            a--;
        }
        cout<<kk<<endl;
    }
    return 0;
}