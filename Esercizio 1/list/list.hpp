
#ifndef LIST_HPP
#define LIST_HPP

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/linear.hpp"
#include "../container/dictionary.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class List : virtual public ClearableContainer,
             virtual public LinearContainer<Data>,
             virtual public DictionaryContainer<Data>{

private:

  // ...

protected:

  // using Container::???;

  struct Node {

      // Data
      // ...
      Data element;
      Node *ptrnext = nullptr;
      /* ********************************************************************** */

      // Specific constructors
      Node() = default;

      //costruttore con valore
      Node(const Data &value) : element(value) {}

      //costruttore con valore e puntatore al nodo succesivo
      Node(const Data &value, Node *ptrNextElement) : element(value), ptrnext(ptrNextElement) {}

    /* ********************************************************************** */

      // Copy constructor
      Node(const Node &);

      // Move constructor
      Node(Node &&)noexcept;

    /* ********************************************************************** */

      //Copy assignment
      Node& operator=(const Node &);

      //move assignment
      Node& operator=(Node &&)noexcept;

    /* ********************************************************************** */

    // Destructor
    virtual ~Node() = default;
    // ...

    /* ********************************************************************** */

    // Comparison operators
    inline bool operator==(const Node &) const noexcept;

    inline bool operator!=(const Node &) const noexcept;
    // ...

    /* ********************************************************************** */

    // Specific member functions

    // ...

  };

  Node* head = nullptr; // Puntatore al primo nodo della lista

public:

  // Default constructor
  // List() specifiers;
  List() = default;

  /* ************************************************************************ */

  // Specific constructor
  // List(argument) specifiers; // A list obtained from a TraversableContainer
  // List(argument) specifiers; // A list obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  // List(argument) specifiers;

  // Move constructor
  // List(argument) specifiers;

  /* ************************************************************************ */

  // Destructor
  // ~List() specifiers;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;

  // Move assignment
  // type operator=(argument) specifiers;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;

  /* ************************************************************************ */

  // Specific member functions

  // type InsertAtFront(argument) specifier; // Copy of the value
  // type InsertAtFront(argument) specifier; // Move of the value
  // type RemoveFromFront() specifier; // (must throw std::length_error when empty)
  // type FrontNRemove() specifier; // (must throw std::length_error when empty)

  // type InsertAtBack(argument) specifier; // Copy of the value
  // type InsertAtBack(argument) specifier; // Move of the value

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear() specifiers; // Override ClearableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  // type Insert(argument) specifier; // Copy of the value
  // type Insert(argument) specifier; // Move of the value
  // type Remove(argument) specifier;

  /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)

  // type operator[](argument) specifiers; // Override (NonMutable) LinearContainer member (must throw std::out_of_range when out of range)
  // type operator[](argument) specifiers; // Override (Mutable) LinearContainer member (must throw std::out_of_range when out of range)

  // type Front() specifiers; // Override (NonMutable) LinearContainer member (must throw std::length_error when empty)
  // type Front() specifiers; // Override (Mutable) LinearContainer member (must throw std::length_error when empty)

  // type Back() specifiers; // Override (NonMutable) LinearContainer member (must throw std::length_error when empty)
  // type Back() specifiers; // Override (Mutable) LinearContainer member (must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  // using typename TraversableContainer<Data>::TraverseFun;

  // type Traverse(arguments) specifiers; // Override TraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderTraversableContainer)

  // type PreOrderTraverse(arguments) specifiers; // Override PreOrderTraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderTraversableContainer)

  // type PostOrderTraverse(arguments) specifiers; // Override PostOrderTraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  // using typename MappableContainer<Data>::MapFun;

  // type Map(argument) specifiers; // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderMappableContainer)

  // type PreOrderMap(argument) specifiers; // Override PreOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderMappableContainer)

  // type PostOrderMap(argument) specifiers; // Override PostOrderMappableContainer member

protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

}

#include "list.cpp"

#endif
