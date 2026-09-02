struct ListNode* insertionSortList(struct ListNode* head) {
    if (!head || !head->next) {
        return head;
    }

    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = NULL;
    
    struct ListNode* curr = head;

    while (curr) {
        struct ListNode* next_node = curr->next;
        struct ListNode* prev = &dummy;

        while (prev->next && prev->next->val < curr->val) {
            prev = prev->next;
        }

        curr->next = prev->next;
        prev->next = curr;

        curr = next_node;
    }

    return dummy.next;
}
