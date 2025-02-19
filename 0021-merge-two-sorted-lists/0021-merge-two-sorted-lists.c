/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* curr=(struct ListNode*)malloc(sizeof(struct ListNode));
    curr->val=0;
    curr->next=NULL;
    struct ListNode* newlist=curr;
    struct ListNode* curr1=list1;
    struct ListNode* curr2=list2;
    while(curr1!=NULL && curr2!=NULL){
        if(curr1->val < curr2->val){
            curr->next=(struct ListNode*)malloc(sizeof(struct ListNode));
            curr->next->val=curr1->val;
            curr=curr->next;
            curr1=curr1->next;
        }
        else{
            curr->next=(struct ListNode*)malloc(sizeof(struct ListNode));
            curr->next->val=curr2->val;
            curr=curr->next;
            curr2=curr2->next;
        }
    }
    if(curr1==NULL){
        curr->next=curr2;
    }else{
        curr->next=curr1;
    }
    return newlist->next;
}