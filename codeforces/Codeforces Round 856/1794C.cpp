#include<bits/stdc++.h>

#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define pii pair<int,int>
#define pdd pair<double,double>
#define endl "\n"

using namespace std;
typedef long long ll;
const ll MOD=2e9+7;
const ll MAXN=5e6+5;
const ll INF=0x7f7f7f7f;


void solve(){
    int n;cin >> n;
    vector<int> a(n);
    fori(0,n)cin >> a[i];
    vector<int> res;
    fori(0,n){
        int l = 1, r = i + 1;
        while(l <= r){
            int m = (l + r) / 2;
            if(a[i - m + 1] >= m){
                l = m + 1;
            }else{
                r = m - 1;
            }
        }
        res.push_back(r);
    }
    fori(0,n)cout << res[i] << ' ';
    cout << endl;
}

int main(){
//    cin.tie(0);
//    ios::sync_with_stdio(false);
    int t;cin >> t;
    while(t--)
        solve();
    return 0;
}



