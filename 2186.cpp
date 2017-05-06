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
    T[++T_len]=u;
}   

void rdfs(int u,int k)
{
    vis[u]=true;
    SCC[u]=k;
    for(int i=0,size=rG[u].size();i<size;++i) {
        int v=rG[u][i];
        if(!vis[v]) rdfs(v,k);
    }
}       

int main()
{
    int N,M;
    scanf("%d%d",&N,&M);
    fromto(1,N,i) {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        rG[v].push_back(u);
    }
    memset(vis,false,sizeof(vis));
    T_len=0;
    fromto(1,N,i) if(!vis[i]) dfs(i);
    reverse(T+1,T+T_len+1);
    
    memset(vis,false,sizeof(vis));
    int k=0;
    fromto(1,T_len,i)
        if(!vis[T[i]]) rdfs(T[i],++k);
    
    int res=0;
    fromto(1,N,i) if(SCC[i]==k) ++res;
    
    memset(vis,false,sizeof(vis));
    rdfs(T[T_len],0);
    fromto(1,N,i) if(!vis[i]) {
        printf("0\n");
        return 0;
    }
    printf("%d\n",res);
    return 0;
}
