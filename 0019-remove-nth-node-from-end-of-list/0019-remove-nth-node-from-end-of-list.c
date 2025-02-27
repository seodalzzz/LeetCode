/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* curr=head;
    int len=1;
    if(head==NULL){
        return NULL;
    }
    while(curr->next!=NULL){
        curr=curr->next;
        len++;
    }
    printf("len: %d",len);
    if(len==1 && n==1){
        head=NULL;
        return head;
    }
    struct ListNode* tail=curr;
    tail->next=head;
    int cnt=len-n;
    for(int i=0;i<cnt;i++){
        curr=curr->next;
    }
    printf("curr: %d, tail: %d\n",curr->val,tail->val);
    if(curr==tail){
        head=curr->next->next;
        tail->next=NULL;
        return head;
    }
    if(curr->next==tail){
        curr->next=NULL;
        return head;
    }
    curr->next=curr->next->next;
    tail->next=NULL;
    return head;


}