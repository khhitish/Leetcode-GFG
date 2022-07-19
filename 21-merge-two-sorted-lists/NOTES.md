}
}
if(first!=nullptr)
{
last->next=first;
}
else
{
last->next=second;
}
return third;
}
*/
//recursive https://youtu.be/0QPpgAsd4IY
if(first->val < second->val)
{
first->next=mergeTwoLists(first->next,second);
return first;
}
else
{
second->next=mergeTwoLists(first,second->next);
return second;
}
}
};
```