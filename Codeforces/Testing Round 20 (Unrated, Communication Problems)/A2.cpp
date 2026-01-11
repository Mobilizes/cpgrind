// Problem: A2. Encode and Decode (Hard Version)
// Contest: Testing Round 20 (Unrated, Communication Problems)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2168/problem/A2
// Memory Limit: 512
// Time Limit: 2000
// Start: 10-11-2025 20:05:22 WIB

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

    string res = "";
    for (int i=0; i<n; i++) {
      string s = to_string(arr[i]);
      for (char c : s) res += char(c - '0' + 'a');
      if (s.size() < 10) res += 'z';
    }
    cout << res << el;
  } else {
    string s; cin >> s;
    vector<int> res;
    int curr = 0;
    int cnt = 0;
    for (char c : s) {
      if (c == 'z') {
        res.push_back(curr);
        curr = 0;
        cnt = 0;
        continue;
      }
      else if (cnt == 10) {
        res.push_back(curr);
        curr = 0;
        cnt = 0;
      }

      curr *= 10;
      cnt++;
      curr += c - 'a';
    }

    if (curr != 0) res.push_back(curr);

    cout << res.size() << el;
    for (int i=0; i<res.size(); i++) {
      cout << res[i] << " ";
    }
    cout << el;
  }
}

void initialize()
{
  // cout << 10000 << el;
  // for (int i=0; i<10000; i++) cout << 1000000000 << " ";
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
