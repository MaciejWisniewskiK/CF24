#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define ALL(a) begin(a), end(a)

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int inf = 1e9;
constexpr int MAXN = 2e5;
int n, k;

vi dp[MAXN][1];
vi sons[MAXN];

int stsz[MAXN];
int write_to[MAXN];

int depth[MAXN];

void dfs1(int w) {
    stsz[w] = 1;
    write_to[w] = w;

    for (int i = 0; i < sons[w].size(); i++) {
        depth[sons[w][i]] = depth[w] + 1;
        dfs1(sons[w][i]);
        stsz[w] += stsz[sons[w][i]];

        if (stsz[sons[w][i]] > stsz[sons[w][0]])
            swap(sons[w][i], sons[w][0]);
    }
}


void dfs2(int w) {
    if (!sons[w].empty())
        write_to[sons[w][0]] = write_to[w];

    for (int i = 0; i < sons[w].size(); i++) {
        dfs2(sons[w][i]);        
    }
}

void dfs3(int w) {
    if (sons[w].empty()) {
        dp[write_to[w]][0].pb(0);
        dp[write_to[w]][0].pb(0);
        return;
    }

    for (int s : sons[w])
        dfs3(s);

    for (int i = 1;  i < sons[w].size(); i++) {
        for (int j = 0; j < dp[sons[w][i]][0].size(); j++) {
            for (int k = 0; k < dp[write_to[w]][0].size(); k++) {

                while (k + j + 1 >= dp[write_to[w]][0].size()) {
                    dp[write_to[w]][0].pb(inf);
                    dp[write_to[w]][1].pb(inf);
                }
                
                dp[write_to[w]][0][k + j] = min(dp[write_to[w]][0][k + j], dp[write_to[w]][0][k] + dp[write_to[sons[w][i]]][0][j] + 2);
            }
        }
    }
}

int main() {
    cin >> n >> k;
    vi par(n + 1);

    for (int i = 2; i <= n; i++) {
        cin >> par[i];
        sons[par[i]].pb(i);
    }

    dfs1(1);
    dfs2(1);
    return 0;
}