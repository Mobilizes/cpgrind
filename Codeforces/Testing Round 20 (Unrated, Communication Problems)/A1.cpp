// Problem: A1. Encode and Decode (Easy Version)
// Contest: Testing Round 20 (Unrated, Communication Problems)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2168/problem/A1
// Memory Limit: 512
// Time Limit: 2000
// Start: 10-11-2025 20:00:13 WIB

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

const bool is_testcases = false;
const bool desync_stdio = false;
const int floating_precision = 8;

auto solve(int tecs = -1)
{
  string t; cin >> t;
  if (t == "first") {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i];

    for (int i=0; i<n; i++) {
      cout << char(arr[i] + 'a' - 1);
    }
    cout << el;
  } else {
    string s; cin >> s;
    int n = s.length();

    cout << n << el;
    for (int i=0; i<n; i++) {
      cout << int(s[i] - 'a' + 1) << " ";
    }
    cout << el;
  }
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
