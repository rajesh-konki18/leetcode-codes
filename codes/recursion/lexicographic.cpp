#include <iostream>
using namespace std;

void printData(int data[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << data[i];
    }
    cout << endl;
}

void printSubSets(int data[], int original[], int size, int nextIndex, int orgSize)
{
    printData(data, size);
    if (nextIndex == orgSize)
    {
        return;
    }
    for (int i = nextIndex; i < orgSize; i++)
    {
        data[size] = original[i];
        printSubSets(data, original, size + 1, i + 1, orgSize);
    }
}

int main()
{
    int data[] = {1, 2, 3, 4};
    int temp[] = {};
    printSubSets(temp, data, 0, 0, 4);
    return 0;
}