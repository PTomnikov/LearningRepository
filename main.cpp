#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queue.h"

using namespace std;

unsigned int AVERAGE_TIME = 6;  // average arrival time of a new visitor

bool new_visit(int avg = AVERAGE_TIME);

int main() {
    // test case for queue (imitation of queue to ATM)
    srand(time(NULL));
    cout << "Enter queue size: ";
    int size_of_queue;
    cin >> size_of_queue;
    MyQueue my_first_queue(size_of_queue);
    cout << "How many cycles (1 cycle = 1 min): ";
    int cycles;
    cin >> cycles;
    cout << "How many visitors per hour: ";
    int per_hour;
    cin >> per_hour;
    int avg_visit_time = 60 / per_hour;
    int visitors = 0;
    int served = 0;
    int wait_time = 0;
    int not_served = 0;
    Member new_visitor;
    for (int i = 0; i < cycles; i++) {
        if (wait_time <= 0) {
            if (my_first_queue.countOfElements() > 0) {
                my_first_queue.removeElement();
                served++;
            }
        }
        if (new_visit(avg_visit_time)) {
            new_visitor.setTime(i);
            visitors++;
            if (my_first_queue.countOfElements() < size_of_queue)
                my_first_queue.addElement(new_visitor);
            else not_served++;
        }
        if (my_first_queue.countOfElements() != 0 && wait_time <= 0)
            wait_time = my_first_queue.whoIsFirst().getOperationTime();
        wait_time--;
    }
    cout << "Total count of visitors: " << visitors << endl;
    cout << "Served visitors: " << served << endl;
    cout << "Not served: " << not_served << endl;

    return 0;
}

bool new_visit(int avg) {
    return (rand() * avg / RAND_MAX < 1);
}
