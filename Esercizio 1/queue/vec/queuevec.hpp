
#ifndef QUEUEVEC_HPP
#define QUEUEVEC_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class QueueVec : virtual public Queue<Data>,
    virtual protected Vector<Data>{

private:

  // ...

protected:
    unsigned long head = 0;
    unsigned long tail = 0;

    using Vector<Data>::size;

    using Vector<Data>::Elements;
  // using Vector<Data>::???;

  // ...

public:

  // Default constructor
  QueueVec():Vector<Data>(4) {};

  // QueueVec() specifier;

  /* ************************************************************************ */

  // Specific constructor
  // QueueVec(argument) specifiers; // A stack obtained from a TraversableContainer
  QueueVec(const TraversableContainer<Data> &);

  // QueueVec(argument) specifiers; // A stack obtained from a MappableContainer
  QueueVec(MappableContainer<Data> && con);
  /* ************************************************************************ */

  // Copy constructor
  // QueueVec(argument);
  QueueVec(const QueueVec & que): Vector<Data>(que), head(que.head) , tail(que.tail) {};

  // Move constructor
  // QueueVec(argument);
  QueueVec(QueueVec &&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~QueueVec() specifier;
  virtual ~QueueVec() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument);
  QueueVec & operator=(const QueueVec &);

  // Move assignment
  // type operator=(argument);
  QueueVec & operator=(QueueVec &&) noexcept;
  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  inline bool operator==(const QueueVec &) const noexcept;

  // type operator!=(argument) specifiers;
  inline bool operator!=(const QueueVec & ) const noexcept;
  /* ************************************************************************ */

  // Specific member functions (inherited from Queue)

  const Data & Head() const override;
  // type Head() specifiers; // Override Queue member (non-mutable version; must throw std::length_error when empty)

  Data & Head() override;
  // type Head() specifiers; // Override Queue member (mutable version; must throw std::length_error when empty)

  void Dequeue() override;
  // type Dequeue() specifiers; // Override Queue member (must throw std::length_error when empty)

  Data HeadNDequeue() override;
  // type HeadNDequeue() specifiers; // Override Queue member (must throw std::length_error when empty)

  void Enqueue(const Data &) override;
  // type Enqueue(argument) specifiers; // Override Queue member (copy of the value)

  void Enqueue(Data &) override;
  // type Enqueue(argument) specifiers; // Override Queue member (move of the value)

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  inline bool Empty() const noexcept override;
  // type Empty() specifiers; // Override Container member

  inline unsigned long Size() const noexcept override;
  // type Size() specifiers; // Override Container member

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear() specifiers; // Override ClearableContainer member
  void Clear() override;

protected:

    // Auxiliary functions, if necessary!
    void Expand();
    void Reduce();

    void Resize(unsigned long, unsigned long);

};

/* ************************************************************************** */

}

#include "queuevec.cpp"

#endif
