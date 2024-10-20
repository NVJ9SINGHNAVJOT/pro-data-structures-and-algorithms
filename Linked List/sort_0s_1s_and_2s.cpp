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

void sortZeroOneTwoByCount(Node *&head)
{
    // step1: find count of zeroes, ones and twos
    int zero = 0;
    int one = 0;
    int two = 0;

    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
            zero++;
        else if (temp->data == 1)
            one++;
        else if (temp->data == 2)
            two++;
        temp = temp->next;
    }

    // step2: fill 0, 1 and 2s in the original ll
    temp = head;
    // fill zeroes
    while (zero--)
    {
        temp->data = 0;
        temp = temp->next;
    }

    // fill ones
    while (one--)
    {
        temp->data = 1;
        temp = temp->next;
    }

    // fill 2s
    while (two--)
    {
        temp->data = 2;
        temp = temp->next;
    }
}

Node *sortZeroOneTwo(Node *&head)
{
    if (head == NULL)
    {
        cout << "LL is empty " << endl;
        return NULL;
    }
    if (head->next == NULL)
    {
        // sngle node in LL
        return head;
    }

    // create dummy nodes
    Node *zeroHead = new Node(-101);
    Node *zeroTail = zeroHead;

    Node *oneHead = new Node(-101);
    Node *oneTail = oneHead;

    Node *twoHead = new Node(-101);
    Node *twoTail = twoHead;

    // traverse the original LL
    Node *curr = head;
    while (curr != NULL)
    {

        if (curr->data == 0)
        {
            // take out the zero wali node
            Node *temp = curr;
            curr = curr->next;
            temp->next = NULL;

            // append the zero node in zeroHead LL
            zeroTail->next = temp;
            zeroTail = temp;
        }
        else if (curr->data == 1)
        {
            // take out the one wali node
            Node *temp = curr;
            curr = curr->next;
            temp->next = NULL;

            // append the zero node in zeroHead LL
            oneTail->next = temp;
            oneTail = temp;
        }
        else if (curr->data == 2)
        {
            // take out the zero wali node
            Node *temp = curr;
            curr = curr->next;
            temp->next = NULL;

            // append the zero node in zeroHead LL
            twoTail->next = temp;
            twoTail = temp;
        }
    }

    // ab yha pr, zero , one, two, teeno LL readyv h

    // join them
    // remove dummmy nodes

    // modify one wali list
    Node *temp = oneHead;
    oneHead = oneHead->next;
    temp->next = NULL;
    delete temp;

    // modify two wali list
    temp = twoHead;
    twoHead = twoHead->next;
    temp->next = NULL;
    delete temp;

    // join list
    if (oneHead != NULL)
    {
        // one wali list is non empty
        // zero wali list ko one wali list se attach krdia
        zeroTail->next = oneHead;

        if (twoHead != NULL)
            oneTail->next = twoHead;
    }
    else
    {
        // one wali list is empty
        if (twoHead != NULL)
            zeroTail->next = twoHead;
    }

    // remove zerohead dummy Node
    temp = zeroHead;
    zeroHead = zeroHead->next;
    temp->next = NULL;
    delete temp;

    // return head of the modified linked list
    return zeroHead;
}

int main()
{
    Node *head = new Node(2);
    Node *second = new Node(2);
    Node *third = new Node(2);
    Node *fourth = new Node(1);
    Node *fifth = new Node(1);
    Node *sixth = new Node(1);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;

    cout << "input LL: ";
    print(head);

    //   sortZeroOneTwo(head);
    //   print(head);

    cout << "printing the sorted list " << endl;
    Node *temp = NULL;
    head = sortZeroOneTwo(head);
    // cout << "Came out of sort function" << endl;
    print(head);

    return 0;
}