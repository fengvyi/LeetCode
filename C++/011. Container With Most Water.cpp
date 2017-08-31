// My BF with optimization, O(n^2)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0, minLeft = 0, minRight = 0;
        for(int i = height.size() - 1; i >= 0; i--){
            if(height[i] < minRight) continue;
            minLeft = 0;
            for(int j = 0; j < i; j++){
                if(height[j] < minLeft) continue;
                maxArea = max(maxArea, min(height[i], height[j]) * (i - j));
                minLeft = max(minLeft, height[j]);
            }
            minRight = max(minRight, height[i]);
        }
        return maxArea;
    }
};

// Brilliant O(n) from Stefan: https://discuss.leetcode.com/topic/16754/simple-and-fast-c-c-with-explanation
class Solution {
public:
    int maxArea(vector<int>& height) {
        int water = 0;
        int i = 0, j = height.size() - 1;
        while (i < j) {
            int h = min(height[i], height[j]);
            water = max(water, (j - i) * h);
            while (height[i] <= h && i < j) i++;
            while (height[j] <= h && i < j) j--;
        }
        return water;
    }
};
