#include <iostream>
#include <queue>

using namespace std;

class MedianFinder {
public:
    priority_queue<int, vector<int>, less<int>> B;
    priority_queue<int, vector<int>, greater<int>> A;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (A.size() != B.size()) {
            A.push(num);
            B.push(A.top());
            A.pop();
        } else {
            B.push(num);
            A.push(B.top());
            B.pop();
        }
    }
    
    double findMedian() {
        return A.size() == B.size() ? (A.top() + B.top()) / 2.0 : A.top();
    }
};

int main() {
    MedianFinder m;
    m.addNum(1);
    cout << m.findMedian() << endl;
    m.addNum(2);
    cout << m.findMedian() << endl;
    m.addNum(3);
    cout << m.findMedian() << endl;
    m.addNum(4);
    cout << m.findMedian() << endl;
    m.addNum(5);
    cout << m.findMedian() << endl;
    return 0;
}
