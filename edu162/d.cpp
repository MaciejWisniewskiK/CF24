#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define f first
#define s second
#define inf 1000000007

int binl(const vll& sum, int ind, ll val) {
    int p = 0, k = ind;
    while (k - p > 1) {
        int s = (p + k) / 2;
        if (sum[ind - 1] - sum[s - 1] > val)
            p = s;
        else
            k = s;
    }

    return p;
}

int binr(const vll& sum, int ind, ll val, int n) {
    int p = ind, k = n + 1;
    while (k - p > 1) {
        int s = (p + k) / 2;
        if (sum[s] - sum[ind] > val)
            k = s;
        else
            p = s;
    }

    return k;
}

void solve() {
    int n;
    cin >> n;

    vll v(n + 2);
    vll sum(n + 2); 
    vi prev_diff(n + 2);
    vi next_diff(n + 2);

    sum[0] = 0;
    
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        sum[i] = sum[i - 1] + v[i];

        prev_diff[i] = (v[i] == v[i - 1] ? prev_diff[i - 1] : i - 1);
    }

    sum[n + 1] = sum[n];

    for (int i = n; i >= 1; i--)
        next_diff[i] = (v[i] == v[i + 1] ? next_diff[i + 1] : i + 1);

    
    // answer querries
    for (int i = 1; i <= n; i++) {
        int min_steps = inf;
        //check left
        if (v[i - 1] > v[i]) {
            cout << "1 ";
            continue;
        }
        if (!(sum[i - 1] <= v[i] || prev_diff[i - 1] == 0)) {
            int curr = binl(sum, i, v[i]);
            curr = min(curr, prev_diff[i - 1]);
            min_steps = min(min_steps, i - curr);
        }

        //check right
        if (v[i + 1] > v[i]) {
            cout << "1 ";
            continue;
        }
        if (!(sum[n + 1] - sum[i] <= v[i] || next_diff[i + 1] == n + 1)) {
            int curr = binr(sum, i, v[i], n);
            curr = max(curr, next_diff[i + 1]);
            min_steps = min(min_steps, curr - i);
        }

        if (min_steps == inf)
            cout << "-1 ";
        else
            cout << min_steps << " ";
    }

    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int tcase = 1;
    cin >> tcase;
    while (tcase--) {
        solve();
    }

    return 0;
}

