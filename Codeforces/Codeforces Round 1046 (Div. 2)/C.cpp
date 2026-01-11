// Problem: C. Against the Difference
// Contest: Codeforces Round 1046 (Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2136/problem/C
// Memory Limit: 256
// Time Limit: 2000
// Start: 28-08-2025 22:06:07 WIB

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

#define Mob ios_base::sync_with_stdio(false); cin.tie(NULL);
#define lcm(a,b) ((a / __gcd(a, b)) * b)
#define el "\n"
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second

const bool is_testcases = true;
const bool desync_stdio = false;

vector<int> arr;

auto solve(int tecs=-1)
{
  arr.clear();

  int n; cin >> n;
  arr.resize(n);
  for (int i=0; i<n; i++) cin >> arr[i];

  vector<int> dp(n+1, 0);

  map<int, pair<queue<int>, int>> mp;
  for (int i=2; i<=n; i++) mp[i] = {{}, 0}; // first index found, block count

  for (int i=0; i<n; i++) {
    dp[i+1] = dp[i];

    if (arr[i] == 1) {
      dp[i+1]++;
      continue;
    }

    mp[arr[i]].first.push(i);
    mp[arr[i]].second++;

    if (mp[arr[i]].second == arr[i]) {
      dp[i+1] = max(dp[i+1], arr[i] + dp[mp[arr[i]].first.front()]);
      mp[arr[i]].first.pop();
      mp[arr[i]].second--;
    }
  }

  // for (int i=1; i<n; i++) cout << dp[i] << ' ';
  cout << dp[n] << el;
}

void initialize()
{
}

template <typename T>
void call_solve(T f, int tecs = -1)
{
  using ReturnValue = invoke_result_t<decltype(f), int>;
  if constexpr (is_same_v<ReturnValue, bool>) {
    cout << (f(tecs) ? "YES" : "NO") << el;
  } else if constexpr (is_same_v<ReturnValue, void>) {
    f(tecs);
  } else {
    static_assert(is_same_v<ReturnValue, void> || is_same_v<ReturnValue, bool>,
      "solve() has to be bool or void");
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
