/** Educational Codeforces Round 143 (Rated for Div. 2)<br>
 * C.Tea Tasting<br>
 * 求前缀和品茶者饮茶数量的前缀和,再二分查找每一杯茶<br>
 * 会被第几个人喝完,得到一个每个人喝了几口的差分数组m,<br>
 * 和最后一个人喝到的剩下的茶的量r,然后还原差分,答案就是b[i]*m[i]+r[i]
 * 主要考查了二分和前缀和*/

#include<bits/stdc++.h>

#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define pii pair<int,int>
#define pdd pair<double,double>

using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
const ll MAXN=2e5+5;
const ll INF=0x7f7f7f7f;

void solve(){
    int n;cin >> n;
    vector<ll> a(n+1),b(n+1),s(n+1);
    fori(1,n+1)cin >> a[i];
    fori(1,n+1)cin >> b[i];
    fori(1,n+1)s[i]=s[i-1]+b[i];
    vector<ll> m(n+1),p(n+1);
    fori(1,n+1){
        int pos = lower_bound(s.begin()+i,s.end(),a[i]+s[i-1])-s.begin();
        if(pos>i){
            m[i]++;
        }else{
            p[i]+=a[i];continue;
        }
        if(pos<=n){
            m[pos]--;
            p[pos]+=s[i-1];
            p[pos]-=s[pos-1];
            p[pos]+=a[i];
        }
    }
    ll mp=0;
    fori(1,n+1){
        mp+=m[i];
        cout << mp*b[i]+p[i] << ' ';
    }
    cout << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;cin >> t;
    while(t--)
        solve();
    return 0;
}
