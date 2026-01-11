// Problem: D. Non Prime Tree
// Contest: Codeforces Round 992 (Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/problemset/problem/2040/D
// Memory Limit: 256
// Time Limit: 2000
// Start: 01-10-2025 13:44:14 WIB

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

const bool is_testcases = true;
const bool desync_stdio = false;

array<bool, 400001> primes;

// clang-format off
auto solve(int tecs = -1)
{
  // clang-format on
  int n;
  cin >> n;
  vector<vector<int>> tr(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    tr[a].push_back(b);
    tr[b].push_back(a);
  }

  vector<bool> vis(n + 1, false);
  vector<int> res(n + 1, 0);
  int itr = 1;
  vis[1] = true;
  res[1] = 1;

  function<void(int)> dfs = [&](int v) {
    for (int i : tr[v]) {
      if (vis[i]) continue;
      vis[i] = true;
      res[i] = itr + 1;
      while (primes[abs(res[i] - res[v])]) {
        res[i]++;
      }
      itr = res[i];
      dfs(i);
    }
  };

  dfs(1);

  for (int i = 1; i <= n; i++) {
    cout << res[i] << ' ';
  }
  cout << el;
  // clang-format off
}

void initialize()
{
  primes.fill(true);
  primes[1] = false;
  for (int i=2; i<=sqrt(400000); i++) {
    if (!primes[i]) continue;
    for (int j=2*i; j<=400000; j+=i) primes[j] = false;
  }
}
// clang-format on

template <typename T>
void call_solve(T f, int tecs = -1)
{
  using ReturnValue = invoke_result_t<decltype(f), int>;
  if constexpr (is_same_v<ReturnValue, bool>) {
    cout << (f(tecs) ? "YES" : "NO") << el;
  } else if constexpr (is_same_v<ReturnValue, void>) {
    f(tecs);
  } else if constexpr (is_integral_v<ReturnValue>) {
    cout << f(tecs) << el;
  } else {
    static_assert(
      is_same_v<ReturnValue, void> || is_same_v<ReturnValue, bool> || is_integral_v<ReturnValue>,
      "solve() return type is not supported");
  }
}

int main()
{
  if constexpr (desync_stdio) {
    Mob;
  }

  initialize();
  if constexpr (is_testcases) {
    int testcase;
    cin >> testcase;
    for (int tecs = 1; tecs <= testcase; tecs++) {
      call_solve(solve, tecs);
    }
  } else {
    call_solve(solve);
  }
}
