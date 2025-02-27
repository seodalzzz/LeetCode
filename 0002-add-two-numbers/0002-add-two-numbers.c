/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int result=0;
    int bit=1;
    struct ListNode* curr=l1;
    struct ListNode* curr2=l2;
    struct ListNode* head=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* currr=head;
    int up=0;
    int now=0;
    head->next=NULL;
    head->val=525;
    while(curr!=NULL && curr2!=NULL){
        struct ListNode* new=(struct ListNode*)malloc(sizeof(struct ListNode));
        now= curr->val+curr2->val+up;
        if(now<10){
            new->val=now;
            up=0;
        }else{
            new->val=now-10;
            up=1;
        }
        new->next=NULL;
        currr->next=new;
        currr=currr->next;
        curr=curr->next;
        curr2=curr2->next;
    }
    if(curr==NULL){
        while(curr2!=NULL){
            struct ListNode* new=(struct ListNode*)malloc(sizeof(struct ListNode));    
            now= curr2->val+up;
            if(now<10){
                new->val=now;
                up=0;
            }else{
                new->val=now-10;
                up=1;
            }
            new->next=NULL;
            currr->next=new;
            currr=currr->next;
            curr2=curr2->next;
        }
    }else{
        while(curr!=NULL){
            struct ListNode* new=(struct ListNode*)malloc(sizeof(struct ListNode));
            now= curr->val+up;
            if(now<10){
                new->val=now;
                up=0;
            }else{
                new->val=now-10;
                up=1;
            }
            new->next=NULL;
            currr->next=new;
            curr=curr->next;
            currr=currr->next;
        }
    }
    if(up==1){
        struct ListNode* new=(struct ListNode*)malloc(sizeof(struct ListNode));
        new->val=1;
        new->next=NULL;
        currr->next=new;
    }
    return head->next;
}