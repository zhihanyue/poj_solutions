//By YZH
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXN 50008
#define MAXQ 200008
#define fromto(from,to,i) for(int i=(from);i<=(to);++i)
struct Query{int L,R,pos;} B[MAXQ];
int B_ans[MAXQ],A[MAXN],N,Q;
int s1[MAXN],s1_pos[MAXN]; int s1_end=0;
int s2[MAXN],s2_pos[MAXN]; int s2_end=0;
bool cmpR(const Query &a,const Query &b){return a.R<b.R;}
bool cmp_pos(const Query &a,const Query &b){return a.pos<b.pos;}
int main() {
    scanf("%d%d",&N,&Q);
    fromto(1,N,i) scanf("%d",&A[i]);
    fromto(1,Q,i){scanf("%d%d",&B[i].L,&B[i].R);B[i].pos=i;}
    sort(B+1,B+Q+1,cmpR);
    int now=0;
    fromto(1,Q,i) {
        fromto(now+1,B[i].R,j) {
            while(s1_end>0 && s1[s1_end-1]<=A[j]) --s1_end;
            s1[s1_end]=A[j]; s1_pos[s1_end++]=j;
            while(s2_end>0 && s2[s2_end-1]>=A[j]) --s2_end;
            s2[s2_end]=A[j]; s2_pos[s2_end++]=j;
        }
        now=B[i].R;
        B_ans[B[i].pos]=s1[lower_bound(s1_pos,s1_pos+s1_end,B[i].L)-s1_pos]
                         -s2[lower_bound(s2_pos,s2_pos+s2_end,B[i].L)-s2_pos];
    }
    fromto(1,Q,i) printf("%d\n",B_ans[i]);
    return 0;
}
