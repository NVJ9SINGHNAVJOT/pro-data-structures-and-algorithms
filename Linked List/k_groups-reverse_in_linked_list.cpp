
#include <iostream>
using namespace std;

// algorithm:
// question: k groups-reverse in linked list
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

Node *reverseKNodes(Node *&head, int k)
{
    if (head == NULL)
    {
        cout << "LL is empty" << endl;
        return head;
    }
    int len = findLength(head);
    if (k > len)
    {
        // cout << "Enter valid value for k " << endl;
        return head;
    }

    // it means number of nodes in LL is >= k
    // Step A: reverse first k nodes of LL
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = curr->next;
    int count = 0;

    while (count < k)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    // Step B: recursive call
    if (forward != NULL)
    {
        // we still have nodes left to reverse
        Node *recursionKaAns = reverseKNodes(forward, k);
        head->next = recursionKaAns;
    }

    // step C: return head of the modified LL
    return prev;
}

int main()
{

    Node *head = NULL;
    Node *tail = NULL;
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 50);
    insertAtTail(head, tail, 60);
    insertAtTail(head, tail, 90);
    insertAtTail(head, tail, 77);
    insertAtPosition(101, 4, head, tail);
    print(head);
    cout << endl;

    Node *newHead = reverseKNodes(head, 3);

    print(newHead);
    cout << endl;

    return 0;
}
