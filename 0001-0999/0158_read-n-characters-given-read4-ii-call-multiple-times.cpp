//Link: https://leetcode.com/problems/read-n-characters-given-read4-ii-call-multiple-times/ 
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
    int readPos = 0;
    int writePos = 0;
    char b[4];
    int read(char *buf, int n) {
        int i = 0;
        for(; i < n; ++i) {
            if(readPos == writePos) {
                writePos = read4(b);
                readPos = 0;
                if(writePos == 0)
                    return i;
            }
            buf[i] = b[readPos++];
        }
        return n;
    }
};