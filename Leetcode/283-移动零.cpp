class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int len = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] != 0) nums[len++] = nums[i];
		}
		for (int i = len; i < nums.size(); i++)nums[i] = 0;
	}
};