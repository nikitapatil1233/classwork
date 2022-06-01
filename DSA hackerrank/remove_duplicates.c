SinglyLinkedListNode* removeDuplicates)( SinglyLinkedListNode  *llist)
{


  SinglyLinkedListNode   *ptr = llist,*temp=NULL,*tmp=NULL;

    while(ptr!=NULL && ptr->next!=NULL)
    {
        temp = ptr->next;
        ptr->next=NULL;

        while(temp!=NULL && ptr->data == temp->data)
        {
            tmp=temp;
            temp=temp->next;

            tmp->next=NULL;

        }
        ptr->next = temp;
        ptr = temp;
    }

    return llist;
}
