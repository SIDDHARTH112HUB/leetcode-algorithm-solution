//Link: https://leetcode.com/problems/friends-of-appropriate-ages/ 
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int n = ages.size();
        vector<int> age_vec(121);
        
        int ans = 0;
        for( int age:ages){
            age_vec[age]++;
        }
        for( int i = 121-1; i>=1; i--){
            for( int j = 0.5*i+8;j<=i;j++){
            //for( int j = i; j>=0; j--){
                    ans += age_vec[i] * (age_vec[j] - (i==j));
                    continue;
                int ageA = i;
                    int ageB = j;
                    int ageACnt = age_vec[i], ageBCnt = age_vec[j];
                    if( ageACnt == 0 || ageBCnt == 0 )
                        continue;
                    if( ageA < 100 && ageB > 100 )
                        break;
                    if( ageA*0.5 +7 >= ageB )
                        break;
                    if( i == j ){
                        ans += (ageACnt-1) * (ageACnt);
                        continue;
                    }
                    
                    
                    ans += ageACnt * ageBCnt;
            }
        }
        return ans;
    }
};