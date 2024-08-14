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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       ListNode *temp = head;
       int count = 0;

       while(temp){
        count++;
        temp = temp->next;
       }

       if(count == 1){
        delete head;
        return nullptr;
       }
        

       int newCount = count-n;
       if (newCount == 0) {
            ListNode* temp1 = head;
            head = head->next;  
            delete temp1;  
            return head;
        }

       ListNode *result = head;
       ListNode *prev = NULL;

       for(int i = 0;i<newCount;i++){
        prev = result;
        result = result->next;
       }

       prev->next = result->next;
       delete result;

       return head;
    }
};
