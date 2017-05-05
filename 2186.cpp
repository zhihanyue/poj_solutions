#include <cstdio>
#include <vector>
#include <algorithm>
#define fromto(from,to,i) for(int (i)=(from);(i)<=(to);++(i))
using namespace std;

vector<int> G[10008],rG[10008];
int T[10008],T_len;
int SCC[10008];
bool vis[10008];

void dfs(int u)
{
    vis[u]=true;
    for(int i=0,size=G[u].size();i<size;++i) {
        int v=G[u][i];
        if(!vis[v]) dfs(v);
    }
    T[T_len++]=u;
}

void rdfs2(int u)
{
    vis[u]=true;
    for(int i=0,size=rG[u].size();i<size;++i) {
        int v=rG[u][i];
        if(!vis[v]) rdfs2(v);
    }
    T[T_len++]=u;
}

void rdfs(int u,int k)
{
    SCC[u]=k;
    for(int i=0,size=rG[u].size();i<size;++i) {
        int v=rG[u][i];
        if(SCC[v]==-1) rdfs(v,k);
    }
}       

int main()
{
    int N,M;
    scanf("%d%d",&N,&M);
    fromto(1,M,i) {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        rG[v].push_back(u);
    }
    memset(vis,false,sizeof(vis));
    T_len=0;
    fromto(1,N,i) if(!vis[i]) dfs(i);
    reverse(T,T+T_len);
    
    memset(SCC,-1,sizeof(SCC));
    int k=0;
    fromto(0,T_len-1,i)
        if(SCC[T[i]]==-1) rdfs(T[i],k++);
    
    memset(vis,false,sizeof(vis));
    int temp=T[T_len-1];
    T_len=0;
    rdfs2(temp);
    int res=0;
    if(T_len==N) fromto(1,N,i)
        if(SCC[i]==k-1) ++res;
    printf("%d\n",res);
    return 0;
}
