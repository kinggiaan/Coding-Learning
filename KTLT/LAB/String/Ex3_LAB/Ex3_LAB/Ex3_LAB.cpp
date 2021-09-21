#include <iostream>
#include<string.h>

using namespace std;

int main() {
	string s = "";
	string a = "";
	cin >> s;

	int count = 1, temp = 1;
	a = a + s[0];
	for (size_t i = 1; i < s.length(); i++) {
		bool f = false;
		for (size_t j = 0; j < a.length(); j++) {
			if (a[j] == s[i]) {
				
				f = true;
				break;
			}
		}
		if(f) {
			temp = 1;
			a = "";
			a += s[i];
		}
		else {

			temp++;
			if (temp>count) count = temp;
			a += s[i];
		}
	}
	cout << count;
	return 0;
}
