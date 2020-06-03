//Link: https://leetcode.com/problems/design-underground-system/ 
class UndergroundSystem {
public:
    unordered_map<string, unordered_map<int, int> > in;
    unordered_map<string, unordered_map<int, int> > out;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        in[stationName][id] = t;
    }
    
    void checkOut(int id, string stationName, int t) {
        out[stationName][id] = t;
    }
    
    double getAverageTime(string startStation, string endStation) {
        int num = 0, time = 0;
        auto &sin = in[startStation];
        for(auto it : out[endStation]) {
            int id = it.first;
            int e = it.second;
            if(sin.count(id)) {
                ++num;
                time += e - sin[id];
            }
        }
        if(num == 0 ) return 0;
        return time * 1.0 / num;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */