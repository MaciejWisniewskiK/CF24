#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define f first
#define s second


void solve() {
    ll n, k;
    cin >> n >> k;


    vector<ll> sums(n);
    map <ll, ll> mapa;

    for (int i = 0; i < n; i++)
        cin >> sums[i];

    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        mapa[abs(x)] += sums[i];
    }

    ll ammoleft = 0;
    ll lastx = 0;
    for (auto elem : mapa) {
        ammoleft += (elem.first - lastx) * k;
        ammoleft -= elem.second;
        lastx = elem.first;
        if (ammoleft < 0) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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

