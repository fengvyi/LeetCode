class Solution {
public:
    bool makesquare(vector<int>& nums) {
        int sum = 0, maxlen = 0, n = nums.size();
        for(int x: nums) sum += x, maxlen = max(maxlen, x);
        int size = sum / 4;
        if(sum == 0 || sum % 4 || maxlen > size ) return false;
        vector<int>visited(n, 0);
        return DFS(nums, visited, 0, 0, size, n, 0, false);
    }
    
    bool DFS(vector<int>& nums, vector<int>& visited, int pos, int length, int size, int n, int count, bool newSide){
        if(length > size) return false;
        if(length == size) count++, length = 0, newSide = true;
        if(count == 3) return true;
        
        length += nums[pos];
        visited[pos] = 1;
        
        for(int i = newSide ? 0 : pos + 1; i < n; i++)
            if(!visited[i] && DFS(nums, visited, i, length, size, n, count, false))
                return true;  
        
        visited[pos] = 0;
        return false;
    }
};
