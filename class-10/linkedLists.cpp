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
    int getMiddleViaSlowFastPointers() {
        if (head == NULL) {
            return -1;
        }


        Node* slow = head;
        Node* fast = head;

        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow->data;
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
    cout << ll->getMiddleViaSlowFastPointers() << endl;

    ll->insertAtEnd(11);
    ll->printList();

    cout << ll->getMiddleViaCountMethod() << endl;
    cout << ll->getMiddleViaSlowFastPointers() << endl;


    ll->clearTheList();
    ll->insertAtEnd(1);
    ll->insertAtEnd(2);
    ll->insertAtEnd(3);
    ll->insertAtEnd(2);
    ll->insertAtEnd(1);
    ll->printList();
    cout << ll->isPalindrome() << endl;

    ll->clearTheList();
    ll->insertAtEnd(1);
    ll->insertAtEnd(2);
    ll->insertAtEnd(3);
    ll->insertAtEnd(3);
    ll->insertAtEnd(2);
    ll->insertAtEnd(1);
    ll->printList();
    cout << ll->isPalindrome() << endl;

    ll->clearTheList();
    ll->insertAtEnd(1);
    ll->insertAtEnd(2);
    ll->insertAtEnd(3);
    ll->insertAtEnd(4);
    ll->insertAtEnd(2);
    ll->insertAtEnd(1);
    ll->printList();
    cout << ll->isPalindrome() << endl;
}