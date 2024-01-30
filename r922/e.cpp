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
int n;


void getp(vector <int> &ids) {
    for (int i = 1; i < ids.size(); i++)
        swap(ids[i], ids[rand() % i]);

    if (ids.empty()) return;
    if (ids.size() == 1) return;
    // set x
    char ans = 'x';
    while (ans != '=') {
        cout << "? " << ids[0] << "\n";
        cout.flush();
        cin >> ans;
    }

    vi smal, big;

    for (int i = 1; i < ids.size(); i++) {
        cout << "? " << ids[i] << "\n";
        cin >> ans;
        if (ans == '<')
            smal.pb(ids[i]);
        else
            big.pb(ids[i]);

        cout << "? " << ids[0] << "\n";
        cin >> ans;
    }

    getp(smal);
    getp(big);
    int mid = ids[0];

    for (int i = 0; i < smal.size(); i++)
        ids[i] = smal[i];
    ids[smal.size()] = mid;
    for (int i = 0; i < big.size(); i++)
        ids[i + smal.size() + 1] = big[i];
}

void solve() {
    cin >> n;
    vi per(n);
    iota(ALL(per), 1);

    getp(per);

    vi v(n);
    for (int i = 0; i < n; i++)
        v[per[i] - 1] = i + 1;
    cout << "! ";
    for (int i : v)
        cout << i << " ";
    cout << "\n";
    cout.flush();
}

// ------------------------------------------------

int main() {
    int tcase = 1; 
    cin >> tcase;
    srand(tcase * 69 + 2137);
    while (tcase--) {
        solve();
    }
    return 0;
}