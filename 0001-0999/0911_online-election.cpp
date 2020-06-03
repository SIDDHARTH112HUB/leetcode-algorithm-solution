//Link: https://leetcode.com/problems/online-election/ 
class TopVotedCandidate {
public:
    map<int, int> mt;
    unordered_map<int, int> count;
    TopVotedCandidate(vector<int> persons, vector<int> times) {
        int max_count= 0;
        int max_count_person = 0;
        for( int i = 0; i < persons.size(); i++){
            int p = persons[i], t = times[i];
            count[p]++;
            if( count[p] >= max_count ){
                mt[t] = p;
                max_count = count[p];
                max_count_person = p;
            }else{
                mt[t] = max_count_person;
            }
        }
    }
    
    int q(int t) {
        auto it = --mt.upper_bound(t);
        return it->second;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj.q(t);
 */