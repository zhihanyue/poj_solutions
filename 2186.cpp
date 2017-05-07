#include <cstdio>
#include <vector>
#include <algorithm>
#define fromto(from,to,i) for(int (i)=(from);(i)<=(to);++(i))
#define fromgoto(from,to,i) for(int (i)=(from),__size=(to);(i)<=(__size);++(i))

using namespace std;

vector<int> G[10008],rG[10008];
vector<int> T;
int SCC[10008];
bool vis[10008];

void dfs(int u)
{
    vis[u]=true;
    fromgoto(0,G[u].size()-1,i) {
        int v=G[u][i];
        if(!vis[v]) dfs(v);
    }
    T.push_back(u);
}   

void rdfs(int u,int k)
{
    vis[u]=true;
    SCC[u]=k;
    fromgoto(0,rG[u].size()-1,i) {
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
    
    //solve
    memset(vis,false,sizeof(vis));
    fromto(1,N,i) if(!vis[i]) dfs(i);
    reverse(T.begin(),T.end());
    
    memset(vis,false,sizeof(vis));
    int k=0;
    fromgoto(0,T.size()-1,i)
        if(!vis[T[i]]) rdfs(T[i],++k);
    
    //print
    int res=0,from=0;
    fromto(1,N,i) if(SCC[i]==k) {from=i;++res;}
    
    memset(vis,false,sizeof(vis));
    rdfs(from,0);
    fromto(1,N,i) if(!vis[i]) { res=0; break; }
    printf("%d\n",res);
    return 0;
}
