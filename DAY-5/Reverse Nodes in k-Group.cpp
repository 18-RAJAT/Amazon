/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        //Temp will be pointing to head 
        ListNode* temp = head;
        
        
        for(int i=1;i<k;++i)
        {
            //Base case
            if(temp == NULL)
            {
                return head;
            }
            
            //now head will be pointing to the next
            temp = temp->next;
        }
        
        //Initial conditions 
        ListNode* current = head;
        ListNode* previous = NULL;
        ListNode* next = NULL;
        
        //K times we will be traversing the condition
        for(int i=1;i<k;++i)
        {
            //Edge to Edge we will reverse
            next = current->next;
            
            current->next = previous;
            
            previous = current;
            
            current = next;
        }
        
        head->next = reverseKGroup(current,k);
        
        return previous;
        
    }
};