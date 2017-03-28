#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
	int cases;
	cin >> cases;
	while(cases--) {
		// Read input
		int size;
		cin >> size;
		vector<int> arr (size);
		for(int i=0; i<size; i++)
			cin >> arr[i];

		// Get position to interchange
		int pos = size -2;
		while(pos >= 0) {
			if(arr[pos] < arr[pos+1])
				break;
			pos--;
		}

		if(pos != -1) {
			
			// Closest value to interchange with
			int closestValue = pos+1;
			for(int i=pos+1; i<size; i++) {
				if(arr[i] - arr[pos] > 0)
					closestValue = i;
				else
					break;
			}

			// Interchange
			int temp = arr[pos];
			arr[pos] = arr[closestValue];
			arr[closestValue] = temp;

			// Sort the elements after pos
			sort(arr.begin() + (pos+1), arr.end());

			for(int i=0; i<size; i++)
				cout << arr[i];
			cout << endl;
		}
		else
			cout << pos << endl;

	}
	return 0;
}