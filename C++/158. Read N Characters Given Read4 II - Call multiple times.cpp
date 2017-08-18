// Forward declaration of the read4 API.
int read4(char *buf);

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
