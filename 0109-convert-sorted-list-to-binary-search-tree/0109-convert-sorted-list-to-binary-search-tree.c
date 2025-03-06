#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 */
// struct ListNode {
//     int val;
//     struct ListNode *next;
// };

// /**
//  * Definition for a binary tree node.
//  */
// struct TreeNode {
//     int val;
//     struct TreeNode *left;
//     struct TreeNode *right;
// };

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

// 중위 순회 (BST 확인용)
void inorder(struct TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

// 리스트 생성 함수
struct ListNode* createList(int arr[], int n) {
    struct ListNode* head = NULL;
    struct ListNode* temp = NULL;
    for (int i = 0; i < n; i++) {
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = arr[i];
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }
    return head;
}

// // 테스트 코드
// int main() {
//     int arr[] = {-10, -3, 0, 5, 9};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     struct ListNode* head = createList(arr, n);

//     struct TreeNode* root = sortedListToBST(head);

//     printf("Inorder Traversal of BST: ");
//     inorder(root);
//     printf("\n");

//     return 0;
// }
