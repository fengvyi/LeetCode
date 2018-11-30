// Forward declaration of the read4 API.
int read4(char *buf);

// Solution 1.
class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int sum = 0;
        for(int i = 0; i < n; i += 4){
            sum += read4(buf);
            buf += 4;
        }
        return min(sum, n);
    }
};

// Solution 2.
class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int sum = 0, i = 4;
        while(sum < n && i == 4){
            i = read4(buf);
            buf += 4;
            sum += i;
        }
        return min(sum, n);
    }
};

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int count = 0;
        while (n) {
            int x = read4(buf);
            count += min(x, n);
            n = max(0, n - x);
            buf += x;
            if (x < 4) {
                break;
            }
        }
        return count;
    }
};
