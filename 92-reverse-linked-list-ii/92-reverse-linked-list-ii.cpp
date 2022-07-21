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
    ListNode* traversing(ListNode* head, int left){
        if(left==0)
            return head;
        else{
            return traversing(head->next, left-1);
        }
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(head==NULL || head->next==NULL || left==right){
            return head;
        }
        ListNode* start=head;
        if(left>=2){
            start=traversing(head, left-2);
        }
        ListNode* ptr=traversing(head, left-1);
        ListNode* end=traversing(head, right-1);
        int dif=right-left;
        ListNode* curr=ptr->next;
        ListNode* prev=curr;
        ListNode* temp=ptr;
        while(dif--){
            if(curr==NULL)
                break;
            curr=curr->next;
            prev->next=temp;
            temp=prev;
            prev=curr;
            
        }
        if(left<2){
            head=temp;
            start->next=curr;
            return head;
        }
        else{
            start->next=temp;
            ptr->next=curr;
            return head;
        }
    }
};