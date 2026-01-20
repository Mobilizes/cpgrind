// Problem: F. BattleCows
// Contest: Codeforces Round 1074 (Div. 4)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2185/problem/F
// Memory Limit: 256
// Time Limit: 2000
// Start: 18-01-2026 22:39:58 WIB

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

#define Mob                         \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);
#define el "\n"
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(a) begin(a), end(a)

const bool is_testcases = true;
const bool desync_stdio = false;
const int floating_precision = 8;

int fill(vector<int> & tr, int i)
{
  if (tr[i]) return tr[i];

  return tr[i] = fill(tr, i*2) ^ fill(tr, i*2+1);
}

auto solve(int tecs = -1)
{
  int n, q; cin >> n >> q;
  int pow2 = (1<<n);
  vector<int> arr(pow2);
  for (int i=0; i<pow2; i++) {
    cin >> arr[i];
  }

  vector<int> tr(pow2*2);
  for (int i=pow2; i<pow2*2; i++) {
    tr[i] = arr[i - pow2];
  }

  fill(tr, 1);

  for (int i=0; i<q; i++) {
    int idx, v; cin >> idx >> v;
    int prev = arr[idx-1];

    int tmp = idx + pow2 - 1;
    tr[tmp] = v;
    while (tmp > 1) {
      tmp /= 2;
      tr[tmp] = 0;
    }
    fill(tr, 1);

    int curr = 0;
    int cnt = 1;
    tmp = idx + pow2 - 1;
    while (tmp > 1) {
      if (tmp & 1) {
        if (tr[tmp] <= tr[tmp-1]) curr += cnt;
      } else {
        if (tr[tmp] < tr[tmp+1]) curr += cnt;
      }
      cnt *= 2;
      tmp /= 2;
    }
    cout << curr << ' ';

    // for (int i=1; i<pow2*2; i++) {
    //   cout << tr[i] << ' ';
    // }
    // cout << el;

    tmp = idx + pow2 - 1;
    tr[tmp] = prev;
    while (tmp > 1) {
      tmp /= 2;
      tr[tmp] = 0;
    }
    fill(tr, 1);
  }
  cout << el;
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
