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
    int pri;
    int cnt;
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
};
Node *root=0;

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
        o=new Node(v);
    else
    {
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
    else if(o->c[0]==0)
    {
        Node *k=o->c[1];
        delete o;
        o=k;
    }
    else if(o->c[1]==0)
    {
        Node *k=o->c[0];
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

Node* find(Node *o,T_val v)
{
    if(o==0)
        return 0;
    int w=o->cmp(v);
    if(w==-1)
        return o;
    else return find(o->c[w],v);
}

Node* t_m(Node *o,int w)
{
    while(o->c[w])
        o=o->c[w];
    return o;
}

int main()
{
/*  insert(root,453);
    insert(root,78);
    insert(root,521);
    insert(root,46853);
    printf("%d\n",t_m(root,1)->val);
    remove(root,46853);
    printf("%d\n",t_m(root,1)->val);
    system("pause");*/
    srand(time(0));
    while(true)
    {
        int N;
        scanf("%d",&N);
        if(N==0)
            break;
        else if(N==1)
        {
            int K,P;
            scanf("%d%d",&K,&P);
            insert(root,(T_val){K,P});
        }
        else if(N==2)
        {
            if(root==0)
                printf("0\n");
            else
            {
                T_val m=t_m(root,1)->val;
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
                T_val m=t_m(root,0)->val;
                printf("%d\n",m.K);
                remove(root,m);
            }
        }
    }
    return 0;
}
