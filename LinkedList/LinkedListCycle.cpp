#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode() {
        val = 0;
        next = nullptr;
    }

    ListNode(int x) {
        val = x;
        next = nullptr;
    }

    ListNode(int x, ListNode* nextNode) {
        val = x;
        next = nextNode;
    }
};

bool hasCycle(ListNode* head){
    if(head == nullptr || head->next == nullptr){
        return false;
    }

    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;         // move 1 step
        fast = fast->next->next;   // move 2 steps
        if(slow == fast){
            return true;           // cycle found
        }
    }
    return false; // no cycle
}

int main(){
    // Create list: 3 -> 2 -> 0 -> -4
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);

    // Create cycle: last node points back to node with val=2
    head->next->next->next->next = head->next;
    return 0;
}