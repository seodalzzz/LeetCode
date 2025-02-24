/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeNodes(struct ListNode* head) {
    struct ListNode * result=(struct ListNode*)malloc(sizeof(struct ListNode));
    result->val=0;
    result->next=NULL;
    struct ListNode * curr=head;
    struct ListNode* resultcurr=result;
    int sum=0;
    while(curr!=NULL){
        if(curr->val==0){
            resultcurr->next=(struct ListNode*)malloc(sizeof(struct ListNode));
            resultcurr->next->val=sum;
            resultcurr=resultcurr->next;
            resultcurr->next=NULL;
            sum=0;
        }
        sum+=curr->val;
        curr=curr->next;
    }
    return result->next->next;
    
}