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
    struct ListNode* first = head;
    struct ListNode* second = head;

    while (second != NULL && second->next != NULL) {
        first = first->next;
        second = second->next->next;
    }
    return first;
}

struct ListNode* findlistprev(struct ListNode* head, struct ListNode* dst) {
    if (head == NULL || head == dst) {
        return NULL;
    }
    struct ListNode* curr = head;
    while (curr->next != dst) {
        curr = curr->next;
    }
    return curr;
}

void insert(struct TreeNode** root, struct ListNode* curr) {
    if (*root == NULL) {
        *root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        (*root)->val = curr->val;
        (*root)->left = NULL;
        (*root)->right = NULL;
        return;
    }

    if (curr->val < (*root)->val) {
        insert(&((*root)->left), curr);
    } else {
        insert(&((*root)->right), curr);
    }
}

void _help(struct TreeNode** root, struct ListNode* start) {
    if (start == NULL) {
        return;
    }
    if (start->next == NULL) {
        insert(root, start);
        return;
    }

    struct ListNode* mid = middleNode(start);
    insert(root, mid);

    struct ListNode* ll = findlistprev(start, mid);
    if (ll != NULL) {
        ll->next = NULL;
    }

    struct ListNode* ls = (start == mid) ? NULL : start;
    struct ListNode* rs = mid->next;

    _help(root, ls);
    _help(root, rs);
}

struct TreeNode* sortedListToBST(struct ListNode* head) {
    struct TreeNode* root = NULL;
    _help(&root, head);
    return root;
}
