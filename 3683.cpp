#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define fromto(from,to,i) for(int (i)=(from);(i)<=(to);++(i))
#define fromgoto(from,to,i) for(int (i)=(from),__temp=(to);(i)<=__temp;++(i))
using namespace std;

int timetonum(pair<int,int> time)
{
    return time.first*60+time.second;
}

pair<int,int> numtotime(int num)
{
    return make_pair(num/60,num%60);
}

bool jiao(pair<int,int> x,pair<int,int> y)
{
    if(x>y) swap(x,y);
    return x.second>y.first;
}

pair<int,int> seg[2008]; 
vector<int> G[4008],rG[4008];
bool vis[4008];
int SCC[4008];
vector<int> topo;
bool xuan[4008];

void addedge(int u,int v)
{
    G[u].push_back(v);
    rG[v].push_back(u);
}

void dfs(int u)
{
    vis[u]=true;
    fromgoto(0,G[u].size()-1,i)
        if(!vis[G[u][i]]) dfs(G[u][i]);
    topo.push_back(u);
}

void rdfs(int u,int k)
{
    vis[u]=true;
    SCC[u]=k;
    fromgoto(0,rG[u].size()-1,i)
        if(!vis[rG[u][i]]) rdfs(rG[u][i],k);
}

int main()
{
    int N;
    //init
    {
        scanf("%d",&N);
        for(int i=0;i<2*N;i+=2) {
            pair<int,int> S,T;
            int D;
            scanf("%d:%d %d:%d %d",&S.first,&S.second,&T.first,&T.second,&D);
            seg[i].first=timetonum(S);
            seg[i].second=seg[i].first+D;
            seg[i^1].second=timetonum(T);
            seg[i^1].first=seg[i^1].second-D;
            //printf("%d %d %d %d\n",seg[i].first,seg[i].second,seg[i^1].first,seg[i^1].second);
            addedge(i+2*N,i^1); addedge(i^1,i+2*N);
            addedge((i^1)+2*N,i); addedge(i,(i^1)+2*N);
        }
        fromto(0,2*N-1,i) fromto(i+1,2*N-1,j)
            if(jiao(seg[i],seg[j])) {
                //printf("%d %d\n",i,j);
                addedge(i,j+2*N);
                addedge(j,i+2*N);
            }
    }
    
    //solve && print
    {
        memset(vis,false,sizeof(vis));
        fromto(0,4*N-1,i) if(!vis[i]) dfs(i);
        reverse(topo.begin(),topo.end());
        memset(vis,false,sizeof(vis));
        int SCC_cnt=0;
        fromgoto(0,topo.size()-1,i) if(!vis[topo[i]]) rdfs(topo[i],++SCC_cnt);
        //printf("SCC_cnt=%d\n",SCC_cnt);
        fromto(0,2*N-1,i) if(SCC[i]==SCC[i+2*N]) {printf("NO\n");goto THEEND;}
        printf("YES\n");
        fromto(0,2*N-1,i) if(SCC[i]>SCC[i+2*N]) {
            pair<int,int> S=numtotime(seg[i].first);
            pair<int,int> T=numtotime(seg[i].second);
            printf("%02d:%02d %02d:%02d\n",S.first,S.second,T.first,T.second);//qian dao ling!!!!!!!!
        }
    }
    
    THEEND:
    return 0;
}
