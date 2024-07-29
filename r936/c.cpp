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
constexpr int MAXN = 1e6;
int n, m, k, q;

int dfs(int w, int par, int x, vector <vi> &g, int &par_size_ret) {
    int subsiz = 1;
    int ret = 0;

    for (int s : g[w]) {
        if (s == par) continue;
        int son_size;
        ret += dfs(s, w, x, g, son_size);
        subsiz += son_size;
    }

    if (subsiz >= x) {
        subsiz = 0;
        ret++;
    }

    par_size_ret = subsiz;
    return ret;
}

int bs(vector <vi> &g) {
    int b = 1, e = n;

    while (e - b > 1) {
        m = (b + e) / 2;
        
        int xd;
        if (dfs(1, 0, m, g, xd) - 1 >= k)
            b = m;
        else    
            e = m;
    }

    return b;
}

void solve() {
    cin >> n >> k;

    vector <vi> graph(n + 1);
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].pb(b);
        graph[b].pb(a);
    }
    cout << bs(graph) << "\n";
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