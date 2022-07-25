#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector<int> a(m);
	forn(i, m) scanf("%d", &a[i]);
	
	int l = 0;
	while ((1 << l) <= m) ++l;
	vector<vector<int>> st(l, vector<int>(m));
	forn(i, m) st[0][i] = a[i];
	for (int j = 1; j < l; ++j) forn(i, m){
		st[j][i] = st[j - 1][i];
		if (i + (1 << (j - 1)) < m)
			st[j][i] = max(st[j][i], st[j - 1][i + (1 << (j - 1))]);
	}
	vector<int> pw(m + 1, 0);
	for (int i = 2; i <= m; ++i) pw[i] = pw[i / 2] + 1;
	auto get = [&](int l, int r){
		if (l > r) swap(l, r);
		++r;
		int len = pw[r - l];
		return max(st[len][l], st[len][r - (1 << len)]);
	};
	
	int q;
	scanf("%d", &q);
	forn(_, q){
		int xs, ys, xf, yf, k;
		scanf("%d%d%d%d%d", &xs, &ys, &xf, &yf, &k);
		--xs, --ys, --xf, --yf;
		if (ys % k != yf % k || xs % k != xf % k){
			puts("NO");
			continue;
		}
		int mx = (n - xs - 1) / k * k + xs;
		puts(get(ys, yf) <= mx ? "YES" : "NO");
	}
	return 0;
}