#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

inline bool inRange(const uint32_t& x, const pair<uint32_t, uint32_t>& range) {
	return x >= range.first && x <= range.second;
}

bool checkMiddlePoint(uint32_t x, uint32_t s, vector<pair<uint32_t, uint32_t> >& r) {
	stable_sort(r.begin(), r.end(), [&x](auto& a, auto& b) {
		bool al = inRange(a.second, { 0,x - 1 });
		bool bl = inRange(b.second, { 0,x - 1 });
		bool am = inRange(x, a);
		bool bm = inRange(x, b);
		bool ar = inRange(a.first, { x + 1,UINT32_MAX });
		bool br = inRange(b.first, { x + 1,UINT32_MAX });
		if ((al && bl) || (ar && br) || (am && bm))return a < b;
		if ((al && (bm || br)) || (am && br))return true;
		else return false;
		});
	uint32_t middle = r.size() >> 1;
	if (r[middle].second < x)return false;
	else if (r[middle].first > x)return true;
	for (uint32_t i = 0; i < middle; ++i) {
		if (s < r[i].first)return false;
		s -= r[i].first;
	}
	if (s < x)return false;
	s -= x;
	for (uint32_t i = 0; i < middle; ++i) {
		if (s < max(r[i].first, x))return false;
		s -= max(r[i].first, x);
	}
	return true;
}

uint32_t findMaxPoints(uint32_t& s, vector<pair<uint32_t, uint32_t> >& ranges) {
	uint32_t m, l = 1, r = s;
	while (r - l > 1) {
		m = (l + r) >> 1;
		if (checkMiddlePoint(m, s, ranges))l = m;
		else r = m;
	}
	if (checkMiddlePoint(r, s, ranges))return r;
	return l;
}

int main() {
	uint32_t n, s;
	cin >> n >> s;
	vector<pair<uint32_t, uint32_t> >ranges(n);
	for (auto& i : ranges)
		cin >> i.first >> i.second;
	cout << findMaxPoints(s, ranges);
}