// Solution 1. Backtracking
// Run Time: 266ms
class Solution {
public:
    string getPermutation(int n, int k) {
        string s = "", res = "";
        for(int i = 1; i <= n; i++) s.push_back(i + '0');
        string path = s;
        int count = 0;
        DFS(s, 0, count, n, k, path, res);
        return res;
    }
    
    void DFS(string& s, int pos, int& count, int n, int k, string& path, string& res){
        if(count >= k || pos == n){
            if(++count == k) res = path;
            return;
        }
        for(int i = 0; i < n; i++){
            if(s[i] == '0') continue;
            path[pos] = s[i];
            s[i] = '0';
            DFS(s, pos + 1, count, n, k, path, res);
            s[i] = path[pos];
        }
    }
};

// Solution 2. Using STL
// Run Time: 119ms
class Solution {
public:
    string getPermutation(int n, int k) {
        string s = "";
        for(int i = 1; i <= n; i++) s.push_back(i + '0');
        while(--k) next_permutation(s.begin(), s.end());
        return s;
    }
};

// Solution 3. Math, C++ version of this thread: https://discuss.leetcode.com/topic/17348/explain-like-i-m-five-java-solution-in-o-n
// Run time: 3ms
class Solution {
public:
    string getPermutation(int n, int k) {
        string s = "", res = "";
        vector<int>factorial(n + 1, 1);
        int sum = 1;
        for(int i = 1; i <= n; i++){
            s.push_back(i + '0');
            sum *= i;
            factorial[i] = sum;
        }
        k--;
        for(int i = 1; i <= n; i++){
            int index = k / factorial[n - i];
            res.push_back(s[index]);
            s.erase(s.begin() + index);
            k %= factorial[n - i];
        }
        return res;
    }
};
