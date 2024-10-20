#include <iostream>
using namespace std;

// algorithm:
// example:
// answer:
// explanation:
// tags:

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // TODO: Write a destrcutor to delete a node
    ~Node()
    {

        cout << "Node with value: " << this->data << " deleted" << endl;
    }
};

// I want to insert a node right at the head of Linked List
void insertAtHead(Node *&head, Node *&tail, int data)
{
    // check for Empty LL
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        // step1:
        Node *newNode = new Node(data);
        // step2:
        newNode->next = head;
        // step3:
        head = newNode;
    }
}

// I want to insert a node right at the end of LINKED LIST
void insertAtTail(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    // step1: creatae a node
    Node *newNode = new Node(data);
    // step2: connect woth tail ndoe
    tail->next = newNode;
    // step3: update tail;
    tail = newNode;
}

void print(Node *head)
{

    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int findLength(Node *&head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}

void insertAtPosition(int data, int position, Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    // step1: find the position: prev & curr;

    if (position == 0)
    {
        insertAtHead(head, tail, data);
        return;
    }

    int len = findLength(head);

    if (position >= len)
    {
        insertAtTail(head, tail, data);
        return;
    }
    // ste1:find prev and curr
    int i = 1;
    Node *prev = head;
    while (i < position)
    {
        prev = prev->next;
        i++;
    }
    Node *curr = prev->next;

    // step2;
    Node *newNode = new Node(data);

    // step3:
    newNode->next = curr;

    // step4:
    prev->next = newNode;
}

void deleteNode(int position, Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        cout << "Cannot delete, LL is empty";
        return;
    }

    // deleting first node
    if (position == 0)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }
    int len = findLength(head);

    // deleting last node
    if (position == len - 1)
    {
        // find prev
        int i = 1;
        Node *prev = head;
        while (i < position)
        {
            prev = prev->next;
            i++;
        }
        // step2:
        prev->next = NULL;
        // step3:
        Node *temp = tail;
        // step4:
        tail = prev;
        // step5:
        delete temp;
        return;
    }

    // deleting middle node

    // step  : find prev and curr
    int i = 1;
    Node *prev = head;
    while (i < position)
    {
        prev = prev->next;
        i++;
    }
    Node *curr = prev->next;

    // step2:
    prev->next = curr->next;
    // step3:
    curr->next = NULL;
    // step4:
    delete curr;
}

Node *mergeNodes(Node *head)
{
    // base case, if head null hua toh null return kr do.... empty Linked List...
    if (!head)
        return 0;
    Node *slow = head, *fast = head->next, *newLastNode = 0;

    int sum = 0;

    while (fast)
    {                        // jb tk fast null nhi ho jata tb tk traverse krna h...
        if (fast->data != 0) // hum check krenge khi fast ka data 0 toh nhi ho gya...tb tk sum krna ...0 milne pr sum nhi krna h...
            sum += fast->data;
        else
        {
            slow->data = sum;   // slow k value ko sum se replace kr do...
            newLastNode = slow; // slow ko store kr lo q ki sum aage bdne wala h...
            slow = slow->next;
            sum = 0; // sum 0 ho jaye ga phir se...
        }
        fast = fast->next;
    }

    Node *temp = newLastNode->next; // temp deallocation k liye bnaya gya...
    newLastNode->next = 0;
    // next node ko null kr do q ki fast null ho chuka h...
    while (temp)
    {                           // deallocation q ki memory leak ho rhi h...
        Node *nxt = temp->next; // temp ko aage bdhate rho q ki temp delete hone wla h...
        delete temp;
        temp = nxt; // temp ko update kr do...
    }

    return head;
}

int main()
{

    Node *head = NULL;
    Node *tail = NULL;
    insertAtTail(head, tail, 0);
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 0);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 0);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 0);

    print(head);
    cout << endl;
    // cout << "head: " << head -> data << endl;
    // cout << "tail: " << tail->data << endl;

    // insertAtPosition(101, 5, head, tail);
    // cout<< "Printing after insert at position call" << endl;
    // print(head);
    // cout << endl;
    // cout << "head: " << head -> data << endl;
    // cout << "tail: " << tail->data << endl;
    insertAtPosition(101, 4, head, tail);
    print(head);
    cout << endl;
    deleteNode(4, head, tail);
    cout << endl;
    print(head);
    cout << endl;

    head = mergeNodes(head);

    print(head);
    cout << endl;

    return 0;
}