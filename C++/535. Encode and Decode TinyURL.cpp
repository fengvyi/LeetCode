class Solution {
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        v.push_back(longUrl);
        return to_string(v.size() - 1);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return v[stoi(shortUrl)];
    }
    
private:
    vector<string>v;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

// Best answer (joke).
class Solution {
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        return longUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return shortUrl;
    }
};
