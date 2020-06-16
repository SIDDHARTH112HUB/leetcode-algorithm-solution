[1152.analyze-user-website-visit-pattern](https://leetcode.com/problems/analyze-user-website-visit-pattern/)  

We are given some website visits: the user with name `username[i]` visited the website `website[i]` at time `timestamp[i]`.

A _3-sequence_ is a list of websites of length 3 sorted in ascending order by the time of their visits.  (The websites in a 3-sequence are not necessarily distinct.)

Find the 3-sequence visited by the largest number of users. If there is more than one solution, return the lexicographically smallest such 3-sequence.

**Example 1:**

  
**Input:** username = \["joe","joe","joe","james","james","james","james","mary","mary","mary"\], timestamp = \[1,2,3,4,5,6,7,8,9,10\], website = \["home","about","career","home","cart","maps","home","home","about","career"\]  
**Output:** \["home","about","career"\]  
**Explanation: **  
The tuples in this example are:  
\["joe", 1, "home"\]  
\["joe", 2, "about"\]  
\["joe", 3, "career"\]  
\["james", 4, "home"\]  
\["james", 5, "cart"\]  
\["james", 6, "maps"\]  
\["james", 7, "home"\]  
\["mary", 8, "home"\]  
\["mary", 9, "about"\]  
\["mary", 10, "career"\]  
The 3-sequence ("home", "about", "career") was visited at least once by **2** users.  
The 3-sequence ("home", "cart", "maps") was visited at least once by 1 user.  
The 3-sequence ("home", "cart", "home") was visited at least once by 1 user.  
The 3-sequence ("home", "maps", "home") was visited at least once by 1 user.  
The 3-sequence ("cart", "maps", "home") was visited at least once by 1 user.  

**Note:**

1.  `3 <= N = username.length = timestamp.length = website.length <= 50`
2.  `1 <= username[i].length <= 10`
3.  `0 <= timestamp[i] <= 10^9`
4.  `1 <= website[i].length <= 10`
5.  Both `username[i]` and `website[i]` contain only lowercase characters.
6.  It is guaranteed that there is at least one user who visited at least 3 websites.
7.  No user visits two websites at the same time.  



**Solution:**  

```cpp
class Solution {
public:
    unordered_map<string, vector<pair<int, string> > > uservisit;
    unordered_map<string, unordered_set<string> > seqCnt;
    int maxCnt = 0;
    string ans;
    vector<string> vans;
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        for(int i = 0; i < username.size(); ++i) {
            
            uservisit[username[i]].push_back({timestamp[i], website[i]});
        }
        for(auto it : uservisit){
            sort(it.second.begin(), it.second.end());
            vector<string> item;
            auto seq = it.second;
            auto un = it.first;
            helper(seq, un, 0, item);
        }
        return vans;
    }
    
    void helper(vector<pair<int, string> > &seq, string &user, int idx, vector<string> &item) {
        if(item.size() == 3) {
            string str = item[0] + "," + item[1] + "," + item[2];
            seqCnt[str].insert(user);
            int c = seqCnt[str].size();
            if(c > maxCnt) {
                //cout<<"count: "<<str<<endl;
                ans = str;
                vans = item;
                maxCnt =c;
            }else if( c == maxCnt) {
                if(ans > str || ans == ""){
                    ans = str;
                    vans = item;
                }
            }
            return;
        }
        for(int i = idx; i < seq.size(); ++i) {
            item.push_back(seq[i].second);
            helper(seq, user, i + 1, item);
            item.pop_back();
        }
    }
};
```
      