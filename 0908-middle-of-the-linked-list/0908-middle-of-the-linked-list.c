/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
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