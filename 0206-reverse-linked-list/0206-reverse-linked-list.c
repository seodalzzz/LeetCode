/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev= head;
    if(prev==NULL){
        return NULL;
    }
    struct ListNode* curr= prev->next;
    if(curr==NULL){
        return head;
    }
    struct ListNode* next=curr->next;
    if(next==NULL){
        curr->next= head;
        head=curr;
        curr->next->next=NULL;
        
        return head;
    }
    while(curr!=NULL){
        if(prev==head){
            prev->next=NULL;
        }
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    printf("%d\n",prev->val);
    head=prev;
    return prev;
}