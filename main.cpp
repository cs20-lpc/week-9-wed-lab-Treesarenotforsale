//test file for ArrayQueue class
#include "ArrayQueue.hpp"
#include <iostream>
using namespace std;
template <typename T>
void print_queue_status(const ArrayQueue<T>& q, const string& name) {
    cout << "\n--- Status of " << name << " ---" << endl;
    cout << "  Length: " << q.getLength() << endl;
    cout << "  Max Size: " << q.getMaxSize() << endl;
    cout << "  Is Empty: " << (q.isEmpty() ? "Yes" : "No") << endl;
    cout << "  Is Full: " << (q.isFull() ? "Yes" : "No") << endl;
    if (!q.isEmpty()) {
        cout << "  Front Element: " << q.front() << endl;
        cout << "  Back Element: " << q.back() << endl;
    }
    cout << "--------------------------------" << endl;
}

int main() {
    cout << "Testing ArrayQueue<int> Class" << endl;
    cout << "=============================" << endl;

    // 1. Test Default Constructor (max size 100 based on the code snippet)
    ArrayQueue<int> q1;
    cout << "\n## Test 1: Default Constructor and Basic Enqueue/Dequeue" << endl;
    print_queue_status(q1, "q1 (initial)");

    // Enqueue some elements
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    cout << "Enqueued 10, 20, 30." << endl;
    print_queue_status(q1, "q1 (after enqueue)");

    // Test front() and dequeue()
    cout << "Dequeueing: " << q1.front() << endl;
    q1.dequeue(); // 10 removed
    print_queue_status(q1, "q1 (after first dequeue)");

    // Test back()
    cout << "Current Back: " << q1.back() << " (Should be 30)" << endl;

    // 2. Test Constructor with Max Size
    const int SMALL_SIZE = 5;
    ArrayQueue<int> q2(SMALL_SIZE);
    cout << "\n## Test 2: Size-Specific Constructor and isFull()" << endl;
    print_queue_status(q2, "q2 (initial)");

    // Fill q2 to test isFull()
    for (int i = 1; i <= SMALL_SIZE; ++i) {
        q2.enqueue(i * 100);
    }
    cout << "Enqueued 5 elements (100, 200, 300, 400, 500)." << endl;
    print_queue_status(q2, "q2 (after filling)");
    
    // 3. Test Copy Constructor and clear()
    cout << "\n## Test 3: Copy Constructor and clear()" << endl;
    ArrayQueue<int> q3 = q2; // Copy constructor
    cout << "q3 created using copy constructor from q2." << endl;
    print_queue_status(q3, "q3 (copy of q2)");

    q3.clear();
    cout << "q3 after clear()." << endl;
    print_queue_status(q3, "q3 (after clear)");
    print_queue_status(q2, "q2 (original, should be unchanged)");


    // 4. Test Overloaded Assignment Operator
    cout << "\n## Test 4: Assignment Operator" << endl;
    ArrayQueue<int> q4; // Uses default size 100
    q4.enqueue(999);
    q4.enqueue(888);
    
    ArrayQueue<int> q5(2); // Smaller queue
    q5 = q4; // Assignment operator
    cout << "q5 assigned from q4 (smaller queue assigned to larger)." << endl;
    print_queue_status(q4, "q4 (original)");
    print_queue_status(q5, "q5 (assigned from q4)");

    // Cleanup
    q1.clear();
    q2.clear();
    q4.clear();
    q5.clear();

    cout << "\nAll tests complete. Check output against expected values." << endl;
    
    return 0;
}