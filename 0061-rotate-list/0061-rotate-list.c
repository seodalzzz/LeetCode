/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(head==NULL){
        return head;
    }
    struct ListNode* tail=head;
    int len=1;
    while(tail->next!=NULL){
        tail=tail->next;
        len++;
    }
    tail->next=head;
    struct ListNode* newhead=head;
    k=k%len;
    for (int i=0;i<len-k;i++){
        newhead=newhead->next;
    }
    struct ListNode* prev= head;
    while(prev->next!=newhead){
        prev=prev->next;
    }
    prev->next=NULL;

    printf("tail : %d\n newhead: %d\n prev: %d\n\n",tail->val, newhead->val, prev->val);
    return newhead;

}