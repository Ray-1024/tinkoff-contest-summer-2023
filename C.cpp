#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	size_t n, ans = SIZE_MAX;
	vector<size_t>last = { 0,0,0,0 };
	string s;
	cin >> n >> s;
	for (size_t i = 0; i < s.size(); ++i) {
		last[s[i] - 'a'] = i + 1;
		if (all_of(last.begin(), last.end(), [](const size_t& a) {return a; }))
			ans = min(*max_element(last.begin(), last.end()) - *min_element(last.begin(), last.end()) + 1, ans);
	}
	if (ans == SIZE_MAX)cout << -1;
	else cout << ans;
}