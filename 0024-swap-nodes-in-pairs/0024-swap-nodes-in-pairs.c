/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode* curr=head;
    struct ListNode* alter=head;
    struct ListNode* prev=head;
    int num=0;
    if(head==NULL){
        return NULL;
    }
    while(curr!=NULL){
        num++;
        alter=curr->next;
        if(alter==NULL){
            return head;
        }
        if(num==1){
            curr->next=alter->next;
            alter->next=curr;
            prev=curr;
            curr=curr->next;
            head=alter;
            continue;
        }
        printf("prev: %d, curr: %d, alter: %d\n",prev->val, curr->val,alter->val);
        prev->next=alter;
        curr->next=alter->next;
        alter->next=curr;

        prev=curr;
        curr=curr->next;
}
    return head;
    
}