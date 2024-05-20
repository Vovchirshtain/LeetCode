#include <stdio.h>
#include <algorithm>

// ============================================== Make Linked List ==============================================
/*
*                                                                                                     * * * * * *
*                                                                                                     * EXAMPLE *
*                                                                                                     * * * * * *
* struct Node
* {
* private:
*     int data;
*     Node *next;
* 
* public:
*     Node()
*     { data = 0; next = nullptr; }
* 
*     void Set_Data(int new_data)
*     { data = new_data; }
* 
*     void Set_Next_Node(Node *new_next_node)
*     { next = new_next_node; }
* 
*     int Get_Data()
*     { return data; }
* 
*     Node *Get_Next_Node()
*     { return next; }
* };
* // ---------------------------------------------------------------------------------------------------------------
* class Linked_List
* {
* private:
*     Node *head, *tail;
* 
* public:
*     Linked_List()
*     { head = nullptr; tail = nullptr; }
* 
*     void Add_Node(int new_data)
*     {
*         Node *temp = new Node;
*         temp->Set_Data(new_data);
*         temp->Set_Next_Node(nullptr);
* 
*         if (head)
*         {
*             tail->Set_Next_Node(temp);
*             tail = temp;
*         }
*         else
*         {
*             head = temp;
*             tail = temp;
*         }
*     }
* 
*     void Print_List()
*     {
*         if (head)
*         {
*             Node *temp = head;
*             printf("List: ");
*             while (temp)
*             {
*                 printf("%i ", temp->Get_Data() );
*                 temp =  temp->Get_Next_Node();
*             }
*             printf("\n");
*         }
*         else
*             printf("List is empty\n");
*     }
* 
*     int Get_Head_Data()
*     {
*         if (head)
*             return head->Get_Data();
*         else
*         {
*             printf("No head data\n");
*             return -1;
*         }
*     }
* 
*     int Get_Tail_Data()
*     {
*         if (tail)
*             return tail->Get_Data();
*         else
*         {
*             printf("No tail data\n");
*             return -1;
*         }
*     }
* 
*     unsigned int Get_List_Length()
*     {
*         unsigned int list_length = 0;
* 
*         if (head)
*         {
*             Node *temp = head;
* 
*             while (temp)
*             {
*                 temp = temp->Get_Next_Node();
*                 list_length++;
*             }
*             return list_length;
*         }
*         else return 0;
*     }
* };
*/
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
/*struct ListNode
* {
*     int val;
*     ListNode *next;
* 
*     ListNode() : val(0), next(nullptr) {}
*     ListNode(int x) : val(x), next(nullptr) {}
*     ListNode(int x, ListNode *next) : val(x), next(next) {}
* };
*/
// ---------------------------------------------------------------------------------------------------------------
struct ListNode
{
private:
    int val;
    ListNode *next;

public:
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

    void Set_Data(int new_data)
    { val = new_data; }

    void Set_Next(ListNode *new_next)
    { next = new_next; }

    int Get_Data()
    { return val; }

    ListNode *Get_Next()
    { return next; }

    void Print_ListNode()
    {
        ListNode *temp = this;
        printf("ListNode: ");
        while (temp)
        {
            printf("%i ", temp->Get_Data() );
            temp = temp->Get_Next();
        }
    }
};
// ---------------------------------------------------------------------------------------------------------------
class Solution 
{
public:
    static ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) 
    {
        if (!list1 || list2 && list1->Get_Data() > list2->Get_Data() ) 
            /*std::swap(list1, list2);*/
        {
            ListNode *tmp;
            tmp = list1;
            list1 = list2;
            list2 = tmp;
        }

        if (list1)
            list1->Set_Next(mergeTwoLists(list1->Get_Next(), list2) );

        return list1;
    }
};
// ---------------------------------------------------------------------------------------------------------------
int main()
{
    ListNode list_3(4);
    ListNode list_2(2, &list_3);
    ListNode list_1(1, &list_2);

    ListNode list_6(4);
    ListNode list_5(3, &list_6);
    ListNode list_4(1, &list_5);

    ListNode *merged_list = Solution::mergeTwoLists(&list_1, &list_4);
    merged_list->Print_ListNode();

    return 0;
}
