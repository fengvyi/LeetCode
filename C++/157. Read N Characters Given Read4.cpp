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
        int sum = 0;
        for(int i = 0; i < n; i+=4){
            sum += read4(buf);
            buf += 4;
        }
        return min(sum, n);
    }
};
