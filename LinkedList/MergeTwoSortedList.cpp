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

ListNode* helper(ListNode* list1, ListNode* list2){
    if(list1 == nullptr){
        return list2;
    }
    if(list2 == nullptr){
        return list1;
    }

    ListNode* head = nullptr;
    if(list1->val < list2->val){
        head = list1;
        list1 = list1->next;
    }else{
        head = list2;
        list2 = list2->next;
    }
    ListNode* p = head;
    while(list1 != nullptr && list2 != nullptr){
        if(list1->val < list2->val){
            p->next = list1;
            list1 = list1->next;
        }else{
            p->next = list2;
            list2 = list2->next;
        }
        p = p->next;
    }
    if(list1 != nullptr){
        p->next = list1;
    }else{
        p->next = list2;
    }
    return head;
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

int main() {
    // list1: 1 -> 2 -> 4
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    // list2: 1 -> 3 -> 4
    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    cout << "List 1: ";
    printList(list1);

    cout << "List 2: ";
    printList(list2);

    ListNode* finalList = helper(list1, list2);

    cout << "Merged: ";
    printList(finalList);

    return 0;
}