[303.range-sum-query-immutable](https://leetcode.com/problems/range-sum-query-immutable/)  

Given an integer array _nums_, find the sum of the elements between indices _i_ and _j_ (_i_ ≤ _j_), inclusive.

**Example:**  

  
Given nums = \[-2, 0, 3, -5, 2, -1\]
  

  
sumRange(0, 2) -> 1
  
sumRange(2, 5) -> -1
  
sumRange(0, 5) -> -3
  

**Note:**  

1.  You may assume that the array does not change.
2.  There are many calls to _sumRange_ function.  



**Solution:**  

```cpp
class STree{
public:
    int start,end,sum;
    STree *left, *right;

    STree(){
        start = 0;
        end = 0;
        sum = 0;
        left = nullptr;
        right = nullptr;
    }

    static STree* buildTree(vector<int>& nums, int start, int end){
        if( start > end) return nullptr;
        STree* tree = new STree();
        
        tree->start = start;
        tree->end = end;
        
        if( start == end){
            tree->sum = nums[start];
            return tree;
        } 
        
        int mid = (start+end)/2;
        tree->left = STree::buildTree(nums, start, mid);
        tree->right = STree::buildTree(nums, mid+1, end);
        if( tree->left )
            tree->sum += tree->left->sum;
        if(tree->right)
            tree->sum += tree->right->sum;
        return tree;
    }
    int range(int i, int j){
        int sum = 0;
        if( this->start==i && this->end == j )
            return this->sum;
        if( this->left && this->left->end >=i )
            sum += this->left->range(i, this->left->end <=j?this->left->end:j );
        if( this->right && this->right->start <= j )
            sum += this->right->range(this->right->start>=i?this->right->start:i, j);
        return sum;
    }
    void update(int i, int origin, int val){
        
        if( this->start <=i && this->end >=i ){
            this->sum += (val - origin);
            if( this->left){
                this->left->update(i, origin, val);
            }
            if( this->right){
                this->right->update(i, origin, val);
            }
        }
        return;
    }
};

class NumArray {
public:
    STree* tree;
    NumArray(vector<int> nums) {
        tree = STree::buildTree(nums, 0, nums.size()-1);
    }
    
    int sumRange(int i, int j) {
        return tree->range(i,j);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
```
      