// C++ program to implement the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum number
// of platforms required
int findPlatform(int arr[], int dep[], int n)
{

	// plat_needed indicates number of platforms
	// needed at a time
	int plat_needed = 1, result = 1;
	int i = 1, j = 0;

	// run a nested loop to find overlap
	for (int i = 0; i < n; i++) {
		// minimum platform
		plat_needed = 1;

		for (int j = i + 1; j < n; j++) {
			// check for overlap
			if (max(arr[i], arr[j]) <= min(dep[i], dep[j]))
				plat_needed++;
		}

		// update result
		result = max(result, plat_needed);
	}

	return result;
}

// Driver Code
int main()
{
	int arr[] = { 9775, 494, 252, 1680 };
	int dep[] = { 2052, 2254, 1395, 2130 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << findPlatform(arr, dep, n);
	return 0;
}
