#include <iostream>
#include <climits>
#include <queue>
#include <vector>
using namespace std;

vector<pair<int,int> > G[1008];
int d[1008];
queue<int> q;
bool inq[1008];
int inqcnt[1008];

int main()
{
    int N,ML,MD;
    cin >> N >> ML >> MD;
    for(int i=1;i<=ML;++i)
    {
        int A,B,D;
        cin >> A >> B >> D;
        G[A].push_back(make_pair(B,D));
    }
    for(int i=1;i<=MD;++i)
    {
        int A,B,D;
        cin >> A >> B >> D;
        G[B].push_back(make_pair(A,-D));
    }
    for(int i=2;i<=N;++i)
        G[i].push_back(make_pair(i-1,0));
    d[1]=0;
    for(int i=2;i<=N;++i)
        d[i]=INT_MAX;
    q.push(1);
    inq[1]=true;
    ++inqcnt[1];
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        inq[u]=false;
        for(int i=0,size=G[u].size();i<size;++i)
        {
            int v=G[u][i].first,w=G[u][i].second;
            if(d[v]>d[u]+w)
            {
                d[v]=d[u]+w;
                if(!inq[v])
                {
                    q.push(v);
                    inq[v]=true;
                    ++inqcnt[v];
                    if(inqcnt[v]>=N)
                    {
                        cout << -1 << endl;
                        return 0;
                    }
                }
            }
        }
    }
    if(d[N]==INT_MAX)
        cout << -2 << endl;
    else cout << d[N] << endl;
    //system("pause");
    return 0;
}
