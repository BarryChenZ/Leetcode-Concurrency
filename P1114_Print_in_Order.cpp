class Foo {
private:
    mutex f1;
    mutex f2;
public:
    Foo() {
        f1.lock();
        f2.lock();
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        f1.unlock();
    }

    void second(function<void()> printSecond) {
        f1.lock();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        f1.unlock();
        f2.unlock();
    }

    void third(function<void()> printThird) {
        f2.lock();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        f2.unlock();
    }
};
