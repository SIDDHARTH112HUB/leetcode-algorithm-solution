[841.keys-and-rooms](https://leetcode.com/problems/keys-and-rooms/)  

There are `N` rooms and you start in room `0`.  Each room has a distinct number in `0, 1, 2, ..., N-1`, and each room may have some keys to access the next room. 

Formally, each room `i` has a list of keys `rooms[i]`, and each key `rooms[i][j]` is an integer in `[0, 1, ..., N-1]` where `N = rooms.length`.  A key `rooms[i][j] = v` opens the room with number `v`.

Initially, all the rooms start locked (except for room `0`). 

You can walk back and forth between rooms freely.

Return `true` if and only if you can enter every room.

**Example 1:**

  
**Input:** \[\[1\],\[2\],\[3\],\[\]\]
  
**Output:** true
  
**Explanation:** 
  
We start in room 0, and pick up key 1.
  
We then go to room 1, and pick up key 2.
  
We then go to room 2, and pick up key 3.
  
We then go to room 3.  Since we were able to go to every room, we return true.
  

**Example 2:**

  
**Input:** \[\[1,3\],\[3,0,1\],\[2\],\[0\]\]
  
**Output:** false
  
**Explanation:** We can't enter the room with number 2.
  

**Note:**

1.  `1 <= rooms.length <= 1000`
2.  `0 <= rooms[i].length <= 1000`
3.  The number of keys in all rooms combined is at most `3000`.  



**Solution:**  

```cpp
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
```
      