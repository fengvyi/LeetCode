class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0, maxH = 0;
        stack<int>stk, idx;
        for(int i = 0; i < height.size(); i++){
            int h = min(maxH, height[i]);
            if(!stk.empty()){
                int temp = 0, preIdx = i, preH = h, curH = h;
                while(!stk.empty() && stk.top() < height[i]){
                    curH = stk.top();
                    temp += (h - preH) * (preIdx - idx.top()) - (curH - preH);
                    preH = stk.top();
                    stk.pop();
                    preIdx = idx.top();
                    idx.pop();
                }
                if(!stk.empty()) temp += (h - preH) * (preIdx - 1 - idx.top());
                sum += temp;
            }
            stk.push(height[i]);
            idx.push(i);
            maxH = max(maxH, height[i]);
        }
        return sum;
    }
};
