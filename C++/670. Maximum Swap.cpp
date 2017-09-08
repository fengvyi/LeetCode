// Solution 1.
// Time: O(n^2)
class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        for(int i = 0; i < s.size(); i++){
            int digit = s[i] - '0';
            int index = i;
            for(int j = s.size() - 1; j > i; j--){
                if(s[j] - '0' > digit){
                    digit = s[j] - '0';
                    index = j;
                }
            }
            if(digit != s[i] - '0'){
                swap(s[i], s[index]);
                return stoi(s);
            }
        }
        return num;
    }
};

// Solution 2.
// Time: O(n)
class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        vector<int>bucket(10);
        for(int i = 0; i < s.size(); i++)
            bucket[s[i] - '0'] = i;
        for(int i = 0; i < s.size(); i++)
            for(int  j = 9; j > s[i] - '0'; j--)
                if(bucket[j] > i){
                    swap(s[i], s[bucket[j]]);
                    return stoi(s);
                }
        return num;
    }
};
