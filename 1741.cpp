#include <cstdio>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
#define fromto(from,to,i) for(int (i)=(from);(i)<=(to);++(i))
#define fromgoto(from,to,i) for(int (i)=(from),__size=(to);(i)<=__size;++(i))
#define watch(a,n) for(int __i=0;__i<(n);++__i) printf("%d ",(a)[__i]);printf("\n");
#define MAXN 10008
#define INF INT_MAX/2
typedef pair<int,int> Edge;//v,w
typedef pair<int,int> Zx;//size,u
vector<Edge> G[MAXN];
int subsize[MAXN];
int K;
int G_n;

bool deleted[MAXN];
int consubsize(int u,int p)
{
    int sum=1;
    fromgoto(0,G[u].size()-1,i) {
        int v=G[u][i].first;
        if(v==p || deleted[v]) continue;
        sum+=consubsize(v,u);
    }
    return subsize[u]=sum;
}

int tsize;
Zx findzx(int u,int p)
{
    Zx res=Zx(INF,0);
    int m=-INF;
    fromgoto(0,G[u].size()-1,i) {
        int v=G[u][i].first,w=G[u][i].second;
        if(v==p || deleted[v]) continue;
        res=min(res,findzx(v,u));
        m=max(m,subsize[v]);
    }
    res=min(res,Zx(max(m,tsize-subsize[u]),u));
    return res;
}

int depth[MAXN];
vector<int> belong[MAXN];
void condb(int u,int p,int b,int d)
{
    depth[u]=d;
    belong[b].push_back(d);
    fromgoto(0,G[u].size()-1,i) {
        int v=G[u][i].first,w=G[u][i].second;
        if(v==p || deleted[v]) continue;
        condb(v,u,b,d+w);
    }
}

long long sumxk(vector<int> &arr,int k)
{
    //printf("arr_size:%d\n",arr.size());
    long long res=0;
    sort(arr.begin(),arr.end());
    //watch(arr,arr.size());
    int h=arr.size()-1;
    fromgoto(0,h,i) {
        while(h>0 && arr[i]+arr[h]>k) --h;
        if(h<=i) break;
        res+=h-i;
    }
    //printf("res=%I64d\n",res);
    return res;
}

int solve(int root)
{
    if((tsize=consubsize(root,-1))<=1) return 0;
    
    long long ans=0;
    root=findzx(root,-1).second;//修正root 
    belong[root].clear();
    belong[root].push_back(0);
    fromgoto(0,G[root].size()-1,i) {
        int v=G[root][i].first,w=G[root][i].second;
        belong[v].clear();
        if(!deleted[v]) condb(v,root,v,w);
        belong[root].insert(belong[root].end(),belong[v].begin(),belong[v].end());
        ans+=sumxk(belong[v],K);
    }
    ans=sumxk(belong[root],K)-ans;
    deleted[root]=true;
    
    fromgoto(0,G[root].size()-1,i) {
        int v=G[root][i].first;
        if(!deleted[v]) ans+=solve(v);
    }
    //printf("solve(%d)=%d\n",root,ans);
    return ans;
}

int main()
{
    while(true) {
        scanf("%d%d",&G_n,&K);
        if(G_n==0 && K==0) break;
        fromto(1,G_n,i) G[i].clear();
        memset(deleted,false,sizeof(deleted));
        int root;
        fromto(1,G_n-1,i) {
            int a,b,w;
            scanf("%d%d%d",&a,&b,&w);
            root=a;
            G[a].push_back(Edge(b,w));
            G[b].push_back(Edge(a,w));
        }
        printf("%d\n",solve(root));//因为刚开始是tree，随便选个点为根 
    }
    return 0;
}
