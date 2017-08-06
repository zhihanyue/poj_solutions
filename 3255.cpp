#include <iostream>
#include <climits>
#include <vector>
#include <queue>
using namespace std;
vector<pair<int,int> > G[5008];
queue<int> q;
bool inq[5008];
int d[5008],d1[5008];

int main()
{
    int N,R;
    cin >> N >> R;
    for(int i=1;i<=R;++i)
    {
        int A,B,D;
        cin >> A >> B >> D;
        G[A].push_back(make_pair(B,D));
        G[B].push_back(make_pair(A,D));
    }
    
    for(int i=1;i<=N;++i)
        d[i]=d1[i]=INT_MAX/2;
    d[1]=0;
    q.push(1);
    inq[1]=true;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        inq[u]=false;
        for(int i=0,size=G[u].size();i<size;++i)
        {
            int v=G[u][i].first,D=G[u][i].second;
            if(d[v]>d[u]+D)
            {
                d1[v]=d[v];
                d[v]=d[u]+D;
                if(!inq[v])
                {
                    q.push(v);
                    inq[v]=true;
                }
            }
            else if(d[v]!=d[u]+D && d1[v]>d[u]+D)
            {
                d1[v]=d[u]+D;
                if(!inq[v])
                {
                    q.push(v);
                    inq[v]=true;
                }
            }
            else if(d[v]!=d1[u]+D && d1[v]>d1[u]+D)
            {
                d1[v]=d1[u]+D;
                if(!inq[v])
                {
                    q.push(v);
                    inq[v]=true;
                }
            }
        }
    }
    cout << d1[N] << endl;
    return 0;
}
