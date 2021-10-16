#include <bits/stdc++.h>
#include <chrono>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
/*............................................................................*/ 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
/* find_by_order(x) give iterator of the index x 
   order_by_key(x) give the position where x will be placed*/
#define int long long
#define lop(i,a,b,c) for (int i=a;i<b;i+=c)
#define rlop(i,a,b,c) for (int i=a-1;i>=b;i-=c)
#define prii pair <int,int>
#define PB push_back
#define S second
#define F first
#define all(x) x.begin(),x.end()
#define vvii vector < vector < int > >
#define vii vector <int>
#define count_1(x) __builtin_popcount(x)
#define cn(a) scanf("%lld",&a);
#define cn_vl(arr,n) lop(i,0,n,1){scanf("%lld",arr+i);}
#define shw_vl(arr,n) lop(i,0,n,1){printf("%lld ",arr[i]);}printf("\n");
#define shw(CON) cout << &("NO\0YES"[3 * CON]) << '\n';
const int MAX=3e5+10;
const int mod=1e9+7;
/*......................................................................*/

void add_mod(int &a,int b){
  a+=b;
  if (a>=mod){
    a-=mod;
  }
}
void sub_mod(int &a,int b){
  a-=b;
  if (a<0){
    a+=mod;
  }
}
void mul_mod(int &a,int b){
  int z=a;
  int res=0;
  while (b>0){
    if (b&1)add_mod(res,z);
    add_mod(z,z);
    b>>=1;
  }
  a=res;
}
int po(int a,int b){
  int res=1;
  while (b>0){
    if (b&1)mul_mod(res,a);
    mul_mod(a,a);
    b>>=1;
  }
  return res;
}
void div_mod(int &a,int b){
  mul_mod(a,po(b,mod-2));
}
/****************************************************************************/
void fsc(int &number)
{
    bool negative = false;
    register int c;
    number = 0;
    c = getchar();
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
    if (negative)
        number *= -1;
}
int dp[160][160][310];
int arr[160][160][2];int n,m;
int f(int i,int j,int cn){
  if (cn>m)return INT_MIN;
  if ((i==n and j==n-1)){
    return 0;
  }
  if ((i==n-1 and j==n)){
    return 0;
  }
  if (i>=n or j>=n)return INT_MIN;
  if (dp[i][j][cn]!=-1)return dp[i][j][cn];
  int q=INT_MIN;
  
    if (arr[i][j][0]){
      q=max(q,arr[i][j][1]+max(f(i+1,j,cn+1),f(i,j+1,cn+1)));
    }
    else {
      if (cn==0 or cn==m)q=max(q,arr[i][j][1]+max(f(i+1,j,cn),f(i,j+1,cn)));
      else q=max(q,arr[i][j][1]+max(f(i+1,j,cn+1),f(i,j+1,cn+1)));
    }
  
  return dp[i][j][cn]=q;
}
void solve(){
  cn(n);cn(m);
  lop (i,0,n,1){
    lop (j,0,n,1){
    char a;cin>>a;
    arr[i][j][0]=1;
    if (a=='.')arr[i][j][0]=0;
    }
  }
  getchar();
  lop (i,0,n,1){
    lop (j,0,n,1){
    int a;fsc(a);
    arr[i][j][1]=a;
    lop (k,0,m+2,1)dp[i][j][k]=-1;
    }
  }
  int ans=f(0,0,0);
  if (ans<0){
    ans=-1;
  }
  printf("%lld\n",ans);
  
}
int32_t main(){
  int t;t=1;cn(t);
  while (t--){
    auto t_1=chrono::high_resolution_clock::now();
    solve();
    auto t_2=chrono::high_resolution_clock::now();
    // cout <<". Elapsed (ms): " << chrono::duration_cast<chrono::milliseconds>(t_2 - t_1).count() << endl;
  }
  return 0;
}