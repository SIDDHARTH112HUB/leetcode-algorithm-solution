//Link: https://leetcode.com/problems/pour-water/ 
class Solution {
public:
    vector<int> pourWater(vector<int>& h, int V, int K) {
        for(int i = 0; i < V; ++i) {
            int findIdx = K;
            for(int j = K; j > 0; --j) {
                if(h[findIdx] < h[j-1]) break;
                if(h[findIdx] > h[j-1]) {
                    findIdx = j - 1;
                }
            }
            if(findIdx == K) {
                for(int j = K; j < h.size() - 1; ++j) {
                    if(h[findIdx] < h[j+1]) break;
                    if(h[findIdx] > h[j + 1]) {
                        findIdx = j + 1;
                    }
                }
            }
            ++h[findIdx];
        }
        return h;
    }
};