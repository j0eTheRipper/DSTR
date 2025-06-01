#ifndef __SINGLELINKNODE_H_INCLUDED__
#define __SINGLELINKNODE_H_INCLUDED__

template <typename T> struct Node {
    T& value;
    Node* next;

    Node<T>(T& value);
    Node<T>();
};

#endif // !__SINGLELINKNODE_H_INCLUDED__
