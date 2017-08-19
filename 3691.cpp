#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define MAXN 1008
#define MAXM 1608
#define INF (INT_MAX/2)
#define fromto(from,to,i) for(int (i)=(from);(i)<=(to);++(i))
#define each_ch fromto(1,4,ch)

int getnum(char ch)
{
    if(ch=='A') return 1;
    else if(ch=='G') return 2;
    else if(ch=='C') return 3;
    else if(ch=='T') return 4;
    return 0;
}

namespace ac {
    int g[MAXM][5],f[MAXM],last[MAXM];
    bool OK[MAXM];
    int trie_len;
    
    int newnode()
    {
        memset(g[trie_len],-1,sizeof(g[trie_len]));
        OK[trie_len]=false;
        last[trie_len]=-1;
        return trie_len++;
    }
    
    void init()
    {
        trie_len=0;
        newnode();
    }
    
    void insert(char t[],int n)
    {
        int now=0;
        fromto(1,n,i) {
            int ch=getnum(t[i]);
            if(g[now][ch]==-1)
                g[now][ch]=newnode();
            now=g[now][ch];
        }
        OK[now]=true;
    }
    
    void getfail()
    {
        queue<int> q;
        f[0]=0;
        each_ch if(g[0][ch]!=-1) {
            f[g[0][ch]]=0;
            last[g[0][ch]]=-1;
            q.push(g[0][ch]);
        } else g[0][ch]=0;
        while(!q.empty()) {
            int now=q.front();q.pop();
            each_ch {
                int next=g[now][ch];
                if(next==-1) {g[now][ch]=g[f[now]][ch];continue;}
                int v=f[now];
                while(g[v][ch]==-1) v=f[v];
                f[next]=g[v][ch];
                last[next]=OK[f[next]]?f[next]:last[f[next]];
                q.push(next);
            }
        }
    }
    
    int dp[MAXN][MAXM];
    int query(char S[],int n)
    {
        dp[0][0]=0;
        fromto(1,trie_len-1,j) dp[0][j]=INF;
        fromto(1,n,i) {
            fromto(0,trie_len-1,j) dp[i][j]=INF;
            fromto(0,trie_len-1,j) each_ch if(!OK[g[j][ch]] && last[g[j][ch]]==-1)
                dp[i][g[j][ch]]=min(dp[i][g[j][ch]],dp[i-1][j]+(ch!=getnum(S[i])));
        }
        int ans=INF;
        fromto(0,trie_len-1,j) if(!OK[j])
        {
            ans=min(ans,dp[n][j]);
            //printf("dp[n][%d]=%d ",j,dp[n][j]);
        }
        //printf("\n");
        return ans;
    }
}

int main()
{
    int casecnt=0;
    while(true) {
        int k;
        scanf("%d",&k);
        if(k==0) break;
        ac::init();
        static char S[MAXM];
        fromto(1,k,i) {
            scanf("%s",S+1);
            ac::insert(S,strlen(S+1));
        }
        ac::getfail();
        scanf("%s",S+1);
        int ans=ac::query(S,strlen(S+1));
        printf("Case %d: %d\n",++casecnt,(ans>=INF)?-1:ans);
    }
    return 0;
}
