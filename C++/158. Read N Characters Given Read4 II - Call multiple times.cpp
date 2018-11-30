// Forward declaration of the read4 API.
int read4(char *buf);

// Solution 1.
class Solution {
private:
    int ptr = 0;
    char* tmp = new char[4];
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int cnt = 0;
        int k;
        while(cnt < n){
            if(ptr == 0) k = read4(tmp);
            if(k == 0) break;
            while(cnt < n && ptr < k){
                buf[cnt++] = tmp[ptr++];
            }
            if(ptr == k) ptr = 0;
        }
        return cnt;
    }
};

// Solution 2.
class Solution {
private:
    int p = 4;
    int i = 4;
    char tmp[4];
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int sum = 0;
        while(sum < n){
            if(p == i){
                i = read4(tmp);
                p = 0;
            }
            if(i == 0) break;
            *buf++ = tmp[p++];
            sum++;
        }
        return sum;
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
            if (p == cnt) {
                cnt = read4(tmp);
                p = 0;
            }
            if (cnt == 0) {
                break;
            }
            *buf++ = tmp[p++];
            ++count;
            --n;
        }
        return count;
    }
    
private:
    int p = 4;
    int cnt = 4;
    char tmp[4];
};
