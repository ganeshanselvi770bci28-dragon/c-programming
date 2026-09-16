void reorderList(struct ListNode* head) {
    if (!head || !head->next || !head->next->next) {
        return;
    }
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode *prev = NULL;
    struct ListNode *curr = slow->next;
    slow->next = NULL; 

    while (curr) {
        struct ListNode *next_temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next_temp;
    }
    struct ListNode *first = head;
    struct ListNode *second = prev; 
    while (second) {
        struct ListNode *temp1 = first->next;
        struct ListNode *temp2 = second->next;

        first->next = second;
        second->next = temp1;

        first = temp1;
        second = temp2;
    }
}
