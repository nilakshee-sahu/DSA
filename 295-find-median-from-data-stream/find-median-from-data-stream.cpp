class MedianFinder {
private:
    priority_queue<double> maxHeap; // left half (largest element at top)
    priority_queue<double, vector<double>, greater<double>> minHeap; // right half (smallest element at top)
    double median;

    int signum(int a, int b) {
        if (a == b) return 0;
        else if (a > b) return 1;
        else return -1;
    }

    void call_median(double element) {
        switch (signum(maxHeap.size(), minHeap.size())) {
            case 0: 
                if (element > median) {
                    minHeap.push(element);
                    median = minHeap.top();
                } else {
                    maxHeap.push(element);
                    median = maxHeap.top();
                }
                break;
                case 1:
                if (element > median) {
                    minHeap.push(element);    
                } else {
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                    maxHeap.push(element);
                }
                median = (maxHeap.top() + minHeap.top()) / 2.0;
                break;

            case -1:
                if (element > median) {
                    maxHeap.push(minHeap.top());
                    minHeap.pop();
                    minHeap.push(element);    
                } else {
                    maxHeap.push(element);
                }
                median = (maxHeap.top() + minHeap.top()) / 2.0;
                break;
        }
    }




public:
    MedianFinder() {
        median = 0;
    }
    
    void addNum(int num) {
        double element = (double)num;
        call_median(element);
    }
    
    double findMedian() {
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */