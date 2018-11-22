class Member {
public:
    Member();
    ~Member();
    void setTime(int nt = 0);
    int getRemainingTime() { return arrived_time; };
    int getOperationTime() { return need_time; };
private:
    int need_time;
    int arrived_time;
};

typedef Member Member;

class MyQueue {
public:
    MyQueue();
    MyQueue(int);
    ~MyQueue();
    struct note {Member member; note* behind;};  // structure for elements of queue
    bool addElement(Member &);                   // add element to queue
    bool removeElement();                        // remove element from queue
    int countOfElements();                       // get the count of elements into the queue
    Member whoIsFirst() { return first_element->member; }; //return info about first
private:
    const static int DEFAULT_SIZE_OF_QUEUE = 10;
    static int count_of_queues;
    int count_of_elements;
    const int size_of_queue;
    note* last_element;
    note* first_element;
};
