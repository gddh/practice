#include "node.h"

struct ListNode*    ft_create_elem(int val)
{
    struct ListNode *tmp;

    tmp = (struct ListNode *)malloc(sizeof(struct ListNode));

    if (tmp)
    {
        tmp->val = val;
        tmp->next = NULL;
    }
    return tmp;
}

void        ft_push_back(struct ListNode **head, int val)
{
   struct ListNode *tmp;

   if (*head)
   {
       tmp = *head;
       while(tmp->next)
       {
           tmp = tmp->next;
       }
       tmp->next = ft_create_elem(val);
   }
   else
       *head = ft_create_elem(val);
   
}

void        print_lst(struct ListNode *lst)
{
    while (lst)
    {
        printf("%d --> ", lst->val);
        lst = lst->next;
    }
    printf("\n");
}

void        remove_next(struct ListNode **node)
{
    struct ListNode* tmp;

    if ((*node)->next)
    {
        tmp = (*node)->next;
        (*node)->next = (*node)->next->next;
        free(tmp);
    }
}

struct ListNode*    removeNthFromEnd(struct ListNode* head, int n)
{
    struct ListNode* lst;
    struct ListNode* prev;

    lst = head;
    while (n-- > 0)
        lst = lst->next;
    if (lst)
    {
        prev = head;
        while (lst->next)
        {
            lst = lst->next;
            prev = prev->next;
        }
        remove_next(&prev);    
        return head;
    }
    else
    {
        prev = head;
        head = head->next;
        free(prev);
        return head;
    }
}

int     main(int argc, char **argv)
{
    struct ListNode *lst;

    lst = NULL;
    ft_push_back(&lst, 1);
    ft_push_back(&lst, 2);
    ft_push_back(&lst, 3);
    ft_push_back(&lst, 4);
    ft_push_back(&lst, 5);
    print_lst(lst);
    lst = removeNthFromEnd(lst, 1);
    print_lst(lst);
}
