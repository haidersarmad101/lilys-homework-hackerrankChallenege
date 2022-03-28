#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
    int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++)
				cin >> a[i];
		map<int, int> ind;
		int b[n], c[n];
		copy(a, a + n, b);
		sort(b, b + n);
		int ans = 2e9;
		for (int j = 0; j < 2; j++) {
			for (int i = 0; i < n; i++) 
				ind[a[i]] = i;
			copy(a, a + n, c);
			int sum = 0;
			for (int i = 0; i < n; i++) 
				if (c[i] != b[i]) {
					sum++;
					ind[c[i]] = ind[b[i]];
					c[ind[b[i]]] = c[i];
				}
			ans = min(ans, sum);
			if (!j) 
				reverse(b, b + n);
		}
		cout << ans;
    return 0;
}
