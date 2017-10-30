class Solution {
public:
    string minAbbreviation(string target, vector<string>& dictionary) {
        string res = "";
        bool found = false;
        for(int i = 0; i <= target.size() && !found; i++) DFS(dictionary, i, 0, target, res, found, vector<int>());
        return res;
    }
    // k: number of letters to pick
    // vec: indices of letters picked
    void DFS(vector<string>& dictionary, int k, int pos, string target, string& res, bool& found, vector<int> vec){
        if(k == 0){  
            int i = 0;
            for(; i < dictionary.size(); i++){
                if(dictionary[i].size() != target.size()) continue;  // word of different length won't cause conflict
                int count = 0;
                for(int x: vec) if(target[x] == dictionary[i][x]) count++;
                if(vec.empty() || count == vec.size()) break;  // encounter a conflict word
            }
            if(i == dictionary.size()){
                found = true;
                if(vec.empty()){
                    res = to_string(target.size());
                    return;
                }
                // translate 'vec' into abbreviation(string)
                string s = "";
                sort(vec.begin(), vec.end());
                for(int j = 0; j < vec.size(); s += target[vec[j]], j++)
                    if(j == 0) s += (vec[0] == 0) ? "" : to_string(vec[0]);
                    else s += (vec[j] - vec[j - 1] - 1 == 0) ? "" : to_string(vec[j] - vec[j - 1] - 1);
                if(vec.back() != target.size() - 1) s += to_string(target.size() - vec.back() - 1);
                if(res.empty() || length(res) > length(s)) res = s;
            }
            return;
        }
        if(pos == target.size()) return;
        DFS(dictionary, k, pos + 1, target, res, found, vec);
        vec.push_back(pos);
        DFS(dictionary, k - 1, pos + 1, target, res, found, vec);
    }
    
    int length(string& s){
        int len = 0;
        for(int i = 0; i < s.size(); i++, len++)
            if(isdigit(s[i])) while(i + 1 < s.size() && isdigit(s[i + 1])) i++;
        return len;
    }
};
