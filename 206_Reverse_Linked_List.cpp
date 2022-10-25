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


class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        if (head == nullptr) {
            return nullptr;
        }
        ListNode* head_ptr = head; // Traverses through original list

        ListNode* result_tail = new ListNode(head->val); // Unnecessary but idk how to get a ptr of inline instanced objects
        ListNode** prev = &result_tail;

        ListNode* result_head = result_tail;


        head_ptr = head_ptr->next;
        

        while (head_ptr != nullptr) {
            result_head = new ListNode(head_ptr->val, *prev);

            prev = &result_head;

            head_ptr = head_ptr->next;
        } 

        return result_head;
    }
};


int main() {

    ListNode* list1 = constructLinkedList(new int[5] {1, 2, 3, 4, 5}, 5);

    ListNode* result_list = Solution().reverseList(list1);

    while (result_list->next != nullptr) {
        cout << result_list->val << endl;
        result_list = result_list->next;
    }
    cout << result_list->val << endl;

    return 0;
}