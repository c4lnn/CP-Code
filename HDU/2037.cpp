#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int start;
    int end;
}n[105];
int cmp(struct Node a,struct Node b)
{
    return a.end<b.end||a.end==b.end&&a.start<b.start;    
}
int main()
{
    int N;
    while(cin>>N&&N)
    {
        int end=0,count=0;
        for(int i=0;i<N;i++)
            cin>>n[i].start>>n[i].end;
        sort(n,n+N,cmp);
        for(int i=0;i<N;i++)
            if(n[i].start>=end)
            {    
                end=n[i].end;
                count++;
            }
        cout<<count<<endl;
    }
    
    return 0;
}
