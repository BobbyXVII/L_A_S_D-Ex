
#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

/* ************************************************************************** */

#include "mappable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class DictionaryContainer : virtual public TestableContainer<Data>{

private:

protected:

public:

  // Destructor
  virtual ~DictionaryContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.
  DictionaryContainer() &operator=(const DictionaryContainer() &) noexcept = delete;

  // Move assignment
  DictionaryContainer() &operator=(DictionaryContainer() &&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  inline bool operator==(DictionaryContainer() &) const noexcept = delete;

  inline bool operator!=(DictionaryContainer() &) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  // Copy of the value
  virtual bool Insert(const Data &) = 0;

  // Move of the value
  virtual bool Insert(Data &&) = 0;

  // Remove of the value
  virtual bool Remove(const Data &) = 0;

  // True if all are inserted(copy)
  virtual bool InsertAll(const TraversableContainer<Data> &);

  // True if all are inserted(move)
  virtual bool InsertAll(MappableContainer<Data> &&);

  // True if all are removed
  virtual bool RemoveAll(const TraversableContainer<Data> &);

  // True if some is inserted(copy)
  virtual bool InsertSome(const TraversableContainer<Data> &);

  //True if some is inserted(move)
  virtual bool InsertSome(MappableContainer<Data> &&);

  //True if some is removed
  virtual bool RemoveSome(const TraversableContainer<Data> &);
};

/* ************************************************************************** */

}

#include "dictionary.cpp"

#endif
