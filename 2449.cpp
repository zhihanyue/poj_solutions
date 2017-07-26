#include <cstdio>
#include <vector>
#include <queue>
#include <climits> 
#define NMAX 1001
#define INF (INT_MAX/3)
#define fromto(from,to,i) for(int (i)=(from);(i)<=(to);++(i))
#define fromgoto(from,to,i) for(int (i)=(from),__size=(to);i<=(__size);++(i))
using namespace std;
typedef pair<int,int> Edge;
typedef pair<int,int> Sta;

vector<Edge> G[NMAX],rG[NMAX];
int G_N;

int solve(int S,int T,int K)
{
    static priority_queue<Sta,vector<Sta>,greater<Sta> > q;
    static int h[NMAX],times[NMAX]={0};
    fill(h,h+G_N+1,INF);
    h[T]=0;
    q.push(Sta(0,T));
    while(!q.empty()) {
        Sta thista=q.top();q.pop();
        int u=thista.second;
        ++times[u];
        if(times[u]>1) continue;
        fromgoto(0,rG[u].size()-1,i) {
            Edge e=rG[u][i];
            int v=e.first,w=e.second;
            if(h[v]>h[u]+w) {
                h[v]=h[u]+w;
                q.push(Sta(h[v],v));
            }
        }
    }
    
    memset(times,0,sizeof(times));
    if(S==T) ++K;
    q.push(Sta(h[S],S));
    while(!q.empty()) {
        Sta thista=q.top();q.pop();
        int f_u=thista.first,u=thista.second;
        ++times[u];
        //if(u==T) ans[times[T]]=f_u-h[u];
        /*if(times[u]>1 && ans[times[u]]==ans[times[u]-1]) {
            --times[u];
            //continue;
        }*/
        //printf("u=%d f_u=%d\n",u,f_u);
        if(times[u]>K) continue;
        if(times[T]==K) return f_u-h[u];
        fromgoto(0,G[u].size()-1,i) {
            Edge e=G[u][i];
            int v=e.first,w=e.second;
            q.push(Sta(f_u-h[u]+w+h[v],v));
        }
    }
    return -1;
}

int main()
{
    int M,S,T,K;
    scanf("%d%d",&G_N,&M);
    fromto(1,M,i) {
        int A,B,T;
        scanf("%d%d%d",&A,&B,&T);
        G[A].push_back(Edge(B,T));
        rG[B].push_back(Edge(A,T));
    }
    scanf("%d%d%d",&S,&T,&K);
    printf("%d\n",solve(S,T,K));
    return 0;
}
