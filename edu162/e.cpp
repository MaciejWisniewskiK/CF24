#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back

void dfs1(const vector<vi> &graph, vi &tree_siz, vi &big_son, int w, int fat) {
    tree_siz[w] = 1;

    for (int s : graph[w]) {
        if (s == fat) continue;
        
        dfs1(graph, tree_siz, big_son, s, w);
        tree_siz[w] += tree_siz[s];

        if (tree_siz[s] > tree_siz[big_son[w]])
            big_son[w] = s;
    }
}

void dfs2(const vector<vi> &graph, const vi &big_son, vi &head, int w, int fat) {
    if (big_son[w] == 0) return;

    for (int s : graph[w]) {
        if (s == fat) continue;
        if (s == big_son[w]) continue;
        head[s] = s;
        dfs2(graph, big_son, head, s, w);
    }

    head[big_son[w]] = head[w];
    dfs2(graph, big_son, head, big_son[w], w);
}

void dfs3_for_noobs(const vi &ogcol, const vector<vi> &graph, const vi &big_son, const vi &head, int w, int fat, map <int, int> &colors, ll &res);
map<int,int> dfs3(const vi &ogcol, const vector<vi> &graph, const vi &big_son, const vi &head, int w, int fat, ll &res) {
    map<int, int> mapa;
    dfs3_for_noobs(ogcol, graph, big_son, head, w, fat, mapa, res);
    return mapa;
}

void dfs3_for_noobs(const vi &ogcol, const vector<vi> &graph, const vi &big_son, const vi &head, int w, int fat, map <int, int> &colors, ll &res) {
    if (big_son[w] == 0) {
        colors[ogcol[w]] = 1;
        return;
    }
    dfs3_for_noobs(ogcol, graph, big_son, head, big_son[w], w, colors, res);
    res += colors[ogcol[w]];
    colors[ogcol[w]] = 1;

    for (int s : graph[w]) {
        if (s == fat) continue;
        if (s == big_son[w]) continue;

        map<int, int> noobmap = dfs3(ogcol, graph, big_son, head, s, w, res);
        for (auto elem : noobmap) {
            if (elem.first != ogcol[w]) {
                res += (ll)colors[elem.first] * (ll)elem.second;
                colors[elem.first] += elem.second;
            }
            else
                res += elem.second;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vi col(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> col[i];
    vector<vi> graph(n+1);

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    
    vi tree_siz(n+1,0);
    vi big_son(n+1, 0);
    dfs1(graph, tree_siz, big_son, 1, 0);

    vi head(n+1, 0);
    head[1] = 1;

    dfs2(graph, big_son, head, 1, 0);

    ll res = 0;
    dfs3(col, graph, big_son, head, 1, 0, res);

    cout << res << "\n";
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

