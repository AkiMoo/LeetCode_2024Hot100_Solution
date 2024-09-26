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
    bool isPalindrome(ListNode* head) {
        ListNode* p1;
        ListNode* p2;
        p1 = head, p2 = head;
        while(p2->next!=nullptr){
            p1 = p1 -> next;
            p2 = p2 -> next;
            if(p2->next!=nullptr){
                p2 = p2 -> next;
            }
        }
        ListNode* newhead = nullptr;
        while(p1!=nullptr){
            ListNode *temp;
            temp = p1->next;
            p1->next = newhead;
            newhead = p1;
            p1 = temp;
        }
        p2 = head;
        while(newhead!=nullptr){
            if(p2->val!=newhead->val){
                return false;
            }
            newhead = newhead->next;
            p2 = p2->next;
        }
        return true;
    }
};
