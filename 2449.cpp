#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX = 1005;
int n,m;
int start,end,k;
struct Edge
{
    int w;
    int to;
    int next;
};
Edge e[100005];
int head[MAX],edgeNum;
int dis[MAX];   //dis[i]表示从i点到end的最短距离
bool vis[MAX];
int cnt[MAX];
vector<Edge> opp_Graph[MAX];

struct Node
{
    int f,g;    //f = g+dis[v]
    int v;      //当前到达的节点
    Node(int a, int b,int c):f(a),g(b),v(c){}
    bool operator < (const Node& a) const
    {
        return a.f < f;
    }
};

void addEdge(int from, int to, int w)
{
    e[edgeNum].to = to;
    e[edgeNum].w = w;
    e[edgeNum].next = head[from];
    head[from] = edgeNum++;
}

void dijikastra(int start)
{
    int i;
    memset(vis,0,sizeof(vis));
    for(i = 1; i <= n; i++)
        dis[i] = INF;
    dis[start] = 0;
    priority_queue<Node> que;
    que.push(Node(0,0,start));
    Node next(0,0,0);
    while(!que.empty())
    {
        Node now = que.top();
        que.pop();
        if(vis[now.v])              //从集合T中选取具有最短距离的节点
            continue;
        vis[now.v] = true;          //标记节点已从集合T加入到集合S中
        for(i = 0; i < opp_Graph[now.v].size(); i++)    //更新从源点到其它节点(集合T中)的最短距离
        {
            Edge edge = opp_Graph[now.v][i];
            if(!vis[edge.to] && dis[now.v] + edge.w < dis[edge.to])     //加不加前面的判断无所谓
            {
                dis[edge.to] = dis[now.v] + edge.w;
                next.f = dis[edge.to];
                next.v = edge.to;
                que.push(next);
            }
        }
    }
}

int A_Star()
{
    int i;
    priority_queue<Node> que;
    if(dis[start] == INF)
        return -1;
    que.push(Node(dis[start],0,start));
    Node next(0,0,0);
    while(!que.empty())
    {
        Node now = que.top();
        que.pop();
        cnt[now.v]++;
        if(cnt[end] == k)
            return now.f;
        if(cnt[now.v] > k)
            continue;
        for(i = head[now.v]; i != -1; i = e[i].next)
        {
            next.v = e[i].to;
            next.g = now.g + e[i].w;
            next.f = next.g + dis[e[i].to];
            que.push(next);
        }
    }
    return -1;
}

int main()
{
    int i;
    int from,to,w;
    edgeNum = 0;
    memset(head,-1,sizeof(head));
    memset(opp_Graph,0,sizeof(opp_Graph));
    memset(cnt,0,sizeof(cnt));
    scanf("%d %d",&n,&m);
    Edge edge;
    for(i = 1; i <= m; i++)
    {
        scanf("%d %d %d",&from,&to,&w);
        addEdge(from,to,w);
        edge.to = from;
        edge.w = w;
        opp_Graph[to].push_back(edge);
    }
    scanf("%d %d %d",&start,&end,&k);
    if(start == end)
        k++;
    dijikastra(end);
    int result = A_Star();
    printf("%d\n",result);
    return 0;
}
