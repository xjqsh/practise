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
    int n,k;cin >> n >> k;
    string s,t;cin >> s >> t;
    if(n>=2*k){
        sort(s.begin(),  s.end());
        sort(t.begin(),  t.end());
        cout << (s==t ? "YES" : "NO") << endl;
    }else {
        int x=max(n-k,0);
        string a,b;
        fori(0,x){
            a.push_back(s[i]);
            b.push_back(t[i]);
        }
        fori(x,n-x){
            if(s[i]!=t[i]){
                cout << "NO" << endl;
                return;
            }
        }
        fori(n-x,n){
            a.push_back(s[i]);
            b.push_back(t[i]);
        }
        sort(a.begin(),  a.end());
        sort(b.begin(),  b.end());
        cout << (a==b ? "YES" : "NO") << endl;
    }

}

int main(){
//    cin.tie(0);
//    ios::sync_with_stdio(false);
    int t;cin >> t;
    while(t--)
        solve();
    return 0;
}



