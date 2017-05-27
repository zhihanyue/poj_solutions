#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
using namespace std;

struct T_val
{
    int K,P;
    bool operator==(const T_val &other) const
    {
        return P==other.P;
    }
    bool operator>(const T_val &other) const
    {
        return P>other.P;
    }
};

struct Node
{
    Node *c[2];
    T_val val;
    int pri,cnt;
    Node(T_val v)
    {
        c[0]=c[1]=0;
        cnt=1;
        val=v;
        pri=rand();
    }
    int cmp(T_val x) const
    {
        return x==val?-1:(x>val);
    }
} *root=0;

void rotate(Node *&o,bool w)
{
    Node *k=o->c[!w];
    o->c[!w]=k->c[w];
    k->c[w]=o;
    o=k;
}

void insert(Node *&o,T_val v)
{
    if(o==0)
    {
        o=new Node(v);
        return;
    }
    int w=o->cmp(v);
    if(w==-1)
        ++o->cnt;
    else
    {
        insert(o->c[w],v);
        if(o->pri < o->c[w]->pri)
            rotate(o,!w);
    }
}

void remove(Node *&o,T_val v)
{
    if(o==0)
        return;
    int w=o->cmp(v);
    if(w!=-1)
        return remove(o->c[w],v);
    if(o->cnt>1)
        --o->cnt;
    else if(o->c[0]==0 || o->c[1]==0)
    {
        Node *k=o->c[o->c[0]==0];
        delete o;
        o=k;
    }
    else
    {
        int w=o->c[0]->pri > o->c[1]->pri;
        rotate(o,w);
        remove(o->c[w],v);
    }
}

T_val t_m(Node *o,int w)
{
    while(o->c[w])
        o=o->c[w];
    return o->val;
}

int main()
{
    srand(time(0));
    while(true)
    {
        int N;
        scanf("%d",&N);
        if(N==0)
            break;
        else if(N==1)
        {
            T_val T;
            scanf("%d%d",&T.K,&T.P);
            insert(root,T);
        }
        else if(N==2)
        {
            if(root==0)
                printf("0\n");
            else
            {
                T_val m=t_m(root,1);
                printf("%d\n",m.K);
                remove(root,m);
            }
        }
        else if(N==3)
        {
            if(root==0)
                printf("0\n");
            else
            {
                T_val m=t_m(root,0);
                printf("%d\n",m.K);
                remove(root,m);
            }
        }
    }
    return 0;
}
