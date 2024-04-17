#include "queuevec.hpp"

namespace lasd {

/* ************************************************************************** */

//Specific constructor (QueueVec)
template <typename Data>
QueueVec<Data> :: QueueVec(const TraversableContainer<Data> & con) : Vector<Data>(con), tail(size) {
    Vector<Data> :: Resize(size*2);
}

template <typename Data>
QueueVec<Data> :: QueueVec(MappableContainer<Data> && con) : Vector<Data>(std::move(con)), tail(size) {
    Vector<Data> :: Resize(size*2);
}

/* ************************************************************************** */
//Move constructor
template <typename Data>
QueueVec<Data> :: QueueVec(QueueVec && que) noexcept : Vector<Data>(std::move(que)) {
    std::swap(head,que.head);
    std::swap(tail,que.tail);
}

//Copy assignment (QueueVec)
template <typename Data>
QueueVec<Data> & QueueVec<Data> :: operator=(const QueueVec<Data> & que) {
    Vector<Data>::operator=(que);
    head = que.head;
    tail = que.tail;
    return *this;
}

//Move assignment (QueueVec)
template <typename Data>
QueueVec<Data> & QueueVec<Data> :: operator=(QueueVec<Data> && que) noexcept {
    Vector<Data>::operator=(std::move(que));
    std::swap(head,que.head);
    std::swap(tail,que.tail);
    return *this;
}

//Comparison operators (QueueVec)
template<typename Data>
bool QueueVec<Data>::operator==(const QueueVec<Data> & que) const noexcept {
    if(Size()==que.Size()) {
        for(unsigned long i1 = head, i2 = que.head;i1 < tail; i1++ %= size, i2++ %= que.size) {
            if(Elements[i1] != que.Elements[i2]) {
                return false;
            }
        }
        return true;
    } else {
        return false;
    }
}

template<typename Data>
inline bool QueueVec<Data>::operator!=(const QueueVec<Data> & que) const noexcept {
    return !(*this == que);
}

//Specific member functions (QueueVec) (Inherited from Queue)
template<typename Data>
const Data & QueueVec<Data>::Head() const {
    if (head != tail) {
        return Elements[head];
    } else {
        throw std::length_error("Access to an empty queue");
    }
}

template<typename Data>
Data & QueueVec<Data>::Head() {
    if (head != tail) {
        return Elements[head];
    } else {
        throw std::length_error("Access to an empty queue");
    }
}

template<typename Data>
void QueueVec<Data>::Dequeue() {
    if(head != tail) {
        Reduce();
        head++ %= size;
    } else {
        throw std::length_error("Access to an empty queue");
    }
}

template<typename Data>
Data QueueVec<Data>::HeadNDequeue() {
    if(head != tail) {
        Reduce();
        Data dat(std::move(Elements[head]));
        head++ %= size;
        return std::move(dat);
    } else {
        throw std::length_error("Access to an empty queue");
    }
}



}