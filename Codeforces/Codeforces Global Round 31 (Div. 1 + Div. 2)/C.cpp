// Problem: C. XOR-factorization
// Contest: Codeforces Global Round 31 (Div. 1 + Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/problemset/problem/2180/C
// Memory Limit: 256
// Time Limit: 2000
// Start: 30-12-2025 04:27:11 WIB

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

auto solve(int tecs = -1)
{
  int n, k; cin >> n >> k;
  vector<int> arr(k, n);

  if (k & 1) return arr;

  int msb = 1 << (31 - __builtin_clz(n));
  int remainder = n - msb;

  for (int i=30; i>=0; i--) {
    int b = 1 << i;
    if (msb + b > n) continue;
    if (remainder & b) continue;

    msb += b;
    remainder += b;
  }

  arr[0] = remainder;
  arr[1] = msb;

  return arr;
}

// vector<int> arr;
// int i = 0;
// int n = 12;
// int k = 6;
// int mx = n * (k-1);
void initialize()
{
  // if (i == k) {
  //   if (accumulate(all(arr), 0) > mx && accumulate(all(arr), 0, [](int a, int b) { return a ^ b; }) == n) {
  //     for (int i=0; i<k; i++) {
  //       cout << arr[i] << ' ';
  //     }
  //     cout << el;
  //     mx = accumulate(all(arr), 0);
  //   }
  //   return;
  // }
  //
  // for (int j=0; j<=n; j++) {
  //   arr.push_back(j);
  //   i++;
  //   initialize();
  //   i--;
  //   arr.pop_back();
  // }
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
