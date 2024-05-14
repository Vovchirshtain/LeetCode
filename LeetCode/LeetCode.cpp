#include <stdio.h>

// ============================================== Merge Two Sorted Lists ==========================================
/*
* You are given the heads of two sorted linked lists list1 and list2.
* 
* Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
* 
* Return the head of the merged linked list.
* 
* Example 1:
* Input: list1 = [1,2,4], list2 = [1,3,4]
* Output: [1,1,2,3,4,4]
* 
* Example 2:
* Input: list1 = [], list2 = []
* Output: []
* 
* Example 3:
* Input: list1 = [], list2 = [0]
* Output: [0]
*/
// ---------------------------------------------------------------------------------------------------------------
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode() : val(0), next(nullptr) {}
*     ListNode(int x) : val(x), next(nullptr) {}
*     ListNode(int x, ListNode *next) : val(x), next(next) {}
* };
*/

//class Solution {
//public:
//    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
//    {
//    }
//};
// ---------------------------------------------------------------------------------------------------------------
struct Node
{
    int data = 0;
    Node *next = NULL;
};
// ---------------------------------------------------------------------------------------------------------------
class Linked_List
{
private:
    Node *head, *tail;
    Node *tmp = new Node;

public:
    Linked_List()
    {
        head = NULL;
        tail = NULL;
    }

    void Add_Node(int n)
    {
        tmp->data = n;
        tmp->next = NULL;

        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }

    void Print_List()
    {
        Node *temp = head;

        if (temp == NULL)
        {
            printf("List is empty\n");
            return;
        }

        while (temp != NULL)
        {
            printf("%i\n", temp->data);
            temp = temp->next;
        }
    }

    int Getter_Head()
    {
        if (tmp->data)
            return this->head->data;
        else
        {
            printf("Getter_Head: No nodes\n");
            return 0;
        }
    }

    int Getter_Tail()
    {
        if (tmp->data)
            return this->tail->data;
        else
        {
            printf("Getter_Tail: No nodes\n");
            return 0;
        }
    }
};
// ---------------------------------------------------------------------------------------------------------------
int main()
{
    Linked_List LL_obj;
    //    LL_obj.Add_Node(1);
    //    LL_obj.Add_Node(2);
    //    LL_obj.Add_Node(3);
    //    LL_obj.Add_Node(4);
    LL_obj.Print_List();

    LL_obj.Getter_Head();
    LL_obj.Getter_Tail();

    return 0;
}

