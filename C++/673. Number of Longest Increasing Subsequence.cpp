class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>len(n, 1);
        vector<int>cnt(n, 1);
        int maxlen = 1, res = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    if(len[i] == len[j] + 1) cnt[i] += cnt[j];
                    if(len[i] < len[j] + 1){
                        len[i] = len[j] + 1;
                        cnt[i] = cnt[j];
                    }
                }
            }
            if(len[i] == maxlen) res += cnt[i];
            if(len[i] > maxlen){
                maxlen = len[i];
                res = cnt[i];
            }
        }
        return res;
    }
};
