#include <iostream>
using namespace std;

class Heap
{
public:
    int arr[101];
    int size;

    Heap()
    {
        size = 0;
    }

    void insertIntoHeap(int value)
    {
        /// value insert karo end me
        size = size + 1;
        int index = size;
        arr[index] = value;

        // iss value ko place at correct position position
        while (index > 1)
        {
            int parentIndex = index / 2;
            if (arr[index] > arr[parentIndex])
            {
                swap(arr[index], arr[parentIndex]);
                index = parentIndex;
            }
            else
            {
                break;
            }
        }
    }

    int deleteFromHeap()
    {

        int ans = arr[1];
        // replace root node value with last node data
        arr[1] = arr[size];
        size--;

        // place root node ka data on its correct position
        int index = 1;
        while (index < size)
        {
            int left = 2 * index;
            int right = 2 * index + 1;

            int largest = index;

            if (left < size && arr[largest] < arr[left])
            {
                largest = left;
            }
            if (right < size && arr[largest] < arr[right])
            {
                largest = right;
            }

            if (largest == index)
            {
                // value is at correct position
                break;
            }
            else
            {
                swap(arr[index], arr[largest]);
                index = largest;
            }
        }
        return ans;
    }
};

int main()
{
    Heap h;
    h.insertIntoHeap(50);
    h.insertIntoHeap(30);
    h.insertIntoHeap(70);
    h.insertIntoHeap(40);
    h.insertIntoHeap(80);
    h.insertIntoHeap(100);

    cout << "printing the heap " << endl;
    for (int i = 0; i <= h.size; i++)
    {
        cout << h.arr[i] << " ";
    }
    cout << endl;

    cout << h.deleteFromHeap() << endl;
    cout << h.deleteFromHeap() << endl;
    cout << h.deleteFromHeap() << endl;

    return 0;
}