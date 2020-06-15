[399.evaluate-division](https://leetcode.com/problems/evaluate-division/)  

Equations are given in the format `A / B = k`, where `A` and `B` are variables represented as strings, and `k` is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return `-1.0`.

**Example:**  
Given `a / b = 2.0, b / c = 3.0.`  
queries are: `a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? .`  
return `[6.0, 0.5, -1.0, 1.0, -1.0 ].`

The input is: `vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries` , where `equations.size() == values.size()`, and the values are positive. This represents the equations. Return `vector<double>`.

According to the example above:

equations = \[ \["a", "b"\], \["b", "c"\] \],
values = \[2.0, 3.0\],
queries = \[ \["a", "c"\], \["b", "a"\], \["a", "e"\], \["a", "a"\], \["x", "x"\] \]. 

The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.  



**Solution:**  

```cpp
class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        map<string, map<string, double> > dict;
        for( int i = 0; i<equations.size(); i++){
            if( equations[i].first == equations[i].second)
                continue;
            dict[equations[i].first][equations[i].second] = values[i];
            if( values[i] != 0.0){
                dict[equations[i].second][equations[i].first] = 1.0/values[i];
                dict[equations[i].first][equations[i].first] = 1.0;
            }
        }
        vector<double> ans;
        
        for( auto &query:queries){
            set<string> visit;
            double val = 1.0;
            bool res = dfs(dict, query.first, query.second, val, visit);
            if( res == true )
                ans.push_back(val);
            else
                ans.push_back(-1.0);
        }
        return ans;
    }
    bool dfs(map<string, map<string, double> > &dict, string &cur, string &target, double &ans, set<string> &visit){
        if(visit.find(cur) != visit.end() )
            return false;
        visit.insert(cur);
        for(auto &it:dict[cur]){
            string str = it.first;
            double val = it.second;
            if( target == str ){
                ans *= val;
                return true;
            }else{
                bool res = dfs(dict, str, target, ans, visit);
                if( res == true ){
                    ans *= val;
                    return true;
                }
            }
        }
        return false;
    }
};
```
      