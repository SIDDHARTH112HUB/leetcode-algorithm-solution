//Link: https://leetcode.com/problems/design-browser-history/ 
class BrowserHistory {
public:
    vector<string> history;
    int cur = 0;
    BrowserHistory(string homepage) {
        history.push_back(homepage);    
    }
    
    void visit(string url) {
        ++cur;
        if(history.size() <= cur) {
            history.push_back(url);
            return;
        }
        history[cur] = url;
        if(history.size() > cur + 1) 
            history.resize(cur + 1);
    }
    
    string back(int steps) {
        if(cur >= steps) cur -= steps;
        else cur = 0;
        return history[cur];
    }
    
    string forward(int steps) {
        if(cur + steps < history.size()) cur += steps;
        else cur = (int)history.size() - 1;
        return history[cur];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */