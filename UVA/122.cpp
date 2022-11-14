#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define mem(i,j) memset(i,j,sizeof(i))
#define lowbit(x) x&(-x)

typedef long long ll;
typedef pair<int,int>pii;

char s[500];
char s1[500];

int v;
bool failed;
vector<int>ans;

struct node
{
    int have_valve;
    node *left;
    node *right;
    node():have_valve(0),left(NULL),right(NULL){}
};
node* root;
void remove_tree(node* u)
{
    if(u==NULL) return;
    remove_tree(u->left);
    remove_tree(u->right);
    delete u;
}
bool bfs()
{
    ans.clear();
    node* u=root;
    queue<node*>q;
    q.push(u);
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        if(!u->have_valve) return false;
        ans.pb(u->have_valve);
        if(u->left) q.push(u->left);
        if(u->right) q.push(u->right);
    }
    return true;
}
bool read()
{
    bool read=false;
    failed=false;
    remove_tree(root);
    root=new node();
    while(~scanf("%s",s)&&s[1]!=')')
    {
        read=true;
        sscanf(&s[1],"%d",&v);
        sscanf(strchr(s,',')+1,"%s",s1);
        node* u=root;
        for(int i=0;i<strlen(s1);i++)
        {
            if(s1[i]=='L')
            {
                if(u->left==NULL) u->left=new node();
                u=u->left;
            }
            else if(s1[i]=='R')
            {
                if(u->right==NULL) u->right=new node();
                u=u->right;
            }
        }
        if(u->have_valve) failed=true;
        else u->have_valve=v;
    }
    if(read) return true;
    else return false;
}
int main()
{
    while(read())
    {
        if(failed) printf("not complete\n");
        else
        {
            if(bfs())
                for(int i=0;i<ans.size();i++)
                {
                    printf("%d",ans[i]);
                    if(i<ans.size()-1) printf(" ");
                    else printf("\n");
                }
            else printf("not complete\n");
        }
    }
    return 0;
}