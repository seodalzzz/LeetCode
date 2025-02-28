/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* doubleIt(struct ListNode* head) {
    struct ListNode* curr=head;
    struct ListNode* prev=head;
    int up=0;
    int num=0;
    if(curr->next==NULL){
        curr->val=curr->val*2;
        curr=curr->next;
    }
    while(curr!=NULL){
        if(curr==head){
            printf("curr: %d\n",curr->val);
            curr->val=(curr->val)*2;
            prev=curr;
            curr=curr->next;
            continue;
        }
        prev->val=prev->val+up;
        num=curr->val*2;
        if(num>=10){
            prev->val++;
            num=num-10;
        }
        curr->val=num;
        prev=curr;
        curr=curr->next;
    }
    if(head->val>=10){
        head->val=head->val-10;
        struct ListNode* new= (struct ListNode*)malloc(sizeof(struct ListNode));
        new->val=1;
        new->next=head;
        head=new;
    }
    return head;
}