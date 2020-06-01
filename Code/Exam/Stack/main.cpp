#include <iostream>
#include <cstdio>
#include <cstring>
#include "stack.hpp"
#include "stackInt.hpp"
#include "stackTemplate.hpp"
using std::cout;

void testVoid()
{
    void *m_v = malloc(sizeof(double)*10);

    char* bytes = (char*)m_v;
    double tmp = 3.5;
    memcpy(bytes+8,&tmp,8);

    double tmp2;
    memcpy(&tmp2,bytes+8,8);
    cout << tmp2 << "\n";

    double* m_d = (double*)m_v;
    cout << m_d[1] << "\n";
}

void testStack()
{
    int a[] = {0,1,2,3,4,5};
    Stack st(4);

    st.push(&a[0]);
    st.push(&a[1]);
    cout << (*(int*)st.pop()) << "\n";
    st.push(&a[2]);
    cout << (*(int*)st.pop()) << "\n";
    st.push(&a[3]);
    st.push(&a[4]);
    cout << (*(int*)st.pop()) << "\n";
    cout << (*(int*)st.pop()) << "\n";
    cout << (*(int*)st.pop()) << "\n";

    int *x, *y, *z;
    //void *x, *y, *z;
    st << (&a[1]) << (&a[2]) << (&a[3]);
    st >> (void*&)x >> (void*&)y >> (void*&)z;
    cout << (*x) << " " << (*y) << " " << (*z) << "\n";
    cout << "Success\n";
}

void testStackInt()
{
    int a[] = {0,1,2,3,4,5};
    StackInt st2;
    for (int t=0;t<1;t++)
    {
        StackInt st;
        st.push(a[5]);
        st.push(a[1]);
        cout << st.pop() << "\n";
        st.push(a[2]);
        st.push(a[3]);
        st2 = st;
        cout << st.pop() << "\n";
        cout << st.pop() << "\n";
        cout << st.pop() << "\n";

        st << 10 << 15 << 20;
        st >> a[0] >> a[3] >> a[5];
        cout << a[0] << " " << a[3] << " " << a[5] << "\n";
    }

    cout << "ST2 = \n";
    while (!st2.empty()) cout << st2.pop() << "\n";
}

void testStackTemplate() {
    int a[] = {0,1,2,3,4,5};
    StackTemplate<int> st2;

    for (int t=0;t<1;t++) {
        StackTemplate<int> st;
        st.push(a[5]);
        st.push(a[1]);
        cout << st.pop() << "\n";
        st.push(a[2]);
        st.push(a[3]);
        st2 = st;
        cout << st.pop() << "\n";
        cout << st.pop() << "\n";
        cout << st.pop() << "\n";
    }

    cout << "ST2 = \n";
    cout << st2.pop() << "\n";
    cout << st2.pop() << "\n";
    cout << st2.pop() << "\n";
}

int main()
{
    testVoid();
   // testStack();
    testStackInt();
   // testStackTemplate();
}
