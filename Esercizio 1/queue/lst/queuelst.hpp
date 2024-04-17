
#ifndef QUEUELST_HPP
#define QUEUELST_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class QueueLst : virtual public Queue<Data>,
        virtual protected List<Data> {

private:

    // ...

protected:

    // using List<Data>::???;

    // ...

public:

    // Default constructor
    inline QueueLst() = default;
    // QueueLst() specifier;

    /* ************************************************************************ */

    //specific constructors
    QueueLst(const TraversableContainer<Data> &con) : List<Data>(con) {};

    QueueLst(MappableContainer<Data> &&con) : List<Data>(std::move(con)) {};
    // QueueLst(argument) specifiers; // A stack obtained from a TraversableContainer
    // QueueLst(argument) specifiers; // A stack obtained from a MappableContainer

    /* ************************************************************************ */

    // Copy constructor
    // QueueLst(argument);
    inline QueueLst(const QueueLst &que) : List<Data>(que) {};


    // Move constructor
    // QueueLst(argument);
    inline QueueLst(QueueLst &&que) noexcept: List<Data>(std::move(que)) {};

    /* ************************************************************************ */

    // Destructor
    // ~QueueLst() specifier;
    virtual ~QueueLst() = default;

    /* ************************************************************************ */

    // Copy assignment
    // type operator=(argument)
    inline QueueLst &operator=(const QueueLst &);

    // Move assignment
    // type operator=(argument);
    inline QueueLst &operator=(QueueLst &&) noexcept;

    /* ************************************************************************ */

    // Comparison operators
    // type operator==(argument) specifiers;
    inline bool operator==(const QueueLst &) const noexcept;

    // type operator!=(argument) specifiers;
    inline bool operator!=(const QueueLst &) const noexcept;


    /* ************************************************************************ */

    // Specific member functions (inherited from Queue)
    inline const Data &Head() const override;

    // type Head() specifiers;
    //Override Queue member (non-mutable version; must throw std::length_error when empty)
    inline Data &Head() override;
    // type Head() specifiers;
    //Override Queue member (mutable version; must throw std::length_error when empty)

    inline void Dequeue() override;
    // type Dequeue() specifiers;
    // Override Queue member (must throw std::length_error when empty)

    inline Data HeadNDequeue() override;
    // type HeadNDequeue() specifiers;
    // Override Queue member (must throw std::length_error when empty)

    inline void Enqueue(const Data &) override;
    // type Enqueue(argument) specifiers;
    // Override Queue member (copy of the value)

    inline void Enqueue(Data &&) override;
    // type Enqueue(argument) specifiers;
    // Override Queue member (move of the value)

    /* ************************************************************************ */

    // Specific member function (inherited from ClearableContainer)

    // using List<Data>::Clear;
    using List<Data>::Clear;

/* ************************************************************************** */
    };
}

#include "queuelst.cpp"

#endif
