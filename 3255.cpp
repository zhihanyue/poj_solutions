#include <iostream>
#include <cstdio>
#include <climits>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
vector<pair<int,int> > G[5008];
queue<int> q;
bool inq[5008];
long long d[5008],d1[5008];

int main()
{
    int N,R;
    while(scanf("%d%d", &N, &R) == 2)
    {
        for(int i=1;i<=N;++i)
            G[i].clear();
        memset(inq,false,sizeof(inq));
        
        for(int i=1;i<=R;++i)
        {
            int A,B,D;
            cin >> A >> B >> D;
            G[A].push_back(make_pair(B,D));
            G[B].push_back(make_pair(A,D));
        }
        
        for(int i=1;i<=N;++i)
            d[i]=d1[i]=INT_MAX-3;
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
    //              cout << v << ' ' << "d-" << u << '=' << d[u] << ' ' << D << endl;
                    d1[v]=d[u]+D;
                    if(!inq[v])
                    {
                        q.push(v);
                        inq[v]=true;
                    }
                }
                else if(d[v]!=d1[u]+D && d1[v]>d1[u]+D)
                {
    //              cout << v << ' ' << "d1-" << u << '=' << d1[u] << ' ' << D << endl;
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
    }
/*
5 5
1 2 100
2 3 100
3 4 100
2 4 5
4 5 2
*/
    //system("pause");
    return 0;
}
