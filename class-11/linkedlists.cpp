#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// TODO: Implement stack using linked list.
class Stack {

public:
    // Implement push/pop/top/size/empty operations

private:
    LinkedList* ll = new LinkedList();
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    // TC: O(1)
    void insertAtBeginning(int val) {
        if (head == NULL) {
            head = new Node(val);
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // TC: O(n)
    void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    // TC: O(n)
    void insertAtEnd(int val) {
        if (head == NULL) {
            insertAtBeginning(val);
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        Node* newNode = new Node(val);
        temp->next = newNode;
    }

    // TC: O(n)
    void insertAtPos(int val, int pos) {

        if (pos == 0) {
            insertAtBeginning(val);
            return;
        }

        Node* temp = head;

        int jumps = 0;
        while (jumps < pos - 1 && temp->next != NULL) {
            temp = temp->next;
            jumps++;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // TC: O(1)
    void deleteFromBeginning() {
        if (head == NULL) {
            return;
        }

        Node* toDelete = head;
        head = head->next;
        delete(toDelete);
    }

    // TC: O(n)
    void deleteFromEnd() {
        if (head == NULL) {
            return;
        }
        if (head->next == NULL) {
            deleteFromBeginning();
        }

        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }

        Node* toDelete = temp->next;
        temp->next = NULL;
        delete(toDelete);
    }

    // TC: O(n)
    void deleteFromPos(int pos) {
        if (head == NULL) {
            return;
        }
        if (head->next == NULL || pos == 0) {
            deleteFromBeginning();
        }

        Node* temp = head;

        int jumps = 0;
        while (jumps < pos - 1 && temp->next->next != NULL) {
            temp = temp->next;
            jumps++;
        }

        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete(toDelete);
    }

    // TC: O(n)
    void reverse() {

        Node* curr = head;
        Node* prev = NULL;
        Node* temp;

        while (curr != NULL) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        head = prev;
    }

    // TC: O(n)
    int getMiddleViaCountMethod() {
        if (head == NULL) {
            return -1;
        }

        int n = getCount();
        int hops = n/2;
        if (n % 2 == 0) {
            hops--;
        }

        Node* temp = head;
        while (hops--) {
            temp = temp->next;
        }

        return temp->data;
    }

    // TC: O(n)
    Node* getMiddleViaSlowFastPointers() {
        if (head == NULL) {
            return new Node(-1);
        }


        Node* slow = head;
        Node* fast = head;

        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    // TC: O(n), AS: O(n)
    bool isPalindrome() {
        bool result = true;
        isPalindromeUtil(head, head, result);
        return result;
    }

    void clearTheList() {
        while (head != NULL) {
            deleteFromBeginning();
        }
    }

    // TC: O(n)
    bool isPalindromeIterative() {
        if (head == NULL) {
            return true;
        }

        Node* mid = getMiddleViaSlowFastPointers();
        Node* head2 = mid->next;
        mid->next = NULL;

        LinkedList* ll2 = new LinkedList();
        ll2->head = head2;

        ll2->reverse();

        while(head != NULL && ll2->head != NULL) {
            if (head->data != ll2->head->data) {
                return false;
            }
            head = head->next;
            ll2->head = ll2->head->next;
        }

        return true;
    }

private:

    Node* isPalindromeUtil(Node* curr, Node* head, bool &result) {
        if (curr == NULL) {
            return head;
        }

        Node* toCompare = isPalindromeUtil(curr->next, head, result);
        if (toCompare->data != curr->data) {
            result = false;
        }

        return toCompare->next;
    }

    int getCount() {
        int n = 0;
        Node* temp = head;
        while (temp != NULL) {
            n++;
            temp = temp->next;
        }
        return n;
    }
};

bool detectCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }

    return false;
}

// TC: 
void detectAndRemoveLoop(Node* head) {
    if (head == NULL) {
        return;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            break;
        }
    }

    if (slow != fast) {
        return;
    }

    // Case for circular linked list with no non-looped part.
    if (slow == head) {
        while (slow->next != head) {
            slow = slow->next;
        }
        slow->next = NULL;
        return;
    }

    slow = head;
    while (slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }

    fast->next = NULL;
}


int main() { 

    LinkedList* ll = new LinkedList();
    ll->insertAtBeginning(3);
    ll->insertAtBeginning(2);
    ll->insertAtBeginning(1);
    ll->insertAtBeginning(0);
    ll->printList();

    ll->insertAtEnd(4);
    ll->insertAtEnd(5);
    ll->printList();

    ll->insertAtPos(7, 0);
    ll->insertAtPos(8, 3);
    ll->insertAtPos(9, 8);
    ll->insertAtPos(10, 10000);
    ll->printList();

    ll->deleteFromBeginning();
    ll->deleteFromBeginning();
    ll->printList();

    ll->reverse();
    ll->printList();

    cout << ll->getMiddleViaCountMethod() << endl;
    cout << ll->getMiddleViaSlowFastPointers()->data << endl;

    ll->insertAtEnd(11);
    ll->printList();

    cout << ll->getMiddleViaCountMethod() << endl;
    cout << ll->getMiddleViaSlowFastPointers()->data << endl;


    ll->clearTheList();
    ll->insertAtEnd(1);
    ll->insertAtEnd(2);
    ll->insertAtEnd(3);
    ll->insertAtEnd(2);
    ll->insertAtEnd(1);
    ll->printList();
    cout << ll->isPalindrome() << endl;
    cout << ll->isPalindromeIterative() << endl;

    ll->clearTheList();
    ll->insertAtEnd(1);
    ll->insertAtEnd(2);
    ll->insertAtEnd(3);
    ll->insertAtEnd(3);
    ll->insertAtEnd(2);
    ll->insertAtEnd(1);
    ll->printList();
    cout << ll->isPalindrome() << endl;
    cout << ll->isPalindromeIterative() << endl;

    ll->clearTheList();
    ll->insertAtEnd(1);
    ll->insertAtEnd(2);
    ll->insertAtEnd(3);
    ll->insertAtEnd(4);
    ll->insertAtEnd(2);
    ll->insertAtEnd(1);
    ll->printList();
    cout << ll->isPalindrome() << endl;
    cout << ll->isPalindromeIterative() << endl;

    
    // --------------------------------

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = head;

    detectAndRemoveLoop(head);

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;

    Node* head2 = new Node(1);
    head2->next = new Node(2);
    head2->next->next = new Node(3);
    head2->next->next->next = new Node(4);
    head2->next->next->next->next = new Node(5);
    head2->next->next->next->next->next = new Node(6);
    head2->next->next->next->next->next->next = new Node(7);
    head2->next->next->next->next->next->next->next = head2->next->next;

    detectAndRemoveLoop(head2);

    while (head2 != NULL) {
        cout << head2->data << " ";
        head2 = head2->next;
    }
    cout << endl;
}