#include<iostream>
#include<inttypes.h>
using namespace std;

int main() {
	uint32_t a, b, c, d;
	cin >> a >> b >> c >> d;
	if ((a >= b && b >= c && c >= d) || (a <= b && b <= c && c <= d))
		cout << "YES";
	else cout << "NO";
}