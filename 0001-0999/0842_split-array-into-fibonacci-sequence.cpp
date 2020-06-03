//Link: https://leetcode.com/problems/split-array-into-fibonacci-sequence/ 
class Solution {
public:
    vector<int> ans;
    vector<int> splitIntoFibonacci(string S) {
        int size = S.size();
        if(size<3)return ans;
        vector<int> nums;
        int res = dfs(S, 0, nums);
        return nums;
    }
    int string2i(string& s, int l, int r){
        long long num = 0;
        for( int i = l; i<=r; i++){
            num = (num * 10) + (s[i]-'0');
        }
        if( num > INT_MAX )
            return -1;
        return num;
    }
    bool dfs(string& S, int idx, vector<int> &nums){
        int size = S.size();
        if( idx >= size ){
            return nums.size()>2;
        } 
        for( int i = idx+1; i<=S.size(); i++){
            int n1 = string2i(S, idx, i-1);
            if( n1<0 )
                return false;
            if( nums.size() >= 2 ){
                
                int sum = nums[nums.size()-1] + nums[nums.size()-2];
                if( sum == n1 ){
                    nums.push_back(n1);
                }
                else
                    continue;
            }else{
                nums.push_back(n1);
            }
            int res = dfs(S, i, nums);
            if( res == true )
                return true;
            else{
                nums.pop_back();
            }
            if( S[idx] == '0')
                break;
        }
        return false;
    }
};