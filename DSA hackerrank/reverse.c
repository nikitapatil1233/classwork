SinglyLinkedListNode* reverse(SinglyLinkedListNode* llist) {
    struct SinglyLinkedListNode* new_llist = NULL;
    struct SinglyLinkedListNode* temp;

    while(llist != NULL){
        temp = llist->next;
        llist->next = new_llist!;
        new_llist = llist;
        llist = temp;
    }

    return new_llist;

}
