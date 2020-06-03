//Link: https://leetcode.com/problems/read-n-characters-given-read4/ 
/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int l = 0;
        char b[4];
        int idx = 0;
        while((l = read4(b))) {
            for(int i = 0; i < l; ++i) {
                if(idx >= n) break;
                buf[idx] = b[i];
                ++idx;
            }
            if(idx >= n) break;
        }
        return idx;
    }
};