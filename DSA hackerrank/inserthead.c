SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* llist, int data) {

 SinglyLinkedListNode* newn=create_singly_linked_list_node(data);
    if(llist==NULL)
        return newn;
    newn->next=llist;
    llist=newn;
    return llist;
}
