//o(n)
//ans��������Ե�i������β�����������������
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