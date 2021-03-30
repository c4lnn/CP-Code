#include<bits/stdc++.h>
using namespace std;
struct Point
{
    int l;
    int w;
};
int cmp(struct Point a,struct Point b)
{
    return a.l<b.l||a.l==b.l&&a.w<b.w;
}
int main()
{
    int N;
    cin>>N;
    while(N--)
    {
        int m;
        cin>>m;
        struct Point n[m];
        int v[m];
        int time=0;
        int s=0;
        int w_max;
        for(int i=0;i<m;i++)
            v[i]=1;
        for(int i=0;i<m;i++)
            cin>>n[i].l>>n[i].w;
        sort(n,n+m,cmp);
        for(int i=0;i<m;i++)
        {
            if(v[i])
            {
                s++;
                w_max=n[i].w;
                time++;
                for(int j=i+1;j<m;j++)
                    if(v[j])
                        if(n[j].w>=w_max)
                        {
                            v[j]=0;
                            s++;
                            w_max=n[j].w;
                        }
            }
            if(s==m)
                break;
        }
        cout<<time<<endl;
    }
    return 0;
}