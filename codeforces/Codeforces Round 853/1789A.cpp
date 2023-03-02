
#include<bits/stdc++.h>

#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define pii pair<int,int>
#define pdd pair<double,double>

using namespace std;
typedef long long ll;
const ll MOD=2e9+7;
const ll MAXN=4e6+5;
const ll INF=0x7f7f7f7f;

void solve(){
    int n,t;cin >> n >> t;
    vector<int> a(n+1),s(n+1);
    int ans=0;
    fori(1,n+1){
        cin >> a[i];
        s[i]=s[i-1]+a[i];
    }
    int l=1,r=1;
    while (r<=n){
        if(s[r]-s[l-1]<=t){
            ans=max(ans,r-l+1);
            r++;
        }else{
            l++;
        }
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
