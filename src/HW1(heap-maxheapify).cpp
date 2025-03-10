#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;
    
    int parent(int i) { 
        return (i - 1) / 2; 
    }
    
    int leftChild(int i) { 
        return (2 * i + 1); 
    }
    
    int rightChild(int i) { 
        return (2 * i + 2); 
    }
    
    void maxHeapify(int i) {
        int left = leftChild(i);
        int right = rightChild(i);
        int largest = i;
        
        if (left < heap.size() && heap[left] > heap[largest])
            largest = left;
        
        if (right < heap.size() && heap[right] > heap[largest])
            largest = right;
        
        if (largest != i) {
            swap(heap[i], heap[largest]);
            maxHeapify(largest);
        }
    }
    
public:
    void insert(int key) {
        heap.push_back(key);
        
        int i = heap.size() - 1;
        while (i > 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }
    
    int getMax() {
        if (heap.empty())
            return -1;
        return heap[0];
    }
    
    int extractMax() {
        if (heap.empty())
            return -1;
        
        int max = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        
        maxHeapify(0);
        
        return max;
    }
    
    void buildMaxHeap(vector<int> arr) {
        heap = arr;
        for (int i = heap.size()/2 - 1; i >= 0; i--)
            maxHeapify(i);
    }
    
    void printHeap() {
        for (int i = 0; i < heap.size(); i++)
            cout << heap[i] << " ";
        cout << endl;
    }
};

int main() {
    MaxHeap mh;
    int n, num;
    
    cout << "Masukkan jumlah elemen: ";
    cin >> n;
    
    cout << "Masukkan elemen-elemen: ";
    for (int i = 0; i < n; i++) {
        cin >> num;
        mh.insert(num);
    }
    
    cout << "Max Heap: ";
    mh.printHeap();
    
    cout << "Elemen maksimum: " << mh.getMax() << endl;
    
    cout << "Ekstrak maksimum: " << mh.extractMax() << endl;
    cout << "Heap setelah ekstraksi: ";
    mh.printHeap();
    
    vector<int> arr = {4, 10, 3, 5, 1};
    mh.buildMaxHeap(arr);
    cout << "Heap baru dari array: ";
    mh.printHeap();
    
    return 0;
}