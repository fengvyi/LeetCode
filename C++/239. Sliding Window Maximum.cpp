class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int>res;
		if (nums.size() == 0) return res;
		int start = 0;
		int end = k - 1;
		int maxIndex = findMax(nums, start, end);
		for (; end < nums.size(); start++, end++) {
			if (nums[end] > nums[maxIndex]) maxIndex = end;
			if (start > maxIndex) maxIndex = findMax(nums, start, end);
			res.push_back(nums[maxIndex]);
		}
		return res;
	}

	int findMax(vector<int>& nums, int start, int end) {
		int maxIndex = start;
		for (int i = start + 1; i <= end; i++)
			if (nums[i] > nums[maxIndex]) maxIndex = i;
		return maxIndex;
	}
};