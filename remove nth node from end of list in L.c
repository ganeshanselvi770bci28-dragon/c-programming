struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = head;

    struct ListNode* first = &dummy;
    struct ListNode* second = &dummy;

    for (int i = 0; i <= n; i++) {
        first = first->next;
    }

    while (first != NULL) {
        first = first->next;
        second = second->next;
    }

    struct ListNode* node_to_delete = second->next;
    second->next = second->next->next;

    return dummy.next;
}
