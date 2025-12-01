/*
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
*/
#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;

    ListNode(){
        val = 0;
        next = nullptr;
    }

    ListNode(int x) {
        val = x;
        next = nullptr;
    }

    ListNode(int x, ListNode* nextNode){
        val = x; 
        next = nextNode;
    }
};

ListNode* reverseList(ListNode* head){
    ListNode* prev = nullptr;
    ListNode* nextNode = nullptr;
    while(head != nullptr){
        nextNode = head->next;
        head->next = prev;
        prev = head;
        head = nextNode;
    }
    return prev;
}

void printList(ListNode* head){
    while(head != nullptr){
        cout << head->val;
        if(head->next != nullptr){
            cout << "->";
        }
        head = head->next;
    }
    cout <<endl;
}

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    cout << "Original List: ";
    printList(head);
    head = reverseList(head);

    cout << "Reversed list: ";
    printList(head);
    return 0;
}