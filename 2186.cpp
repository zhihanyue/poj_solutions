#include <iostream>
using namespace std;
#define MAXM 50010
#define MAXV 10010
#define min(a,b) (a>b?b:a)

typedef struct{
    int s,t,next,next2;
}Edge;

Edge edge[MAXM];
int n,m,headlist[MAXV],headlist2[MAXV];

int order[MAXV],belong[MAXV];
int num,count;
bool vis[MAXV];

void dfs(int x){
    int i,a;
    vis[x]=1;
    for(i=headlist[x];i!=-1;i=edge[i].next){
        a=edge[i].t;
        if(!vis[a]) dfs(a);
    }
    order[++num]=x;
}

void dfst(int x){
    int i,a;
    belong[x]=count;        //记录结点属于哪个连通分量
    vis[x]=1;
    for(i=headlist2[x];i!=-1;i=edge[i].next2){      //要将边反过来遍历一遍
        a=edge[i].s;
        if(!vis[a]) dfst(a);
    }
}

void kosaraju(){
    int i;
    memset(vis,0,sizeof(vis));
    num=count=0;
    for(i=1;i<=n;i++)
        if(!vis[i]) dfs(i);
    memset(vis,0,sizeof(vis));
        
    for(i=n;i>=1;i--)
        if(!vis[order[i]]){
            count++;
            dfst(order[i]);
        }
}

void output(){
    int i,outdegree[MAXV]={0},outzero=0,ans=0,cnt;
    for(i=0;i<m;i++){
        if(belong[edge[i].s]!=belong[edge[i].t]){
            outdegree[belong[edge[i].s]]++;
        }
    }
    for(i=1;i<=count;i++){
        if(!outdegree[i]){
            outzero++;
            cnt=i;
        }
    }
    for(i=1;i<=n;i++)
        if(belong[i]==cnt) ans++;
        if(outzero==1)  printf("%d\n",ans);
        else printf("0\n");
}

int main(){
    int i,a,b;
    scanf("%d%d",&n,&m));
        memset(headlist,-1,sizeof(headlist));
        memset(headlist2,-1,sizeof(headlist2));
        for(i=0;i<m;i++){
            scanf("%d%d",&a,&b);
            edge[i].s=a;
            edge[i].t=b;
            edge[i].next=headlist[a];
            headlist[a]=i;
            edge[i].next2=headlist2[b];     //记录反边
            headlist2[b]=i;
        }
        kosaraju();
        output();
    return 0;
}