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
    int n;cin >> n;
    int ans=n-1;
    string str;cin >> str;
    fori(0,n-2){
        if(str[i]==str[i+2])ans--;
    }
    cout << ans << endl;
}

int main(){
//    cin.tie(0);
//    ios::sync_with_stdio(false);
    int t;cin >> t;
    while(t--)
        solve();
    return 0;
}



