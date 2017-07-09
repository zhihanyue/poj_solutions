#include <cstdio>
#include <climits>
#include <vector>
#include <queue>
using namespace std;
#define fromgoto(from,to,i) for(int (i)=(from),__size=(to);(i)<=__size;++(i))
#define MAXN 1008
#define INF (INT_MAX/2)
struct Edge {
    int to,cap,cost,rev;
    Edge(int _to,int _cap,int _cost,int _rev):to(_to),cap(_cap),cost(_cost),rev(_rev){}
};
vector<Edge> G[MAXN];
int G_N;
int Start,To;
void add_edge(int u,int v,int cap,int cost)
{
    G[u].push_back(Edge(v,cap,cost,G[v].size()));
    G[v].push_back(Edge(u,0,-cost,G[u].size()-1));
}

int min_cost_flow(int goodflow)
{
    int flow=0,cost=0;
    static int d[MAXN];
    static int preu[MAXN],prei[MAXN];
    while(flow<goodflow) {
        fill(d,d+G_N+1,INF);
        queue<int> q;
        d[Start]=0;
        preu[Start]=prei[Start]=-1;
        q.push(Start);
        while(!q.empty()) {
            int u=q.front();q.pop();
            fromgoto(0,G[u].size()-1,i) {
                Edge e=G[u][i];
                if(e.cap>0 && d[e.to]>d[u]+e.cost) {
                    d[e.to]=d[u]+e.cost;
                    preu[e.to]=u;prei[e.to]=i;
                    q.push(e.to);
                }
            }
        }
        if(d[To]>=INF) return -1;
        int mincap=INF;
        for(int u,v=To;(u=preu[v])!=-1;v=u) {
            Edge &e=G[u][prei[v]];
            mincap=min(mincap,e.cap);
        }
        for(int u,v=To;(u=preu[v])!=-1;v=u) {
            Edge &e=G[u][prei[v]];
            e.cap-=mincap;
            G[e.to][e.rev].cap+=mincap;
            cost+=e.cost*mincap;
        }
        flow+=mincap;
    }
    return cost;
}

int main()
{
    int m;
    scanf("%d%d",&G_N,&m);
    Start=1;To=G_N;
    while(m--) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add_edge(a,b,1,c);
        add_edge(b,a,1,c);
    }
    printf("%d\n",min_cost_flow(2));
    return 0;
}
