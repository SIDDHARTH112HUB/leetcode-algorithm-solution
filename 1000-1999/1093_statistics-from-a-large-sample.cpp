//Link: https://leetcode.com/problems/statistics-from-a-large-sample/ 
class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        long long mn = -1, mx = -1, sum = 0, md = -1;
        double fmd = 0;
        long long total = accumulate(count.begin(), count.end(), 0);
        long long me = max_element(count.begin(), count.end()) - count.begin();
        long long prev =  0;
        long long sum2 = 0;
        vector<double> ans(4);
        for(int i = 0; i < count.size(); ++i) {
            if( count[i] > 0 && mn == -1){
                mn = i;
            }
            if( count[count.size()-1-i] > 0 && mx == -1)
                mx = count.size()-1-i;
            
            if(sum + count[i] >= (total+1) / 2 && md == -1) {
                if( total % 2 == 1){
                    md = i;
                    fmd = md;
                }
                else{
                    if(sum + count[i] == (total+1) / 2){
                        int cur = i+1;
                        for(int j = i+1; j< count.size();++j)
                            if(count[j]> 0){
                                cur = j;
                                break;
                            }
                        fmd = (cur+i) / 2.0;
                        md = fmd;
                    }else{
                        fmd = i;
                        md = i;
                    }
                }
            }
            if(count[i]> 0)
                prev = i;
            sum += count[i];
            sum2 += count[i] *i;
        }
        ans = {mn, mx, sum2*1.0/total, fmd, me};
        return ans;
    }
};