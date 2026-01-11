#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = 1e18;

#define fi first
#define se second
#define pb push_back

struct Point {
  ld x, y;
};

double area(Point a, Point b, Point c) {
  return abs(a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) / 2;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<Point> p(n);
  for (auto& i : p) {
    cin >> i.x >> i.y;
  }

  vector<ld> v;
  for (int i = 1; i < n - 1; i++) {
    v.pb(area(p[0], p[i], p[i + 1]));
    if (i > 1) {
      v.back() += v[v.size() - 2];
    }
  }

  n -= 2;
  set<ld> s = {v[0]};
  ld ans = LDBL_MAX;
  for (int i = 1; i < n - 1; i++) {
    ld s3 = v.back() - v[i];
    auto it = s.lower_bound(v[i] / 2);
    if (it != s.end()) {
      ld s1 = *it, s2 = v[i] - s1;
      ans = min(ans, max({s1, s2, s3}) - min({s1, s2, s3}));
    }
    if (it != s.begin()) {
      ld s1 = *prev(it), s2 = v[i] - s1;
      ans = min(ans, max({s1, s2, s3}) - min({s1, s2, s3}));
    }
    s.insert(v[i]);
  }
  cout << fixed << setprecision(10) << ans;

  return 0;
}
