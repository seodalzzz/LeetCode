/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* first=head;
    struct ListNode* second=head;

    while(second!=NULL && second->next!=NULL){
        first=first->next;
        second=second->next->next;
    }
    return first;
}

struct TreeNode* insert(struct TreeNode* root, struct ListNode* curr){
    struct TreeNode* treecurr=root;
    struct TreeNode* treeprev=root;
    // printf("%d",treecurr->val);
    if(root==NULL){
        root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        root->val=curr->val;
        root->left=NULL;
        root->right=NULL;
        printf("%d",root->val);
        return root;
    }
    printf("%d",treecurr->val);    
    while(treecurr!=NULL){
        treeprev=treecurr;
        if(treecurr->val<curr->val){
            treecurr=treecurr->right;
        }else{
            treecurr=treecurr->left;
        }
    }
    if(treeprev->val<curr->val){
        treeprev->right=(struct TreeNode*)malloc(sizeof(struct TreeNode));
        treeprev->right->val=curr->val;
        treeprev->right->left=NULL;
        treeprev->right->right=NULL;
    }else{
        treeprev->left=(struct TreeNode*)malloc(sizeof(struct TreeNode));
        treeprev->left->val=curr->val;
        treeprev->left->left=NULL;
        treeprev->left->right=NULL;
    }
    return root;
}

struct ListNode* findlistprev(struct ListNode* head, struct ListNode* dst){
    struct ListNode* curr=head;
    if(head==NULL){
        return NULL;
    }
    if(head==dst){
        return NULL;
    }
    while(curr->next!=dst){
        curr=curr->next;
    }
    return curr;
}

struct TreeNode* _help(struct TreeNode* root, struct ListNode* start){
    if(start==NULL){
        return root;
    }
    if(start->next==NULL){
        return insert(root, start);
    }
    struct ListNode* mid=middleNode(start);
    root=insert(root,mid);
    struct ListNode* ls=start;
    if(ls==mid){
        ls=NULL;
    }
    struct ListNode* ll=findlistprev(start,mid);
    if(ll!=NULL){
        ll->next=NULL;
    }
    struct ListNode* rs=mid->next;
    root= _help(root, ls);
    root=_help(root, rs);
    return root;
}

struct TreeNode* sortedListToBST(struct ListNode* head) {
    //mid 찾기
    //tree넣기
    struct TreeNode* root=NULL;
    if(head==NULL){
        return NULL;
    }
    root=_help(root, head);
    return root;
    
}