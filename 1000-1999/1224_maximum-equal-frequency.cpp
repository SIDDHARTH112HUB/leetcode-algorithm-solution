//Link: https://leetcode.com/problems/maximum-equal-frequency/ 
struct Obj {
public:
    int mx = 0;
    int mn = 0;
    map<int, unordered_set<int> > cnt;
    unordered_map<int, int> m;
    Obj() {
        
    }
    
    void inc(int key) {
        int count = m[key]++;
        if(count > 0) {
            if(cnt[count].size() > 1)
                cnt[count].erase(key);
            else
                cnt.erase(count);
        }
        ++count;
        if(cnt.count(mn) == 0)
            mn = count;
        else
            mn = min(mn, count);
        cnt[count].insert(key);
        mx = max(mx, count);
    }
    
    void dec(int key) {
        if(m[key] == 0) return;
        int count = m[key]--;
        if(cnt[count].size() <= 1)
            cnt.erase(count);
        else
            cnt[count].erase(key);
        if(cnt.count(mx) == 0)
            mx -= 1;
        --count;
        if(count > 0)
            cnt[count].insert(key);
        else
            m.erase(key);
        mn = min(mn, count);
        if(mn == 0 && mx > 0) {
            cnt.erase(0);
            mn = cnt.size() ? cnt.begin()->first : 0;
            /*for(auto &it : cnt) 
                if(it.first > 0 || mn == 0)
                    mn = min(mn == 0 ? INT_MAX:mn, it.first);*/
        }
    }
    
    int getMaxKey() {
        if(cnt[mx].size() == 0) return 0;
        return *cnt[mx].begin();
    }
    
    int getMinKey() {
        if(cnt[mn].size() == 0) return 0;
        return *cnt[mn].begin();
    }
};

class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        Obj o;
        for(auto n : nums) {
            o.inc(n);
        }
        for(int i = nums.size() - 1; i>= 0; --i) {
            int mx = o.mx, mn = o.mn;
            if(o.mx == 1 && o.mn == 1) return i + 1;
            if(o.m.size() == 1) return i+ 1;
            if(o.mx == o.mn) {
                o.dec(nums[i]);
                continue;
            }
            if(o.cnt[mx].size() > 1 && o.cnt[mn].size() > 1) {
                o.dec(nums[i]);
                continue;
            }
            int mxk = o.getMaxKey();
            o.dec(mxk);
            //cout<<o.mx<<" "<<o.mn<<" mxk:"<<mxk<<endl;
            if(o.mx == o.mn)
                return i + 1;
            o.inc(mxk);
            int mnk = o.getMinKey();
            o.dec(mnk);
            //cout<<o.mx<<" "<<o.mn<<" mnk:"<<mnk<<endl;
            if(o.mx == o.mn)
                return i + 1;
            o.inc(mnk);
            o.dec(nums[i]);
        }
        return 0;
    }
};