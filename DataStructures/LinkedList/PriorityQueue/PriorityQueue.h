#ifndef __PRIORITY_QUEUE_H__
#define __PRIORITY_QUEUE_H__

template <typename T> class PriorityQueue {
  public:
    virtual void push(T*) = 0;
    virtual T& pop() = 0;
    virtual T& peek() = 0;
};

#endif // !__PRIORITY_QUEUE_H__
