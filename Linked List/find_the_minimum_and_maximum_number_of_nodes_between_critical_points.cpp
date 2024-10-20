#include <iostream>
#include <vector>
#include <climits>
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

vector<int> nodesBetweenCriticalPoints(Node *head)
{
    vector<int> ans = {-1, -1};

    Node *prev = head;
    if (!prev)
        return ans;
    Node *curr = prev->next;
    if (!curr)
        return ans;
    Node *next = curr->next;
    if (!next)
        return ans;

    int first = -1;
    int last = -1;
    int mind = INT_MAX;
    int i = 1;

    while (next)
    {
        bool iscp = ((curr->data > prev->data && curr->data > next->data) || (curr->data < prev->data && curr->data < next->data)) ? true : false;
        if (iscp && first == -1)
        {
            first = i;
            last = i;
        }
        else if (iscp)
        {
            mind = min(mind, i - last);
            last = i;
        }
        i++;
        prev = curr;
        curr = next;
        next = next->next;
    }
    if (first == last)
    {
        return ans;
    }
    else
    {
        ans[0] = mind;
        ans[1] = last - first;
    }
    return ans;
}

int main()
{

    Node *head = NULL;
    Node *tail = NULL;
    insertAtTail(head, tail, 5);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 5);
    insertAtTail(head, tail, 1);

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

    vector<int> ans = nodesBetweenCriticalPoints(head);

    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}