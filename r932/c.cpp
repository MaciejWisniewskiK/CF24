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

constexpr int inf = 1e9;
constexpr int MAXN = 2e3 + 7;


void solve() {
    int n; ll l;
    cin >> n >> l;
    vector <pii> v;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.pb({b, a});
    }
    v.pb({-1, 0});
    sort(ALL(v));

    int res = 0;

    for (int tail = 1; tail <= n; tail++) {
        ll bonus = 0;
        priority_queue <ll> pq;
        ll pq_sum = 0;
        for (int head = tail; head <= n; head++) {
            if (head > tail)
                bonus = abs(v[head].fi - v[tail].fi);
            
            pq.push(v[head].se); // * -1
            pq_sum += v[head].se;

            while (!pq.empty() && pq_sum + bonus > l) {
                pq_sum -= pq.top(); // * -1
                pq.pop();
            }

            if (pq_sum + bonus <= l)
                res = max(res, (int)pq.size());
            else
                break;
        }
    }

    cout << res << "\n";
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