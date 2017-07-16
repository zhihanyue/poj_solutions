#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 200008
#define fromto(from,to,i) for(int (i)=(from);(i)<=(to);++(i))
#define fromdownto(from,to,i) for(int (i)=(from);(i)>=(to);--(i))
#define watch(a,n) for(int __i=0;__i<(n);++__i) printf("[%d]=%d ",__i,(a)[__i]);printf("\n");
using namespace std;
typedef pair<int,int> sta;
int A[MAXN],A_len;
int B[MAXN],B_len;

int sa[MAXN],rank[2*MAXN],k_len;

void jssort(int arr[],int n)
{
    int k=n;//要根据题目不同来设定 
    static int js[MAXN],newarr[MAXN];
    //memset(js,0,sizeof(js));
    fromto(1,n,i) ++js[rank[arr[i]+k_len]];
    fromto(1,k,i) js[i]+=js[i-1];//千万别令from=2，这样少了为0的情况！！！ 
    fromto(1,n,i) newarr[js[rank[arr[i]+k_len]]--]=arr[i];
    
    //memset(js,0,sizeof(js));
    fromto(1,n,i) ++js[rank[newarr[i]]];
    fromto(1,k,i) js[i]+=js[i-1];
    fromdownto(n,1,i) arr[js[rank[newarr[i]]]--]=newarr[i];
}

bool cmp_init(int x,int y){return B[x]<B[y];}
bool cmp(int x,int y){return rank[x]<rank[y] || (rank[x]==rank[y] && rank[x+k_len]<rank[y+k_len]);}

void getsa(int arr[],int n)
{
    memset(sa,0,sizeof(sa)); 
    memset(rank,0,sizeof(rank));
    fromto(1,n,i) sa[i]=i;
    sort(sa+1,sa+n+1,cmp_init);
    rank[sa[1]]=1;
    fromto(2,n,i) rank[sa[i]]=rank[sa[i-1]]+cmp_init(sa[i-1],sa[i]);
    
    for(k_len=1;k_len<=n;k_len*=2) {
        jssort(sa,n);
        static int newrank[2*MAXN];
        newrank[sa[1]]=1;
        fromto(2,n,i) newrank[sa[i]]=newrank[sa[i-1]]+cmp(sa[i-1],sa[i]);
        fromto(1,n,i) rank[i]=newrank[i];
    }
}

int main()
{
    scanf("%d",&A_len);
    fromto(1,A_len,i) scanf("%d",&A[i]);
    reverse_copy(A+1,A+A_len+1,B+1);
    B_len=A_len;
    getsa(B,B_len);
    
    fromto(1,B_len,i) if(sa[i]>2) {
        fromto(sa[i],B_len,j) printf("%d\n",B[j]);
        B_len=sa[i]-1;
        break;
    }
    fromto(1,B_len,i) B[i+B_len]=B[i];
    B_len*=2;
    getsa(B,B_len);
    
    fromto(1,B_len,i) if(sa[i]>1 && sa[i]<=B_len/2) {
        fromto(sa[i],sa[i]+B_len/2-1,j) printf("%d\n",B[j]);
        break;
    }
    return 0;
}
