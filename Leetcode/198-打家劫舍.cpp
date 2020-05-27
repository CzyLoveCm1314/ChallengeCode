class Solution {
public:
	int rob(vector<int>& nums) {
		return max(rob1(nums), rob2(nums));
	}

	int rob1(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		if (nums.size() == 1) return nums[0];
		if (nums.size() == 2) return max(nums[0], nums[1]);
		int* dp = new int[nums.size() + 1];
		dp[0] = nums[0];
		dp[1] = max(nums[0], nums[1]);
		for (int i = 2; i < nums.size() - 1; i++)
			dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
		return dp[nums.size() - 2];
	}

	int rob2(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		if (nums.size() == 1) return nums[0];
		if (nums.size() == 2) return max(nums[0], nums[1]);
		int* dp = new int[nums.size() + 2];
		dp[1] = nums[1];
		dp[2] = max(nums[1], nums[2]);
		for (int i = 3; i < nums.size(); i++)
			dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
		return dp[nums.size() - 1];
	}
};