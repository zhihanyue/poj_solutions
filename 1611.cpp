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
vector<int> L[MAXN];
int inL[MAXN];
void merge(int L1,int L2) {
    if(L1==L2) return;
    //if(L[L1].size()>L[L2].size()) swap(L1,L2);
    foreach(L[L1],p,vector<int>) inL[*p]=L2;
    L[L2].insert(L[L2].end(),L[L1].begin(),L[L1].end());
    vector<int>().swap(L[L1]);
}
int main()
{
    while(true) {
        int n,m;scanf("%d%d",&n,&m);
        if(n==0 && m==0) break;
        fromto(0,n-1,i){inL[i]=i;L[i]=vector<int>();L[i].push_back(i);}
        while(m--) {
            int k,s0,s;scanf("%d%d",&k,&s0);
            fromto(2,k,j) {
                scanf("%d",&s);
                merge(inL[s0],inL[s]);
            }
        }
        printf("%d\n",L[inL[0]].size());
    }
    return 0;
}
