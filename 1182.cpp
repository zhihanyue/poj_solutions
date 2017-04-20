#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <climits>
using namespace std;
#define fromto(from,to,i) for(int i=(from);i<=(to);++i)
#define fromdownto(from,to,i) for(int i=(from);i>=(to);--i)
#define fromgoto(from,to,i) for(int i=(from),__size=(to);i<=__size;++i)
#define foreach(v,p,type) for(type::iterator p=(v).begin();p!=(v).end();++p)
#define MP make_pair
#define INF INT_MAX
#define MAXN 50008

struct uset {
    int fa[MAXN],gx[MAXN];//gx:0=Same -1=BeEaten 1=Eat 
    uset(){for(int i=0;i<MAXN;++i){fa[i]=i;gx[i]=0;}}
    inline int g(int x,int y){return x==y?-x:x+y;}
    int root(int v) {
        if(fa[v]!=v) {
            int t=root(fa[v]);
            gx[v]=g(gx[v],gx[fa[v]]);
            fa[v]=t;
        }
        return fa[v];
    }
    bool merge(int x,int y,int k) {
        int u=root(x),v=root(y);
        if(u==v) return g(gx[x],-gx[y])==k;
        gx[v]=g(g(-gx[y],-k),gx[x]); fa[v]=u;
        return true;
    }
};

int main()
{
    int n,m,ans=0;
    scanf("%d%d",&n,&m);
    uset S;
    while(m--) {
        int d,x,y;scanf("%d%d%d",&d,&x,&y);
        if(x>n || y>n || !S.merge(x,y,d!=1)) ++ans;
    }
    printf("%d\n",ans);
    return 0;
}
