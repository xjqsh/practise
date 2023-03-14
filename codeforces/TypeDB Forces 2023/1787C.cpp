/** TypeDB Forces 2023 (Div. 1 + Div. 2, Rated, Prizes!)<br>
 * C. Remove the Bracket<br>
 * dp，事实上每个数只有一种划分方式，所以对于每个位置只有两种状态，考虑状态转移*/

#include<bits/stdc++.h>

#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define pii pair<int,int>
#define pdd pair<double,double>
#define endl "\n"

using namespace std;
typedef long long ll;
const ll MOD=2e9+7;
const ll MAXN=4e6+5;
const ll INF=0x7f7f7f7f;

void solve(){
    ll n,s;cin >> n >> s;
    vector<vector<ll>> a(2,vector<ll>(n));
    cin >> a[0][0];a[1][0]=a[0][0];
    fori(1,n-1){
        ll x;cin >> x;
        if(x>=s){
            a[0][i]=s;
            a[1][i]=x-s;
        }else{
            a[0][i]=0;
            a[1][i]=x;
        }
    }
    cin >> a[0][n-1];a[1][n-1]=a[0][n-1];
    vector<vector<ll>> dp(2,vector<ll>(n));
    fori(1,n){
        dp[0][i] = min(dp[0][i-1]+a[1][i-1]*a[0][i],
                       dp[1][i-1]+a[0][i-1]*a[0][i]);
        dp[1][i] = min(dp[0][i-1]+a[1][i-1]*a[1][i],
                       dp[1][i-1]+a[0][i-1]*a[1][i]);
    }
    cout << max(dp[0][n-1],dp[1][n-1]) << endl;
}

int main(){
//    cin.tie(0);
//    ios::sync_with_stdio(false);
    int t;cin >> t;
    while(t--)
        solve();
    return 0;
}



