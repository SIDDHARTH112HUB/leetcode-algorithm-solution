//Link: https://leetcode.com/problems/copy-list-with-random-pointer/ 
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if( head == NULL ) return NULL;
        map<int, RandomListNode*> data;
        
        RandomListNode* p = head;
        RandomListNode* new_p = new RandomListNode(head->label);
        RandomListNode* new_head = new_p;
        while(p != NULL)
        {
            RandomListNode* p_next = p->next;
            if( p->next != NULL )
            {
                RandomListNode* new_p_next = data[p_next->label];
                if( new_p_next == NULL )
                {
                    new_p_next = new RandomListNode(p_next->label);
                    data[new_p_next->label] = new_p_next;
                }
                new_p->next = new_p_next;
            }
            if( p->random != NULL )
            {
                RandomListNode* new_p_random = data[p->random->label];
                if( new_p_random == NULL)
                {
                    new_p_random = new RandomListNode( p->random->label );
                    data[p->random->label] = new_p_random;
                }
                new_p->random = new_p_random;
            }
            
            new_p = new_p->next;
            p = p->next;
        }
        return new_head;
    }
};