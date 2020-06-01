#include <iostream>
using std::cout;

class ListException {
    const char* msg;

    void copy(const ListException &le) {
        if (msg!=nullptr) delete msg;
        msg = le.msg;
    }
public:
    ListException(const char* mess) throw() {msg = mess;}

    ListException(const ListException &le) throw() {
        msg = le.msg;
    }

    ~ListException() throw() {
        delete msg;
    }

    ListException& operator=(const ListException &le) {
        if (this!=&le) copy(le);
        return (*this);
    }

    const char* what() const {
        return msg;
    }
};
