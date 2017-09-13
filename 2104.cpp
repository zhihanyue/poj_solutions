#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXN 100008
#define fromto(from,to,i) for(int (i)=(from);(i)<=(to);++(i))
#define watch(a,n) for(int __i=0;__i<(n);++__i) printf("%d ",a[__i]);printf("\n");
int A[MAXN],B[MAXN];
struct Node {
    int cnt;
    Node *left,*right;
    Node(){}
    Node(int _cnt,Node *_left,Node *_right):cnt(_cnt),left(_left),right(_right){}
} nodes[100*MAXN];
int nodes_k=0;
Node *new_Node(int _cnt,Node *_left,Node *_right)
{
    return &(nodes[nodes_k++]=Node(_cnt,_left,_right));
}

void push_down(Node *o)
{
    //Equivalent transformation
    if(o->left==NULL) o->left=new_Node(0,NULL,NULL);
    if(o->right==NULL) o->right=new_Node(0,NULL,NULL);
    //Non-equivalent transformation(null)
    
}

void push_up(Node *o)
{
    o->cnt=o->left->cnt+o->right->cnt;
}

Node *newver(Node *o,int L,int r,int newval)
{
    if(newval<L || newval>=r) return o;
    if(L+1==r){return new_Node(o->cnt+1,NULL,NULL);}
    int M=L+(r-L)/2;
    push_down(o);
    Node *newnode=new_Node(0,newver(o->left,L,M,newval),newver(o->right,M,r,newval));
    push_up(newnode);
    return newnode;
}

int subkth(Node *o1,Node *o2,int L,int r,int k)//kth in (o1-o2)tree,must have kth!
{
    if(L+1==r) return L;
    int leftcnt=o1->left->cnt-o2->left->cnt;
    push_down(o1);push_down(o2);
    int M=L+(r-L)/2;
    if(k<=leftcnt)
        return subkth(o1->left,o2->left,L,M,k);
    else return subkth(o1->right,o2->right,M,r,k-leftcnt);
}

Node *Version[MAXN];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    fromto(1,n,i) {scanf("%d",&A[i]);B[i]=A[i];}
    sort(B+1,B+n+1);
    fromto(1,n,i) A[i]=lower_bound(B+1,B+n+1,A[i])-B;
    Version[0]=new_Node(0,NULL,NULL);
    fromto(1,n,i) Version[i]=newver(Version[i-1],1,n+1,A[i]);
    while(m--) {
        int L,R,k;
        scanf("%d%d%d",&L,&R,&k);
        printf("%d\n",(k>R-L+1)?-1:B[subkth(Version[R],Version[L-1],1,n+1,k)]);
    }
    return 0;
}
