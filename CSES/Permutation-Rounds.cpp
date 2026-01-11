// Problem: Permutation Rounds
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/3398
// Memory Limit: 512
// Time Limit: 1000
// Start: 17-11-2025 06:26:05 WIB

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

struct dsu {
  public:
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    std::vector<int> parent_or_size;
};

int mx_n = 200000;
ll mod = 1000000007;

vector<int> primes;

auto solve(int tecs = -1)
{
  int n; cin >> n;
  vector<int> arr(n+1);
  for (int i=1; i<=n; i++) cin >> arr[i];

  dsu ds(n+4);
  for (int i=1; i<=n; i++) {
    ds.merge(i, arr[i]);
  }

  vector<ll> factors(mx_n, 0);
  for (auto i : ds.groups()) {
    int curr = i.size();
    for (int p : primes) {
      ll cnt = 0;
      while (curr % p == 0) {
        curr /= p;
        cnt++;
      }
      factors[p] = max(factors[p], cnt);
      if (curr == 1) break;
    }
  }

  ll res = 1;
  for (int i=2; i<=mx_n; i++) {
    for (int j=0; j<factors[i]; j++) {
      res = (res * i) % mod;
    }
  }

  return res;

  // vector<int> a(n+1);
  // for (int i=1; i<=n; i++) a[i] = i;
  // for (int k=0; k<res; k++) {
  //   vector<int> b(n+1);
  //   for (int i=1; i<=n; i++) b[arr[i]] = a[i];
  //   for (int i=1; i<=n; i++) cout << b[i] << ' ';
  //   a = b;
  //   cout << el;
  // }
}

vector<bool> sieve(int n)
{
  vector<bool> prime(n + 1, 1);
  prime[0] = prime[1] = 0;
  for (int i = 2; i * i <= n; i++) {
    if (prime[i]) {
      for (int j = i * i; j <= n; j += i) {
        prime[j] = 0;
      }
    }
  }
  return prime;
}

void initialize()
{
  vector<bool> prime = sieve(mx_n);
  for (int i=2; i<=mx_n; i++) if (prime[i]) primes.push_back(i);
  //
  // vector<int> res;
  // int idx = 1;
  // for (int i=0; i<11; i++) {
  //   for (int j=1; j<primes[i]; j++) {
  //     res.push_back(idx+j);
  //   }
  //   res.push_back(idx);
  //   idx += primes[i];
  // }
  //
  // cout << res.size() << el;
  // for (int i : res) cout << i << ' ';
  // cout << el;
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
