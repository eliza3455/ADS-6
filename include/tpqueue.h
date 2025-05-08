#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <stdexcept>

template<typename T>
class TPQueue {
 private:
  struct Node {
    T data;
    Node* next;
    explicit Node(const T& d) : data(d), next(nullptr) {}
  };

  Node* head;

 public:
  TPQueue() : head(nullptr) {}
  ~TPQueue() { clear(); }

  TPQueue(const TPQueue&) = delete;
  TPQueue& operator=(const TPQueue&) = delete;

  void push(const T& val) {
    Node* node = new Node(val);
    if (!head || val.prior > head->data.prior) {
      node->next = head;
      head = node;
    } else {
      Node* cur = head;
      while (cur->next && cur->next->data.prior >= val.prior) {
        cur = cur->next;
      }
      node->next = cur->next;
      cur->next = node;
    }
  }

  T pop() {
    if (!head) {
      throw std::out_of_range("TPQueue::pop: empty queue");
    }
    Node* node = head;
    head = head->next;
    T val = node->data;
    delete node;
    return val;
  }

  bool empty() const { return head == nullptr; }
  void clear() {
    while (head) {
      Node* tmp = head;
      head = head->next;
      delete tmp;
    }
  }
};

struct SYM {
  char ch;  // cppcheck-suppress unusedStructMember
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
