#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#define fromto(from,to,i) for(int (i)=(from);(i)<=(to);++(i))
#define fromgoto(from,to,i) for(int (i)=(from),__to=(to);(i)<=__to;++(i))
#define lowbit(i) ((i)&(-(i)))
#define MAXN 100008
using namespace std;

struct edge{int to,w,id;};
vector<edge> G[MAXN];
pair<int,int> dfsxu[2*MAXN];
int dfs_edge[2*MAXN],edge_id[MAXN][2];
int dfs_id[MAXN],dfs_len;
pair<int,int> ST[20][2*MAXN];
long long BIT[2*MAXN];
int BIT_len;

void add(int i,int add)
{
    dfs_edge[i]+=add;
    for(;i<=BIT_len;i+=lowbit(i)) BIT[i]+=add;
}

long long sum(int i)
{
    long long res=0;
    for(;i>0;i-=lowbit(i))
        res+=BIT[i];
    return res;
}

long long query(int L,int r)
{
    if(r<L) swap(L,r);
    return sum(r-1)-sum(L-1);
}

void dfs(int u,int p,int d)
{
    dfsxu[++dfs_len]=make_pair(d,u);
    dfs_id[u]=dfs_len;
    fromgoto(0,G[u].size()-1,i) {
        edge e=G[u][i];
        if(e.to==p) continue;
        
        add(dfs_len,e.w);
        edge_id[e.id][0]=dfs_len;
        dfs(e.to,u,d+1);
        add(dfs_len,-e.w);
        edge_id[e.id][1]=dfs_len;
        
        dfsxu[++dfs_len]=make_pair(d,u);
    }
}

void ST_init()
{
    fromto(1,dfs_len,i) ST[0][i]=dfsxu[i];
    fromgoto(1,(int)(log((double)dfs_len)/log(2.0))+1,i) fromto(1,dfs_len-(1<<i)+1,j)
        ST[i][j]=min(ST[i-1][j],ST[i-1][j+(1<<(i-1))]);
}

pair<int,int> ST_query(int L,int R)
{
    if(L>R) swap(L,R);
    int k=(int)(log((double)R-L+1)/log(2.0));
    return min(ST[k][L],ST[k][R+1-(1<<k)]);
}

void lca_init(int root)
{
    memset(dfs_edge,0,sizeof(dfs_edge));
    memset(dfs_id,0,sizeof(dfs_id));
    dfs_len=0;
    dfs(root,root,1);
    ST_init();
}

int lca(int root,int u,int v)
{
    return ST_query(dfs_id[u],dfs_id[v]).second;
}

int main()
{
    int n,q,s;
    scanf("%d%d%d",&n,&q,&s);
    fromto(1,n-1,i) {
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        edge tempe={b,w,i};
        G[a].push_back(tempe);
        tempe.to=a;
        G[b].push_back(tempe);
    }
    BIT_len=n*2+1;
    lca_init(1);
    fromto(1,q,temptemp) {
        int type;
        scanf("%d",&type);
        if(type) {
            int e,w;
            scanf("%d%d",&e,&w);
            int a1=edge_id[e][0],a2=edge_id[e][1],old=dfs_edge[a1];
            add(a1,w-old);
            add(a2,old-w);
        } else {
            int to;
            scanf("%d",&to);
            int ca=lca(1,s,to);
            printf("%d\n",query(dfs_id[s],dfs_id[ca])+query(dfs_id[to],dfs_id[ca]));
            s=to;
        }
    }
    //system("pause");
    return 0;
}
