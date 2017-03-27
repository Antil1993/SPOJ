#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Function to add numbers (stored in reverse) in strings
string addString(string & a, string & b) {
	int carry = 0;
	string solution = "";
	for(int i=0; i< a.size() || i < b.size(); i++) {
		int s1 = (i < a.size()) ? (a[i] - '0') : 0;
		int s2 = (i < b.size()) ? (b[i] - '0') : 0;
		int sum = s1 + s2 + carry;
		if(sum > 9) {
			carry = 1;
			sum -= 10;
		}
		else
			carry = 0;

		solution = solution + (char)(sum + '0');
	}

	if(carry == 1)
		solution = solution + '1';
	return solution;
}

// Function returns the possible number of ways one can make n digit numbers
string getSolution(vector<string> & results, int n) {
	if(results[n].compare(""))
		return	results[n];

	string s1 = getSolution(results, n-1);
	string s2 = getSolution(results, n-2);
	results[n] = addString(s1, s2);
	return results[n];
}

int main() {
	int n;
	cin >> n;
	vector<string> results (n+1, "");
	results[0] = "1";
	results[1] = "2";
	getSolution(results, n);
	reverse(results[n].begin(), results[n].end());
	cout << results[n];
	return 0;
}