SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
    SinglyLinkedListNode* newn=create_singly_linked_list_node(data);
    if(newn==NULL)
        return head;
    read(newn);
    if(head==NULL)
        return newn;
    else
    {
        SinglyLinkedListNode* cur=head;
        while(cur->next!=NULL)
            cur=cur->next;
        cur->next=newn;
        return head;
    }


}
