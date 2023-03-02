/** Educational Codeforces Round 144 (Rated for Div. 2)<br>
 * C. Maximum Set<br>
 * 神奇的思路题，具体在底下注释里*/

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
    int l, r;
    cin >> l >> r;
    int max_size = 1;
    // 看看最多能乘几个2，最大长度一定是l最多乘几个2仍然小于r
    while((l << max_size) <= r)
        max_size++;
    // 1 << (max_size - 1) l是被2乘的倍数
    // r / (1 << (max_size - 1) 是l到r中乘以最大倍数不超过r的数
    // 则此时的ans2是至多从几个数开始乘可以达到长度最大值
    int ans2 = (r / (1 << (max_size - 1)) - l + 1);
    // 如果最大长度大于1，尝试把2换成3
    // 最多只能换一个，因为两个3一定可以换成3个2，不符合最大的要求
    if(max_size > 1)
        ans2 += (max_size - 1) * max(0, (r / (1 << (max_size - 2)) / 3 - l + 1));
    cout << max_size << " " << ans2 << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;cin >> t;
    while (t--)
        solve();
    return 0;
}

