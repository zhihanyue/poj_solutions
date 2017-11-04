#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Node{int dis,fuel;} zhan[10008];
priority_queue<int> q;

bool cmp(const Node &a,const Node &b)
{
    return a.dis>b.dis;
}

int main()
{
    int N,L,P;
    cin >> N;
    for(int i=1;i<=N;++i)
        cin >> zhan[i].dis >> zhan[i].fuel;
    zhan[++N]=(Node){0,0};
    cin >> L >> P;
    sort(zhan+1,zhan+N+1,cmp);
    int ans=0;
    for(int i=1;i<=N;++i)
    {
        while(L-P>zhan[i].dis)
        {
            if(q.empty())
            {
                cout << -1 << endl;
                return 0;
            }
            P+=q.top();
            q.pop();
            ++ans;
        }
        P-=L-zhan[i].dis;
        L=zhan[i].dis;
        q.push(zhan[i].fuel);
    }
    cout << ans << endl;
    return 0;
}
