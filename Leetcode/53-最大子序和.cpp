//o(n)
//ans缓存代表以第i个数结尾的连续子数组的最大和
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int ans = nums[0];
		int maxans = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			ans = max(ans + nums[i], nums[i]);
			if (ans > maxans) maxans = ans;
		}
		return maxans;
	}
};