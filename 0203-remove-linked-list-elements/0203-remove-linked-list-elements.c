/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* curr=head;
    struct ListNode* prev=head;
    while(curr!=NULL){
        if(curr->val==val){
            if(curr==head){
                head=curr->next;
                continue;
            }
            // printf("%d", curr->val);
            prev->next=curr->next;
            curr=prev->next;
            continue;
        }
        prev=curr;
        curr=curr->next;
    }
    return head;
}