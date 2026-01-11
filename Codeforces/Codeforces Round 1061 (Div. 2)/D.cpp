// Problem: D. Find the Last Number
// Contest: Codeforces Round 1061 (Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2156/problem/D
// Memory Limit: 256
// Time Limit: 3000
// Start: 24-10-2025 22:22:24 WIB

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

void ask(const auto & i, const auto & j, auto & q) {
  cout << "? " << i << " " << j << endl;
  cin >> q;
}

auto solve(int tecs = -1)
{
  int n;
  cin >> n;

  int x;

  queue<int> q;
  queue<int> idx;
  for (int i=1; i<=n; i++) q.push(i);
  for (int i=1; i<n; i++) idx.push(i);

  int res = 0;
  for (int b=1; b<=n; b*=2) {
    int req = 0;
    queue<int> tmp = q;
    while (!tmp.empty()) {
      if (tmp.front() & b) req++;
      tmp.pop();
    }

    int cnt = 0;
    queue<int> tmp1, tmp0;
    while (!idx.empty()) {
      ask(idx.front(), b, x);
      if (x) tmp1.push(idx.front());
      else tmp0.push(idx.front());
      idx.pop();
    }

    queue<int> nq;
    if (tmp1.size() == req) {
      idx = tmp0;
      while (!q.empty()) {
        if (!(q.front() & b)) nq.push(q.front());
        q.pop();
      }
    } else if (tmp1.size() < req) {
      res += b;
      idx = tmp1;
      while (!q.empty()) {
        if (q.front() & b) nq.push(q.front());
        q.pop();
      }
    }

    q = nq;
  }

  cout << "! " << res << endl;
}

// clang-format off
void initialize()
{
}
// clang-format on

template <typename T>
void call_solve(T f, int tecs = -1)
{
  using ReturnValue = invoke_result_t<decltype(f), int>;
  if constexpr (is_same_v<ReturnValue, bool>) {
    cout << (f(tecs) ? "YES" : "NO") << el;
  } else if constexpr (is_integral_v<ReturnValue> || is_same_v<ReturnValue, string> ||
                       is_same_v<ReturnValue, const char *>) {
    cout << f(tecs) << el;
  } else if constexpr (is_floating_point_v<ReturnValue>) {
    cout << fixed << setprecision(floating_precision) << f(tecs) << el;
  } else if constexpr (ranges::range<ReturnValue>) {
    for (auto i : f(tecs)) cout << i << ' ';
    cout << el;
  } else {
    f(tecs);
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
