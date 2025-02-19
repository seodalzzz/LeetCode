/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int getDecimalValue(struct ListNode* head) {
    struct ListNode* curr=head;
    int bitop=1;
    while(curr!=NULL){
        bitop=bitop*2;
        curr=curr->next;
    }
    bitop=bitop/2;
    curr=head;
    int sum=0;
    while(curr!=NULL){
        sum+=bitop*curr->val;
        bitop=bitop/2;
        curr=curr->next;
    }
    return sum;


}