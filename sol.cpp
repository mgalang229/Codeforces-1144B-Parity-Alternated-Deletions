#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> even;
	vector<int> odd;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		// calculate the sum of all the elements
		sum += x;
		// store the elements into two vectors (based on their parity)
		if (x % 2 == 0) {
			even.emplace_back(x);
		} else {
			odd.emplace_back(x);
		}
	}
	// sort both the vectors ('even' and 'odd') in non-increasing order
	sort(even.rbegin(), even.rend());
	sort(odd.rbegin(), odd.rend());
	vector<int> res;
	int even_index = 0;
	int odd_index = 0;
	// check if there are more even numbers than odd numbers in the sequence
	if ((int) even.size() > (int) odd.size()) {
		// if yes, then combine the two vectors together in one vector and arrange them
		// in such a way that even numbers appear before odd numbers in the sequence
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0 && even_index < (int) even.size()) {
				res.emplace_back(even[even_index]);
				even_index++;
			} else if (odd_index < (int) odd.size()) {
				res.emplace_back(odd[odd_index]);
				odd_index++;
			}
		}
	} else {
		// if no, then do the same but arrange them in such a way that odd numbers appear 
		// before even numbers in the sequence
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0 && odd_index < (int) odd.size()) {
				res.emplace_back(odd[odd_index]);
				odd_index++;
			} else if (even_index < (int) even.size()) {
				res.emplace_back(even[even_index]);
				even_index++;
			}
		}
	}
	auto Parity = [&](const int& a) {
		return (a % 2 == 0);
	};
	vector<int> visited(n, false);
	for (int i = 0; i < (int) res.size() - 1; i++) {
		// mark all the elements with their corresponding adjacent elements
		// i.e., 'a[i]' = even && 'a[i + 1]' = odd or vice-versa
		if (Parity(res[i]) != Parity(res[i + 1])) {
			visited[i] = true;
			visited[i + 1] = true;
		}
	}
	// subtract the first element from the sum (initial)
	sum -= res[0];
	// start the loop from the second element
	for (int i = 1; i < (int) res.size(); i++) {
		if (visited[i]) {
			// if the element is visited, then subtract this value from the sum
			sum -= res[i];
		}
	}
	cout << sum << '\n';
	return 0;
}
