#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;
#define MAXN 108
#define INF (INT_MAX/2)
#define fromto(from,to,i) for(int i=(from);i<=(to);++i)
int main()
{
    static int G[MAXN][MAXN],d[MAXN][MAXN],pre[MAXN][MAXN];
    int n,m;
    scanf("%d%d",&n,&m);
    fromto(1,n,i) fromto(1,n,j) {
        G[i][j]=INF;
        d[i][j]=INF;
        pre[i][j]=i;
    }
    fromto(1,m,i) {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        w=min(w,G[u][v]);
        G[u][v]=w;G[v][u]=w;
        d[u][v]=w;d[v][u]=w;
    }
    static int minhuan=INF,path[MAXN],path_len;
    fromto(1,n,k) {
        fromto(1,k-1,i) fromto(i+1,k-1,j)
            if(d[i][j]!=INF && G[i][k]!=INF && G[k][j]!=INF && minhuan>d[i][j]+G[i][k]+G[k][j]) {
                minhuan=d[i][j]+G[i][k]+G[k][j];
                path_len=0;
                for(int v=j;v!=i;v=pre[i][v]) path[++path_len]=v;
                path[++path_len]=i; path[++path_len]=k;
            }
        fromto(1,n,i) fromto(1,n,j)
            if(d[i][k]!=INF && d[k][j]!=INF && d[i][j]>d[i][k]+d[k][j]) {
                d[i][j]=d[i][k]+d[k][j];
                pre[i][j]=pre[k][j];
            }
    }
    if(minhuan==INF){printf("No solution.\n");return 0;}
    fromto(1,path_len,i) printf(i!=path_len?"%d ":"%d\n",path[i]);
    return 0;
}
 