// Problem: Digit Sum
// Contest: Classical
// Judge: SPOJ
// URL: https://www.spoj.com/problems/PR003004/
// Memory Limit: 1536
// Time Limit: 1000
// Start: 08-11-2025 23:39:44 WIB

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

#define Mob                         \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);
#define lcm(a, b) ((a / __gcd(a, b)) * b)
#define el "\n"
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define all(a) begin(a), end(a)

const bool is_testcases = true;
const bool desync_stdio = false;
const int floating_precision = 8;

// digit, under, started
bool vis[17][150][2];
ll dp[17][150][2];

string upp;
ll solve_dp(int idx, int k, bool under) {
  if (idx == upp.size()) {
    return k;
  }

  if (vis[idx][k][under]) return dp[idx][k][under];
  vis[idx][k][under] = true;

  int d = upp[idx] - '0';

  ll res = 0;
  for (int i=0; i<=9; i++) {
    if (!under && i > d) break;

    bool isunder = under || i < d;

    res += solve_dp(idx+1, k + i, isunder);
  }

  return dp[idx][k][under] = res;
}

auto solve(int tecs = -1)
{
  for (int i=0; i<17; i++) {
    for (int j=0; j<150; j++) {
      for (int k=0; k<2; k++) {
        vis[i][j][k] = false;
        dp[i][j][k] = 0;
      }
    }
  }

  ll x, y; cin >> x >> y;
  upp = to_string(y);
  ll res = solve_dp(0, 0, false);

  for (int i=0; i<upp.size(); i++) {
    for (int j=0; j<150; j++) {
      // cout << "{";
      for (int k=0; k<2; k++) {
        // cout << dp[i][j][k] << ',';
        vis[i][j][k] = false;
        dp[i][j][k] = 0;
      }
      // cout << "} ";
    }
    // cout << el;
  }

  if (x-1 < 0) {
    cout << res << endl;
    return;
  }
  upp = to_string(x-1);
  res -= solve_dp(0, 0, false);

  cout << res << endl;
}

void initialize()
{
}

int main()
{
  if constexpr (desync_stdio) {
    Mob;
  }

  initialize();
  if (is_testcases) {
    int testcase;
    cin >> testcase;
    for (int tecs = 1; tecs <= testcase; tecs++) {
      solve(tecs);
    }
  } else {
    solve();
  }
}
// if you see good syntax format, i used clang-format
