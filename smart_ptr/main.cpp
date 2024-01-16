#include <iostream>
#include <memory>

struct Student {
    std::string _id;
    std::string _name;
};

class SmartPtr {
    Student* _data {nullptr};

    explicit SmartPtr(Student* data) : _data(data) {}
public:
    Student* get() { return _data; }
    static SmartPtr make_smartptr() {
        std::cout << "allocating new student" << std::endl;
        return SmartPtr(new Student());
    }
    SmartPtr(SmartPtr&& ptr) noexcept {
        _data = ptr._data;
        ptr._data = nullptr;
    }
    Student* operator->() noexcept { return _data; }
    bool operator==(Student* s) { return _data == s; }
    ~SmartPtr() {
        if (_data) std::cout << "deallocating student" << std::endl;
        delete _data;
    }
};

int main() {

    auto print = [](auto& desc, auto& s) {
        std::cout << desc << s->_name << " (" << s->_id << ") " << std::endl;
    };
    {
        // regular pointers
        auto s = new Student {"W111222", "john"};
        print("OLD PTR: ", s);

        delete s;
    }
    std::cout << "-----------" << std::endl;
    {
        // custom smart pointer
        auto sp1 = SmartPtr::make_smartptr();
        sp1->_id = "W222333";
        sp1->_name = "jane";
        print("ORIGINAL: ", sp1);

        // borrow a reference to the data
        auto student = sp1.get();
        print("REFERENCED: ", student);

        // give ownership to another variable
        auto sp2 = std::move(sp1);
        print("MOVED: ", sp2);

        // this should give an error since we moved the data!
        auto s = (sp1 == nullptr) ? "EMPTY" : sp1->_name + "( " + sp1->_id + ") ";
        std::cout << "ILLEGAL: " << s << std::endl;
    }
    std::cout << "-----------" << std::endl;
    {
        // STL version
        auto up1 = std::make_unique<Student>();
        up1->_id = "W333444";
        up1->_name = "jill";
        print("UNIQUE: ", up1);

        // reference the object
        auto student = up1.get();
        print("REFERENCED: ", student);

        // give ownership
        auto up2 = std::move(up1);
        print("MOVED: ", up2);

    }

    return 0;
}