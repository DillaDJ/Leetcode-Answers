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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow_ptr = head;
        ListNode* fast_ptr = head;

        while (fast_ptr != nullptr && fast_ptr->next != nullptr) {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
        
        return slow_ptr;
    }
};


int main() {

    ListNode* list1 = constructLinkedList(new int[6] {1, 2, 3, 4, 5, 6}, 6);

    ListNode* result_list = Solution().middleNode(list1);

    while (result_list->next != nullptr) {
        cout << result_list->val << endl;
        result_list = result_list->next;
    }
    cout << result_list->val << endl;

    return 0;
}