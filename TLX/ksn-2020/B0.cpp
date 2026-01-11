#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

#define Mob                         \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);
#define el "\n"
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define all(a) begin(a), end(a)

const bool is_testcases = false;
const bool desync_stdio = false;
const int floating_precision = 8;

const int mx_n = 10000005;

auto solve(int tecs = -1)
{
  ll n; cin >> n;
  ll tn = n;
  vector<ll> res;
  for (int i=0; i<4; i++) {
    ll ans = sqrt(n);
    n -= ans*ans;
    res.push_back(ans);
  }
 
  while (n) {
    res[0]--;
    res.erase(res.begin()+1, res.end());
    n = tn - res[0]*res[0];
    for (int i = 1; i < 4; i++) {
      ll l = 0, r = n;
      ll ans = 0;
      while (l <= r) {
        ll m = (l + r) / 2;
        if (m * m <= n) {
          ans = m;
          l = m + 1;
        } else {
          r = m - 1;
        }
      }
      n -= ans * ans;
      res.push_back(ans);
    }
  }
 
  return res;
}

// lagrange four squares theorem:
// split n to 2, p and q
// p = (a1^2 + a2^2 + a3^2 + a4^2)
// q = (b1^2 + b2^2 + b3^2 + b4^2)
// pq = (c1^2 + c2^2 + c3^2 + c4^2)
// c1 = abs(a1b1 - a2b2 - a3b3 - a4b4)
// c2 = abs(a1b2 + a2b1 + a3b4 - a4b3)
// c3 = abs(a1b3 - a2b4 + a3b1 + a4b2)
// c4 = abs(a1b4 + a2b3 - a3b2 + a4b1)
//
// amazing resource: https://youtu.be/Q95PB_Dcjoo?si=7ky3cxJ2NLUVds70&t=1052
//
// 12: 4*3
// 4: 2 0 0 0
// 3: 1 1 1 0
// 12: 2 2 2 0
//
// 55: 5*11
// 5: 2 1 0 0
// 11: 3 1 1 0
// 55: 5 5 2 1
//
// 5: 2 1 0 0
// 11: 1 3 1 0
// 55: 1 7 2 1
//
// this is overkill
//

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
