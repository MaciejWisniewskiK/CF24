#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define ALL(a) begin(a), end(a)

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

// ------------------------------------------------

constexpr long long inf = 1e18;
constexpr int MAXN = 1e6;
int n;

bool check(long long val, const vector<ll> &v) {
    //if (val <= 100)
     //   cout << val << "\n";

    vi reach(n + 2);
    int pt = 0;
    ll csum = 0;
    for (int i = 1; i <= n + 1; i++) {
        csum += v[i];
        while (csum > val) {
            pt++;
            csum -= v[pt];
        }
        reach[i] = pt;
    }

    vector<ll> dp(n + 2);
    deque<pair<int, ll> > monoq;

    dp[0] = 0;
    monoq.pb({0, 0});
    for (int i = 1; i <= n + 1; i++) {
        
        while (monoq.back().fi < reach[i - 1]) 
            monoq.pop_back();
        
        dp[i] = v[i] + monoq.back().se;

        while (!monoq.empty() && monoq.front().se >= dp[i])
            monoq.pop_front();
        
        monoq.push_front({i, dp[i]});
    }

    /*if (val == 27) {
        for (int i = 0; i < n + 2; i++) {
            cout << v[i] << " " << reach[i] << " " << dp[i] << "\n";
        }
    }*/

    return (dp[n + 1] <= val);
}

long long bs(const vector<ll>& v) {
    long long p = 0, k = inf, s;

    while (k - p > 1) {
        s = (p + k) / 2;

        if (check(s, v))
            k = s;
        else
            p = s;
    }

    return k;
}


void solve() {
    cin >> n;
    vector<ll> v(n + 2, 0);

    for (int i = 1; i <= n; i++)
        cin >> v[i];

    cout << bs(v) << "\n";
}

// ------------------------------------------------

int main() {
    int tcase = 1; 
    cin >> tcase;
    while (tcase--) {
        solve();
    }
    return 0;
}