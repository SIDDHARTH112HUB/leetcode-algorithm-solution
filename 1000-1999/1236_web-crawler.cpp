//Link: https://leetcode.com/problems/web-crawler/ 
/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */

class Solution {
public:
    string hostname;
    unordered_set<string> v;
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        
        for(int i = 0; i < startUrl.size(); ++i) {
            if(startUrl[i] == '/' && (i + 1 < startUrl.size() && startUrl[i+1] != '/' && startUrl[i-1] != '/')) {
                break;
            }
            hostname += startUrl[i];
        }
        cout<<hostname<<endl;
        vector<string> ans;
        dfs(startUrl, htmlParser);
        for(auto &url : v) {
            if(url.find(hostname) != string::npos)
                ans.push_back(url);
        }
        return ans;
    }
    void dfs(string &url, HtmlParser &htmlParser) {
        if(v.count(url)) return;
        v.insert(url);
        if(url.find(hostname) == string::npos) return;
        auto urls = htmlParser.getUrls(url);
        for(auto &next : urls) {
            dfs(next, htmlParser);
        }
    }
};