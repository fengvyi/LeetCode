/**
 * Solution 1. 
 * Brute force, simple and easy.
 * Time complexity : O(n*m)
 * Space comlexity : O(1)
 * Run time : 109 ms
 */
class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.size() == 0) return 0;
		for (int i = 0; i < haystack.size(); i++)
			if (haystack[i] == needle[0] && isEqual(haystack.substr(i), needle)) return i;
		return -1;
	}

	bool isEqual(string s1, string s2) {
		if (s1.size() < s2.size()) return false;
		for (int i = 0; i < s2.size(); i++)
			if (s1[i] != s2[i]) return false;
		return true;
	}
};

// Or move isEqual() function inside.
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0) return 0;
        for(int i = 0; i < haystack.size(); i++){
            int j = 0;
            for(;j < needle.size(); j++){
                if(i + j == haystack.size()) return -1;
                if(haystack[i + j] != needle[j]) break;
            }
            if(j == needle.size()) return i;
        }
        return -1;
    }
};

/**
 * Solution 2. 
 * In BF solution, we compare two strings everytime we meet the charactor needle[0], 
 * which can cause a lot of unnecessary calculations.
 * Is there a way to "shrink" the candidate substrings ?
 * We can use a hash table to count the number of occurrence of `char`s in needle, 
 * and only jump to comparison when substring in haystack has the same `char`s and occurrence with needle.
 * Time complexity : O(n)
 * Space complexity : O(n)
 * Run time : 6 ms
 */
class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.size() == 0) return 0;
		unordered_map<char, int>m;
		for (auto x : needle) m[x]++;
		int count = needle.size();
		int begin = 0, end = 0;
		while (end < haystack.size()) {
			if (m[haystack[end++]]-- > 0) count--;
			if (count == 0) {
				int i = begin, j = 0;
				while (j < needle.size() && haystack[i] == needle[j]) i++, j++;
				if (j == needle.size()) return begin;
			}
			if (end - begin == needle.size() && m[haystack[begin++]]++ >= 0) count++;
		}
		return -1;
	}
};

/**
 * Solution 3. 
 * Finally, a "cheat" solution.
 * Time complexity : O(n)
 * Space complexity : O(1)  (not sure about that, correct me if I'm wrong)
 * Run time : 6 ms
 */
class Solution {
public:
	int strStr(string haystack, string needle) {
		return haystack.find(needle);
	}
};
