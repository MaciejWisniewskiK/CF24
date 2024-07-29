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
int n, m, q;
int x;


int doit(bitset<32> &bs, int first_0_instead_of_1, vector<bitset <32> > &v) {
    bitset<32> allowed_bits = bs;
    if (first_0_instead_of_1 >= 0) {
        allowed_bits[first_0_instead_of_1] = 0;
        for (int i = first_0_instead_of_1 - 1; i >= 0; i--)
            allowed_bits[i] = 1;
    }
    
    bitset<32> curr(0);
    int res = 0;
    for (int i = 0; i < n; i++) {
        curr ^= v[i];

        if ((curr | allowed_bits) == allowed_bits) {
            curr = 0;
            res++;
            continue;
        }

        if (i == n - 1)
            return -1;
    }
    
    return res;
}

void solve() {
    cin >> n >> x;
    vector <bitset<32> > v;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        bitset <32> b(a);
        v.push_back(b);
    }
    
    bitset <32> bs(x);

    int k = -1;
    bool was_one = false;
    for (int i = 31; i >= 0; i--) {
        if (!bs[i]) continue;
        k = max(k, doit(bs, i, v));
    }
    k = max(k, doit(bs, -1, v));


    cout << k << "\n";
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