struct ListNode *reverse( struct ListNode *head ){
 struct ListNode *newhead=NULL, *tail=NULL,*p=head;

    while (p)
    {
        tail = p->next;//记录后驱
        p->next = newhead; //插到前面
        newhead = p;//更新
        p = tail;//下一个
    }
    return newhead;
}