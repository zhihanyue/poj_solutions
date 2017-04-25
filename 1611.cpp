#include <cstdio>
#include <cmath>
#include <climits>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;
#define fromto(from,to,i) for(int i=(from);i<=(to);++i)
#define fromdownto(from,to,i) for(int i=(from);i>=(to);--i)
#define fromgoto(from,to,i) for(int i=(from),__size=(to);i<=__size;++i)
#define foreach(v,p,type) for(type::iterator p=(v).begin();p!=(v).end();++p)
#define INF INT_MAX
#define MAXN 30008
list<int> L[MAXN];
int L_size[MAXN];
int inL[MAXN];
void merge(int L1,int L2) {
    if(L1==L2) return;
    if(L_size[L1]>L_size[L2]) swap(L1,L2);
    foreach(L[L1],p,list<int>) inL[*p]=L2;
    L[L2].splice(L[L2].end(),L[L1]);
    L_size[L2]+=L_size[L1];L_size[L1]=0;
}
int main()
{
    while(true) {
        int n,m;scanf("%d%d",&n,&m);
        if(n==0 && m==0) break;
        fromto(0,n-1,i){inL[i]=i;L[i].clear();L[i].push_back(i);L_size[i]=1;}
        while(m--) {
            int k,s0,s;scanf("%d%d",&k,&s0);
            fromto(2,k,j) {
                scanf("%d",&s);
                merge(inL[s0],inL[s]);
            }
        }
        printf("%d\n",L_size[inL[0]]);
    }
    return 0;
}
