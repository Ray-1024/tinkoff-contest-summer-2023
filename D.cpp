#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

int main() {
	uint32_t n, ans = 0, max_elements_count = 2e5;
	cin >> n;
	vector<uint32_t>cnt(max_elements_count + 1);
	unordered_map<uint32_t, uint32_t>elems;
	for (uint32_t curr, i = 1; i <= n && cin >> curr; ++i) {
		if (cnt[curr]) {
			--elems[cnt[curr]];
			if (!elems[cnt[curr]])elems.erase(cnt[curr]);
		}
		++cnt[curr];
		++elems[cnt[curr]];
		if (elems.size() == 1 && elems.find(1) != elems.end())ans = i;
		else if (elems.size() == 2) {
			if (elems.begin()->second == 1)ans = i;
			else {
				uint32_t a = elems.begin()->first;
				if (elems.find(a + 1) != elems.end() && elems[a + 1] == 1)ans = i;
				else if (elems.find(a - 1) != elems.end() && elems[a - 1] == 1)ans = i;
			}
		}
	}
	cout << ans;
}