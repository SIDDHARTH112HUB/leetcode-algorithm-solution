[838.push-dominoes](https://leetcode.com/problems/push-dominoes/)  

There are `N` dominoes in a line, and we place each domino vertically upright.

In the beginning, we simultaneously push some of the dominoes either to the left or to the right.

![](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/05/18/domino.png)

After each second, each domino that is falling to the left pushes the adjacent domino on the left.

Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.

When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.

For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.

Given a string "S" representing the initial state. `S[i] = 'L'`, if the i-th domino has been pushed to the left; `S[i] = 'R'`, if the i-th domino has been pushed to the right; `S[i] = '.'`, if the `i`\-th domino has not been pushed.

Return a string representing the final state. 

**Example 1:**

**Input:** ".L.R...LR..L.."
**Output:** "LL.RR.LLRRLL.."

**Example 2:**

**Input:** "RR.L"
**Output:** "RR.L"
**Explanation:** The first domino expends no additional force on the second domino.

**Note:**

1.  `0 <= N <= 10^5`
2.  String `dominoes` contains only `'L`', `'R'` and `'.'`  



**Solution:**  

```cpp
class Solution {
public:
    string pushDominoes(string dominoes) {
        int size = dominoes.size();
        map<int, char> d;
        //d[-1] = 'L';
        d[size] = 'R';
        for(int i = 0; i<size; i++){
            if( dominoes[i] != '.'){
                d[i] = dominoes[i];
            }
        }
        //cout<<"begin "<<endl;
        char prev = 'L'; 
        int prev_idx = -1;
        for( auto &it:d){
            char dir = it.second;
            int idx = it.first;
            /*if( idx == prev_idx ){
                continue;
            }*/
            //cout<<"prev "<<prev<<prev_idx<<" dir "<<dir<<idx<<endl;
            if( dir == 'L' && prev=='R'){
                for( int i = 1; i<=(idx-prev_idx-1)/2; i++){
                    dominoes[i+prev_idx] = 'R';
                    dominoes[idx-i] = 'L';
                }
            }
            else if( dir=='L' ){
                for( int i =idx-1; i>=0; i--){
                    if( dominoes[i] == '.')
                        dominoes[i] = 'L';
                    else
                        break;
                }
            }else if( prev=='R' ){
                //cout<<"prev == R "<< prev_idx+1 << " "<<size<<endl;
                for( int i =prev_idx+1; i<size; i++){
                    //cout<<dominoes[i]<<" i: "<<i<<" "<<size<<endl;
                    if( dominoes[i] == '.')
                        dominoes[i] = 'R';
                    else
                        break;
                }
            }
            prev = dir;
            prev_idx = idx;
            
        }
        return dominoes;
    }
};
```
      