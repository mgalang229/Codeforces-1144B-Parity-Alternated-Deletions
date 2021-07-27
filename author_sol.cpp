#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int sum = 0;
	vector<int> even, odd;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		// calculate the sum of all the elements
		sum += x;
		// store the odd and even numbers in their respective vectors
		if (x & 1) {
			odd.push_back(x);
		} else {
			even.push_back(x);
		}
	}
	// sort both of the vectors in non-increasing order
	sort(odd.rbegin(), odd.rend());
	sort(even.rbegin(), even.rend());
	// find the minimum value between the odd and the even numbers (since this the number of
	// elements that are matched with each other and will subtracted from sum)
	int k = min((int) odd.size(), (int) even.size());
	int rem = sum;
	// subtract the sum of the first 'k' odd elements from 'rem'
	rem -= accumulate(odd.begin(), odd.begin() + k, 0);
	// subtract the sum of the first 'k' even elements from 'rem'
	rem -= accumulate(even.begin(), even.begin() + k, 0);
	if (int(odd.size()) > k) {
		// if the odd numbers are greater than 'k', then subract the element at the 'k'-th
		// position from the value of the sum (this will produce the minimum sum)
		rem -= odd[k];
	}
	if (int(even.size()) > k) {
		// if the even numbers are greater than 'k', then subract the element at the 'k'-th
		// position from the value of the sum (this will produce the minimum sum)
		rem -= even[k];
	}
	cout << rem << '\n';
	return 0;
}
