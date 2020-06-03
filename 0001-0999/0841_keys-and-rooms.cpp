//Link: https://leetcode.com/problems/keys-and-rooms/ 
class Solution {
public:
    int *visit;
    int visit_num  = 1;
    int room_num = 0;
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        room_num = rooms.size();
        //visit.resize(room_num);
        visit = new int[room_num];
        
        memset(visit, 0, sizeof(int)*room_num);
        visit[0] = 1;
        dfs(rooms, 0, 0);
        //cout<<visit_num<<room_num<<endl;
        return visit_num >= (room_num);
    }
    void dfs(vector<vector<int>>& rooms, int room_idx, int key_idx){
        vector<int> &key_list = rooms[room_idx];
        for( int i = key_idx; i<key_list.size();i++){
            int cur_key = key_list[i];
            if( cur_key < 0 )
                continue;
            if( !visit[cur_key] ){
                visit_num++;
                visit[cur_key] = 1;
                if( visit_num >= room_num )
                    return;
            }
            key_list[i] = -1;
            dfs(rooms, cur_key, 0);
        }
    }
};