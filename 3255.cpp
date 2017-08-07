#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

const int MAX_N = 5000 + 10;
struct Edge
{
    int nE;
    int nDis;
    Edge(int e, int d):nE(e), nDis(d) {}
};
vector<Edge> graph[MAX_N];
bool bVisit[MAX_N];
int nSDis[MAX_N];
int nEDis[MAX_N];

struct Node
{
    int nN;
    int nDis;

    bool operator < (const Node& node) const
    {
        return nDis > node.nDis;
    }
};

int ShortestPath(int nS, int nE, int* nDis, int nN)
{
    priority_queue<Node> pq;
    memset(bVisit, false, sizeof(bVisit));
    for (int i = 1; i <= nN; i++)
    {
        nDis[i] = 0x7fffffff;
    }
    nDis[nS] = 0;
    Node head;
    head.nDis = 0, head.nN = nS;
    pq.push(head);

    while (pq.empty() == false)
    {
        Node head = pq.top();
        pq.pop();
        int nU = head.nN;
        if (bVisit[nU]) continue;
        bVisit[nU] = true;

        for (int i = 0; i < graph[nU].size(); ++i)
        {
            int nV = graph[nU][i].nE;
            int nLen = head.nDis + graph[nU][i].nDis;
            if (nLen < nDis[nV])
            {
                nDis[nV] = nLen;
                Node node;
                node.nDis = nLen;
                node.nN = nV;
                pq.push(node);
            }
        }
    }
   
    return nDis[nE];
}

int Second(int nS, int nE, int nN)
{
    int nShortest = ShortestPath(nS, nE, nSDis, nN);
    ShortestPath(nE, nS, nEDis, nN);

    int nAns = 0x7fffffff;

    for (int i = 1; i <= nN; ++i)
    {
        for (int j = 0; j < graph[i].size(); ++j)
        {
            int nU = i;
            int nV = graph[i][j].nE;
            int nLen = nSDis[i] + graph[i][j].nDis + nEDis[nV];
            if (nLen != nShortest)
            {
                nAns = min(nAns, nLen);
            }
        }
    }

    return nAns;
}

int main()
{
    int nN, nR;
    int nA, nB, nD;

    while (scanf("%d%d", &nN, &nR) == 2)
    {
        for (int i = 1; i <= nN; ++i)
        {
            graph[i].clear();
        }

        while (nR--)
        {
            scanf("%d%d%d", &nA, &nB, &nD);
            graph[nA].push_back(Edge(nB, nD));
            graph[nB].push_back(Edge(nA, nD));
        }
        printf("%d\n", Second(1, nN, nN));
    }
    return 0;
}
