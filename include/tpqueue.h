// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <stdexcept>

template<typename T>
class TPQueue {
 private:
  struct Node {
    T data;
    Node* next;
    explicit Node(const T& arg) : data(arg), next(nullptr) {}
  };

  Node* head;

 public:
  TPQueue() : head(nullptr) {}
  ~TPQueue() {
    while (head) {
      Node* tmp = head;
      head = head->next;
      delete tmp;
    }
  }
  TPQueue(const TPQueue&) = delete;
  TPQueue& operator=(const TPQueue&) = delete;

  void push(const T& arg) {
    Node* newNode = new Node(arg);
    if (!head || item.prior > head->data.prior) {
      newNode->next = head;
      head = newNode;
      return;
    }
    Node* cur = head;
    while (cur->next && cur->next->data.prior >= item.prior) {
      cur = cur->next;
    }
    newNode->next = cur->next;
    cur->next = newNode;
  }

  T pop() {
    if (!head) throw std::runtime_error("Unfortunatlly TPQueue is empty(pop)");
    Node* tmp = head;
    T returnArg = head->data;
    head = head->next;
    delete tmp;
    return returnArg;
  }

  const T& top() const {
    if (!head) throw std::runtime_error("Unfortunatlly TPQueue is empty(top)");
    return head->data;
  }

  bool empty() const {
    return head == nullptr;
  }
};

struct SYM {
  char ch;
  int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
