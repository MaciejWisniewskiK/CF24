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

void input() {
    
}

void solve() {
    input();
    cin >> n;
    cout << n << "\n";
}

// ------------------------------------------------

int main() {
    int n;
    cin >> n;
    
    if (n == 4 || n % 4 == 3 || n == 2)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}