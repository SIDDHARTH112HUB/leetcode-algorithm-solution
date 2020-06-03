//Link: https://leetcode.com/problems/gas-station/ 
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int NG = gas.size();
        int CG = cost.size();
        if( NG == 0 ) return -1;
        int count = 0;
        int gas_num = 0;
        int cost_num = 0;
        int cc = 0;
        while( count <= 2*NG ){
            int cnt = count%NG;
            if( gas_num + gas[cnt] >= cost[cnt]){
                gas_num += (gas[cnt] - cost[cnt]);
                cc += 1;
            }else{
                gas_num = 0;
                cost_num = 0;
                cc = 0;
            }
            count++;
            if( cc >= NG )
                return count%NG;
        }
        return -1;
    }
};