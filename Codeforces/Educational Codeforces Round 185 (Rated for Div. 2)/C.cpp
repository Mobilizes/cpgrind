// Problem: C. Quotient and Remainder
// Contest: Educational Codeforces Round 185 (Rated for Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2170/problem/C
// Memory Limit: 512
// Time Limit: 2000
// Start: 28-11-2025 22:32:34 WIB

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

#define Mob                         \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);
#define el "\n"
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define all(a) begin(a), end(a)

const bool is_testcases = true;
const bool desync_stdio = false;
const int floating_precision = 8;

auto solve(int tecs = -1)
{
  ll n, k; cin >> n >> k;
  multiset<ll> q;
  for (int i=0; i<n; i++) {
    int x; cin >> x;
    q.insert(x);
  }

  int res = 0;
  for (int i=0; i<n; i++) {
    int r; cin >> r;
    int y = r+1;
    ll mx_q = (k - r) / y;
    auto itr = q.upper_bound(mx_q);
    if (itr == q.begin()) continue;
    --itr;
    q.erase(itr);
    res++;
  }
  return res;
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
// if you see good syntax format, i used clang-format
