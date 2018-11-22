#include <iostream>
#include <cstdlib>
#include "queue.h"

int MyQueue::count_of_queues = 0;

MyQueue::MyQueue(): size_of_queue(DEFAULT_SIZE_OF_QUEUE) {
    count_of_elements = 0;
    count_of_queues++;
}

MyQueue::MyQueue(int size): size_of_queue(size) {
    count_of_elements = 0;
    count_of_queues++;
}

MyQueue::~MyQueue() {
    count_of_queues--;
}

bool MyQueue::addElement(Member& elem) {
    if (count_of_elements >= size_of_queue)
        return false;
    note* new_element = new note;
    new_element->member = elem;
    new_element->behind = 0;
    if (count_of_elements == 0) {
        first_element = last_element = new_element;
        count_of_elements++;
        return true;
    }
    count_of_elements++;
    last_element->behind = new_element;
    last_element = new_element;
    return true;
}

bool MyQueue::removeElement() {
    if (count_of_elements <= 0)
        return false;
    note* temp = first_element;
    first_element = first_element->behind;
    delete temp;
    count_of_elements--;
    return true;
}

int MyQueue::countOfElements() {
    return count_of_elements;
}

//Member's methods
Member::Member() {}

Member::~Member() {}

void Member::setTime(int nt)
{
    arrived_time = nt;
    need_time = rand() % 3 + 1;
    std::cout << need_time << std::endl;
}

