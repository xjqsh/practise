/** Educational Codeforces Round 144 (Rated for Div. 2)<br>
 * B. Asterisk-Minor Template
 * 贪一下就行了，只有头尾相同，或者有连续两个字符相同的情况才有解<br>
 * 有笨比因为字符串长度wa6次，我不说是谁*/

#include<bits/stdc++.h>

#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define pii pair<int,int>
#define pdd pair<double,double>
#define endl "\n"

using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
const ll MAXN=2e5+5;
const ll INF=0x7f7f7f7f;

void solve(){
    string a,b;cin >> a >> b;
    int l1 = a.size();
    int l2 = b.size();
    if(a[0]==b[0]){
        cout << "YES\n" << a[0] << "*\n";
        return;
    }
    if(a[l1-1]==b[l2-1]){
        cout << "YES\n*" << a[l1-1] << "\n";
        return;
    }
    string ans;
    fori(0,l1-1){
        forj(0,l2-1){
            if(a[i]==b[j] && a[i+1]==b[j+1]){
                ans.push_back('*');
                ans.push_back(a[i]);
                ans.push_back(a[i+1]);
                ans.push_back('*');
                cout << "YES\n" << ans << "\n";
                return;
            }
        }
    }
    cout << "NO" << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;cin >> t;
    while(t--)
        solve();
    return 0;
}

