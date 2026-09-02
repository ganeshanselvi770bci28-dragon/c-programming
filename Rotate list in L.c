struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (!head || !head->next || k == 0) {
        return head;
    }

    struct ListNode* tail = head;
    int len = 1;
    
    while (tail->next) {
        tail = tail->next;
        len++;
    }

    k = k % len;
    if (k == 0) {
        return head;
    }

    tail->next = head;

    int steps_to_new_tail = len - k;
    struct ListNode* new_tail = head;
    for (int i = 1; i < steps_to_new_tail; i++) {
        new_tail = new_tail->next;
    }

    struct ListNode* new_head = new_tail->next;
    new_tail->next = NULL;

    return new_head;
}
