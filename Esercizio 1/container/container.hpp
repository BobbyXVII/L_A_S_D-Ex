
#ifndef CONTAINER_HPP
#define CONTAINER_HPP

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

class Container {

private:

protected:

    //Container attribute
    unsigned long size = 0;

    // Default constructor
    Container() = default;

public:

  // Destructor
  virtual ~Container() = default;

  /* ************************************************************************ */

    // Copy assignment
    Container &operator=(const Container &) noexcept = delete;

    // Move assignment
    Container &operator=(Container &&) noexcept = delete;

  /* ************************************************************************ */

    // Comparison operators
    bool operator==(const Container &) const noexcept = delete;

    bool operator!=(const Container &) const noexcept = delete;

  /* ************************************************************************ */

    // Specific member functions
    inline virtual bool Empty() const noexcept {
        return size == 0;
    }

    inline virtual unsigned long Size() const noexcept {
        return size;
    }


};

/* ************************************************************************** */

class ClearableContainer : virtual public Container{

private:

protected:

public:

  // Destructor
  virtual ~ClearableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  ClearableContainer &operator=(const ClearableContainer &) noexcept = delete;

  // Move assignment
  ClearableContainer &operator=(ClearableContainer &&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const ClearableContainer &OtherContainer) const noexcept = delete;

  bool operator!=(const ClearableContainer &OtherContainer) const noexcept = delete;
  /* ************************************************************************ */

  // Specific member functions
  virtual void Clear() = 0;

};

/* ************************************************************************** */

class ResizableContainer extends virtual public ClearableContainer{

private:

protected:

public:

  // Destructor
    virtual ~ResizableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  ResizableContainer &operator=(const ResizableContainer &OtherContainer) noexcept = delete

  // Move assignment
  ResizableContainer &operator=( ResizableContainer &&OtherContainer) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const ResizableContainer &OtherContainer) const noexcept = delete;

  bool operator!=(const ResizableContainer &OtherContainer) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions
  virtual void Resize(unsigned long) = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear() specifiers; // Override ClearableContainer member
  void Clear() override {Resize(0);}

};

/* ************************************************************************** */

}

#endif
