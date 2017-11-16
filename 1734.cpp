#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
const int N = 110;
const int inf = 1e8;
struct node{
    int to,w;
};
vector<node> QQ[N];
bool vis[N];
int S,ans[N],temp[N],best,ans_nodes;
void dfs(int now,int fa,int dep,int sum)
{
     int i;
     if(now==S&&vis[S])
     {
         if(sum<best)
         {
             best=sum;ans_nodes=dep;
             for(i=0;i<dep;i++)
                 ans[i]=temp[i];
         }
         return ;
     }
     temp[dep]=now;
     for(i=0;i<QQ[now].size();i++)
     {
         if(QQ[now][i].to!=S&&vis[QQ[now][i].to]) continue;
         if(QQ[now][i].to==fa) continue;
         vis[QQ[now][i].to]=true;
         if(QQ[now][i].w+sum<best) 
             dfs(QQ[now][i].to,now,dep+1,sum+QQ[now][i].w);
         vis[QQ[now][i].to]=false;
     }
}
int main()
{
    int n,m;
    int i,w,s,t;
    scanf("%d%d",&n,&m);
        node tmp;
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&s,&t,&w);
            tmp.to=t;
            tmp.w=w;
            QQ[s].push_back(tmp);
            tmp.to=s;
            QQ[t].push_back(tmp);
        }
        best=inf;//错误原因：全局变量在这里又定义了一遍，汗！！！！
        for(i=1;i<=n;i++)
        {
            memset(vis,false,sizeof(vis));
            S=i;
            dfs(i,-1,0,0);
        }
        if(best==inf) printf("No solution.\n");
        else 
        {
            printf("%d",ans[0]);
            for(i=1;i<ans_nodes;i++)
                printf(" %d",ans[i]);
        }
        printf("\n");
    return 0;
}
