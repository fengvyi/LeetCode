class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int count = 0, n = sentence.size(), idx = 0;
        for (int i = 0; i < rows; ++i) {
            int slot = cols;
            while (slot > 0 && slot >= sentence[idx].size()) {
                slot -= sentence[idx].size() + 1;
                ++idx;
                if (idx == n) {
                    ++count;
                    idx = 0;
                }
            }
        }
        return count;
    }
};
