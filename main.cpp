#include <iostream>
#include "PriorityStack.h"

int main()
{

    PriorityStack<int> st;


    std::cout << (st.IsEmpty() ? "Stack is empty!" : "Stack isn't empty.") << std::endl << std::endl;

    st.Push(1, 20);
    st.Push(2, 30);
    st.Push(2, 90);

    st.Push(3, 30);
    st.Push(4, 80);
    st.Push(5, 70);

    Print(st);

    std::cout << (st.IsEmpty() ? "Stack is empty!" : "Stack isn't empty.") << std::endl << std::endl;


    st.Pop();
    st.Pop();

    Print(st);

    std::cout << "Clear stack" << std::endl << std::endl;
    st.Clear();
    Print(st);

    return 0;
}
