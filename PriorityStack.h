#ifndef PRIORITYSTACK_H
#define PRIORITYSTACK_H

#include<iostream>

template <class T>
struct Node {

    T data;
    int priority;
    Node<T> *next;
};

template <class T>
class PriorityStack
{
public:
    PriorityStack() {
        top = nullptr;
        size = 0;
    }

    // добавить элемент в стэк
    void Push(int priority, T value) {

        Node<T> *new_node = new  Node<T>;
        new_node->data = value;
        new_node->priority = priority;

        if (top == nullptr || priority >= top->priority) {

            new_node->next = top;
            top = new_node;

        } else {

             Node<T> *temp_node = top;

             while(temp_node->next != nullptr && temp_node->next->priority > priority) {

                 temp_node = temp_node->next;
             }

             new_node->next = temp_node->next;
             temp_node->next = new_node;
             ++size;
        }
    }

    // взять элемент из стэка с максимальным приоритетом
    T Pop() {

        if (IsEmpty()) {
            std::cout << "Program Terminated\n";
            exit(EXIT_FAILURE);
        }

        Node<T> *new_node;

        T temp = top->data;
        new_node = top;
        top = top->next;
        size--;

        delete new_node;

        return temp;
    }

    // проверяет, пустой ли стэк
    bool IsEmpty() {
        return top == nullptr;
    }

    // очищает стэк
    void Clear() {

        while (!IsEmpty()) {
            Pop();
        }
    }

    // выводит стек
    friend void Print(const PriorityStack<int>& stack) {

         Node<T> *p;
         p = stack.top;

         if (p == nullptr) {

             std::cout << "Stack is empty!" << std::endl << std::endl;

         } else {

             std::cout << "Stack from top:" << std::endl;

             while (p != nullptr) {

                 std::cout << "Priority:"  << p->priority << " | " << "Value:" << p->data << std::endl;
                 p = p->next;
             }
         }
    }

private:
    Node<T> *top;
    int size;

};

#endif // PRIORITYSTACK_H
