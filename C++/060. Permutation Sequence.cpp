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
