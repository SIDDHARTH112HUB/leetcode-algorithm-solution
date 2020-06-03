//Link: https://leetcode.com/problems/fruit-into-baskets/ 
class Solution {
public:
    int totalFruit(vector<int>& tree) {
        if( tree.size() == 0 ) return 0;
        map<int, int> m;
        int type = 0;
        int ans = 0;
        int begin = 0;
        int prev = 0;
        prev = tree[0];
        m[tree[0]] = 0;
        for( int i = 1; i<tree.size(); i++){
            if( m.size() < 2 ){
                if( prev != tree[i])
                    m[tree[i]] = i;
                prev = tree[i];
            }else{
                
                if( m.count(tree[i]) == 0 ){
                    /*int k = m.begin()->first;
                    begin = m.begin()->second;
                    ans = max(ans, i-begin);
                    if( m.begin()->second < m.rbegin()->second ){
                        k = m.rbegin()->first;
                        begin = m.rbegin()->second;
                    }
                    */
                    ans = max(ans, i-begin);
                    for( auto it = m.begin(); it!=m.end(); ++it ){
                        if( it->first != tree[i-1]){
                            m.erase(it);
                            break;
                        }
                    }
                    //cout<<"size: "<<m.size()<<endl;
                    begin = m.begin()->second;
                }
                if( prev != tree[i])
                    m[tree[i]] = i;
                prev = tree[i];
            }
        }
        ans = max(ans, int(tree.size()-begin));
        return ans;
    }
};