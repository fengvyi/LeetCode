/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        vector<string>cur, next;
        cur = wordlist;
        for (int i = 0; i < 10; ++i) {
            int n = cur.size();
            auto word = cur[rand() % n];
            int match = master.guess(word);
            if (match == 6) {
                break;
            }
            for (auto& s: cur) {
                if (distance(s, word) == match) {
                    next.push_back(s);
                }
            }
            cur.clear();
            swap(cur, next);
        }
    }
    
    int distance(string& a, string& b) {
        int res = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] == b[i]) {
                ++res;
            }
        }
        return res;
    }
};
