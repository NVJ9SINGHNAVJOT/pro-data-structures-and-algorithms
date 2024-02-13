#include <iostream>
using namespace std;

// algorithm:
// question: intersection of two linked list
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

Node *getIntersectionNode(Node *headA, Node *headB)
{
    Node *a = headA;
    Node *b = headB;

    while (a->next && b->next)
    {
        if (a == b)
        {
            return a;
        }
        a = a->next;
        b = b->next;
    }

    // a and b pointer are at final positions
    // where either a or b is previous of null or both
    if (a->next == 0 && b->next == 0 && a != b)
    {
        return 0;
    }

    if (a->next == 0)
    {
        // b is larger or equal to a
        // we need to find out how much bigger it is
        int blen = 0;
        while (b->next)
        {
            blen++;
            b = b->next;
        }
        while (blen--)
        {
            headB = headB->next;
        }
    }
    else
    {
        // a is bigger than b and we need to find out how much
        int alen = 0;
        while (a->next)
        {
            alen++;
            a = a->next;
        }
        while (alen--)
        {
            headA = headA->next;
        }
    }

    // now headA and headB pointer are set for restart position
    while (headA != headB)
    {
        headA = headA->next;
        headB = headB->next;
    }

    return headA;
}

int main()
{
    Node *head1 = NULL;
    Node *head2 = NULL;

    head1 = new Node(1);
    Node *first = new Node(2);
    Node *second = new Node(3);
    Node *third = new Node(4);
    Node *fourth = new Node(5);

    head2 = new Node(1);
    Node *first2 = new Node(2);
    Node *second2 = new Node(3);

    head1->next = first;
    first->next = second;
    second->next = third;
    third->next = fourth;

    head2->next = first2;
    first2->next = second2;
    second2->next = second;

    print(head1);
    cout << endl;
    print(head2);
    cout << endl;

    cout << second2 << endl;
    cout << "yooo" << endl;

    Node *intersectionNode = getIntersectionNode(head1, head2);
    cout << "yooo1" << endl;
    cout << intersectionNode << endl;
    cout << intersectionNode->data << endl;
    return 0;
}