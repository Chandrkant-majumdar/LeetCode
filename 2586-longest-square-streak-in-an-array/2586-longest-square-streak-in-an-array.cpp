#include <algorithm>
#include <vector>
#include <cstring>

const int VMAX = 1e5 + 8;

int dp[VMAX];

class Solution {
  public:
	int longestSquareStreak(std::vector<int> &nums)
	{
		// sort in reverse order
		std::sort(nums.begin(), nums.end(), std::greater<int>());

		// initialise the dp with zeroes for all values
		int max = nums[0];
		memset(dp, 0, sizeof(int) * (1 + max));

		int ans = 0;
		for (int i : nums) {
			// base case is that we can't extend the subsequence 
			dp[i] = 1;

			// check if i * i doesn't overflow
			// and if dp[i * i] > 0
			// (ie. i * i exists before the current val)
			if (i <= max / i && dp[i * i] != 0) {
				dp[i] = 1 + dp[i * i];
			}

			// if we extended the subsequence more than prev. answer
			// update the answer
			if (dp[i] > ans) {
				ans = dp[i];
			}
		}

		// if ans is < 2, we have no valid subsequence, so return -1
		if (ans < 2) {
			ans = -1;
		}
		return ans;
	}
};