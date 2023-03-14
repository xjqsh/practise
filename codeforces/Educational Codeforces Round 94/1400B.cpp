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
    ll p,f;cin >> p >> f;
    ll cnts,cntw;cin >> cnts >> cntw;
    ll s,w;cin >> s >> w;
    ll ans=0;
    fori(0,cnts+1){
        if(i*s>p)break;
        ll cw=min((p-i*s)/w,cntw);
        ll rs=cnts-i,rw=cntw-cw;
        ll fs,fw;
        if(s<w){
            fs = min(rs,f/s);
            fw = min(rw,(f-fs*s)/w);
        }else{
            fw = min(rw,f/w);
            fs = min(rs,(f-fw*w)/s);
        }
        ans = max(ans,i+cw+fs+fw);
    }
    cout << ans << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int t;cin >> t;
    while(t--)
        solve();
    return 0;
}





