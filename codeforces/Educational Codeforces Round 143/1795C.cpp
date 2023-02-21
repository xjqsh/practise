/** Educational Codeforces Round 143 (Rated for Div. 2)<br>
 * C.Tea Tasting<br>
 * 求前缀和品茶者饮茶数量的前缀和,再二分查找每一杯茶<br>
 * 会被第几个人喝完,得到一个每个人喝了几口的差分数组m,<br>
 * 和最后一个人喝到的剩下的茶的量r,然后还原差分,答案就是b[i]*m[i]+r[i]
 * 主要考场二分和前缀和*/

#include<bits/stdc++.h>

#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define pii pair<int,int>
#define pdd pair<double,double>

using namespace std;
typedef long long ll;
const ll MOD=998244353;
const ll MAXN=2e5+5;
const ll INF=0x7f7f7f7f;

inline ll add(ll a,ll b){
    return (a+b)%MOD;
}
inline ll mul(ll a,ll b){
    return (a%MOD*(b%MOD))%MOD;
}
inline ll sub(ll a,ll b){
    return (a%MOD-b%MOD+MOD)%MOD;
}
ll mpow(ll a,ll b){
    ll am=a%MOD;
    ll result=1;
    while(b){
        if (b&1) result=result*am%MOD;
        am=am*am%MOD;
        b>>=1;
    }
    return result;
}
ll dv(ll a,ll b){
    return mul(a,mpow(b,MOD-2));
}
ll permute[MAXN],inv[MAXN];
void comb_init(){
    permute[0]=1;inv[0]=1;
    for (int i=1; i<MAXN; ++i){
        permute[i]=mul(permute[i-1],i);
        inv[i]=mpow(permute[i],MOD-2);
    }
}
inline ll perm(ll a,ll b){
    if(a<b) swap(a,b);
    return mul(permute[a],inv[a-b]);
}
inline ll comb(ll a,ll b){
    if(a<b) swap(a,b);
    return mul(mul(permute[a],inv[b]),inv[a-b]);
}

void solve(){
    int n;cin >> n;
    comb_init();
    ll ans=comb(n/3,n/6);
    fori(1,n/3+1){
        vector<int> v(3);
        forj(0,3)cin >> v[j];

        sort(v.begin(),v.end());
        if(v[0]==v[1] && v[1]==v[2])
            ans=mul(ans,3);
        else if(v[0]==v[1])
            ans=mul(ans,2);
    }
    cout << ans << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
//    int t;cin >> t;
//    while(t--)
        solve();
    return 0;
}
