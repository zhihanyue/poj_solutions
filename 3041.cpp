#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits> 
using namespace std;
#define MAXN 1008
#define fromto(from,to,i) for(int (i)=(from);(i)<=(to);++(i))
#define fromgoto(from,to,i) for(int (i)=(from),__to=(to);(i)<=__to;++(i))
#define hang(i) i
#define lie(i) N+i
#define INF (INT_MAX/2)

struct Edge {
    int v,cap,rev;
    Edge(int _v,int _cap,int _rev):v(_v),cap(_cap),rev(_rev){}
};
vector<Edge> G[MAXN];
int Start,To;

void add_edge(int u,int v,int cap)
{
    G[u].push_back(Edge(v,cap,G[v].size()));
    G[v].push_back(Edge(u,0,G[u].size()-1));//0!!!!!!!!!!
}

int level[MAXN];
bool bfs()
{
    memset(level,-1,sizeof(level));
    queue<int> q;
    level[Start]=0;
    q.push(Start);
    while(!q.empty()) {
        int u=q.front();q.pop();
        fromgoto(0,G[u].size()-1,i) {
            Edge e=G[u][i];
            if(e.cap>0 && level[e.v]<0) {
                level[e.v]=level[u]+1;
                q.push(e.v);
            }
        }
    }
    return level[To]>=0;
}

int iter[MAXN];
int dfs(int u,int flow)
{
    if(u==To) return flow;
    int d;
    for(int &i=iter[u],size=G[u].size();i<size;++i) {
        Edge &e=G[u][i];
        if(e.cap>0 && level[u]<level[e.v] && (d=dfs(e.v,min(flow,e.cap)))>0) {
            e.cap-=d;
            G[e.v][e.rev].cap+=d;
            return d;
        }
    }
    return 0;
}

int max_flow()
{
    int flow=0;
    while(bfs()) {
        memset(iter,0,sizeof(iter));
        for(int flow_now;(flow_now=dfs(Start,INF))>0;flow+=flow_now);
    }
    return flow;
}

int main()
{
    int N,K;
    scanf("%d%d",&N,&K);
    Start=0; To=2*N+1;
    fromto(1,N,i) add_edge(Start,i,1);
    fromto(N+1,2*N,i) add_edge(i,To,1);
    while(K--) {
        int R,C;
        scanf("%d%d",&R,&C);
        add_edge(hang(R),lie(C),1);
    }
    printf("%d\n",max_flow());
    return 0;
}
