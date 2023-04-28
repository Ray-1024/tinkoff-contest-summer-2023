#include<iostream>
#include<inttypes.h>
using namespace std;

int main() {
	uint32_t n, m, k;
	cin >> n >> m >> k;
	cout << (n * k + m - 1) / m;
}