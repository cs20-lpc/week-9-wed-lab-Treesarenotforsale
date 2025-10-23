//#include "ArrayQueue.hpp"
template <typename T>
ArrayQueue<T>::ArrayQueue(int i) {
    // TODO
    maxSize = i;
    buffer = new T[maxSize];
    frontIndex = 0;
    backIndex = -1;
    this->length = 0;
}

template <typename T>
ArrayQueue<T>::ArrayQueue(const ArrayQueue<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
ArrayQueue<T>& ArrayQueue<T>::operator=(const ArrayQueue<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
ArrayQueue<T>::~ArrayQueue() {
    clear();
}

template <typename T>
T ArrayQueue<T>::back() const {
    // TODO
    if (isEmpty()) {
        throw std::underflow_error("Queue is empty. Cannot access back element.");
    }
    return buffer[backIndex];
}

template <typename T>
void ArrayQueue<T>::clear() {
    // TODO
    delete[] buffer;
    buffer = new T[maxSize];
    frontIndex = 0;
    backIndex = -1;
    this->length = 0;
}

template <typename T>
void ArrayQueue<T>::copy(const ArrayQueue<T>& copyObj) {
    // TODO
    maxSize = copyObj.maxSize;
    buffer = new T[maxSize];
    frontIndex = copyObj.frontIndex;
    backIndex = copyObj.backIndex;
    this->length = copyObj.length;
    for (int i = 0; i < this->length; i++) {
        buffer[(frontIndex + i) % maxSize] = copyObj.buffer[(copyObj.frontIndex + i) % maxSize];
    }
}

template <typename T>
void ArrayQueue<T>::dequeue() {
    // TODO
    if (isEmpty()) {
        throw std::underflow_error("Queue is empty. Cannot dequeue.");
    }
    frontIndex = (frontIndex + 1) % maxSize;
    this->length--;
}

template <typename T>
void ArrayQueue<T>::enqueue(const T& elem) {
    // TODO
    if (isFull()) {
        throw std::overflow_error("Queue is full. Cannot enqueue.");
    }
    backIndex = (backIndex + 1) % maxSize;
    buffer[backIndex] = elem;
    this->length++;
}

template <typename T>
T ArrayQueue<T>::front() const {
    // TODO
    if (isEmpty()) {
        throw std::underflow_error("Queue is empty. Cannot access front element.");
    }
    return buffer[frontIndex];
}


template <typename T>
int ArrayQueue<T>::getLength() const {
    return this->length;
}

template <typename T>
int ArrayQueue<T>::getMaxSize() const {
    return maxSize;
}

template <typename T>
bool ArrayQueue<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
bool ArrayQueue<T>::isFull() const {
    return this->length == maxSize;
}
