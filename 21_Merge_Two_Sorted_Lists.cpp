#include <iostream>


using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if (list1 == nullptr && list2 == nullptr)
        {
            return nullptr;
        }

        ListNode* a = list1;
        ListNode* b = list2;

        ListNode* head = new ListNode();
        ListNode** tail = &head;

        while (a != nullptr or b != nullptr) {
                        
            if (a != nullptr && (b == nullptr or a->val <= b->val)) {               
                (*tail)->val = a->val;
                a = a->next;
            }
            else if (b != nullptr && (a == nullptr or b->val < a->val)) {
                (*tail)->val = b->val;
                b = b->next;
            }

            if (a != nullptr or b != nullptr) {
                (*tail)->next = new ListNode;
                tail = &(*tail)->next;
            }

        }

        return head;
    }
};


ListNode* constructLinkedList(int array[], int size) {

    ListNode* prevNode = nullptr;

    for (int i = size - 1; i >= 0; i--)
    {
        if (prevNode == nullptr) {
            prevNode = new ListNode(array[i]);
        }
        else {
            prevNode = new ListNode(array[i], prevNode);
        }
    }

    return prevNode;
}


int main() {

    ListNode* list1 = constructLinkedList(new int[6] {1, 6, 8, 9, 11, 14}, 6);
    ListNode* list2 = constructLinkedList(new int[11] {1, 2, 3, 4, 7, 8, 8, 9, 12, 13, 15}, 11);

    ListNode* result_list = Solution().mergeTwoLists(list1, list2);

    while (result_list->next != nullptr) {
        cout << result_list->val << endl;
        result_list = result_list->next;
    }
    cout << result_list->val << endl;

    return 0;
}