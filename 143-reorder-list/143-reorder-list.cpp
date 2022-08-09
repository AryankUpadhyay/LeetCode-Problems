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
    void reorderList(ListNode* head) {
        ListNode* start=head;
        stack<ListNode*> st;
        int len=0;
        while(start!=NULL){
            st.push(start);
            start=start->next;
            len++;
        }
        len=(len+1)/2;
        // cout<<"Len=> "<<len<<endl;
        ListNode* ptr=head;
        while(st.top()!=ptr && len--){
            ListNode* temp=ptr->next;
            ptr->next=st.top();
            st.top()->next=temp;
            ptr=temp;
            st.pop();
        }
        ptr->next=NULL;
        // while(head!=NULL){
        //     cout<<head->val<<" ";
        //     head=head->next;
        // }
        // cout<<endl;
        
    }
};