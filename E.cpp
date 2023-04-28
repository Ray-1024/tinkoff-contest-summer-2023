#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

int64_t getAns(const int64_t& l, const int64_t& r) {
	return l * r;
}

int main() {
	uint32_t n;
	int64_t ans = 0;
	cin >> n;
	vector<int64_t>sum(n);
	unordered_map<int64_t, vector<int64_t> >inds;
	cin >> sum[0];
	inds[sum[0]].push_back(0);
	for (uint32_t i = 1; i < n; ++i)
		cin >> sum[i], sum[i] += sum[i - 1], inds[sum[i]].push_back(i);
	for (const auto& i : inds) {
		if (!i.first) {

		}
	}

}