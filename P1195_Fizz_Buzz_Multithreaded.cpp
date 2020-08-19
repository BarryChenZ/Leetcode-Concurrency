class FizzBuzz {
private:
    int n;
    mutex m1;
    mutex m3;
    mutex m5;
    mutex m35;
public:
    FizzBuzz(int n) {
        this->n = n;
        m1.unlock();
        m3.lock();
        m5.lock();
        m35.lock();
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        for(int i = 3; i <= this->n; i += 3){
            m3.lock();
            printFizz(); 
            if((i + 3) % 5 == 0) i += 3;
            m1.unlock();
        }  
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        for(int i = 5; i <= this->n; i += 5){
            m5.lock();
            printBuzz(); 
            if((i + 5) % 3 == 0) i += 5;
            m1.unlock();
        }  
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        for(int i = 15; i <= this->n; i += 15){
            m35.lock();
            printFizzBuzz();
            m1.unlock();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        for(int i = 1; i <= this->n; i++){
            m1.lock();
            if(i % 15 == 0){
                m35.unlock();
            }
            else if(i % 5 == 0){
                m5.unlock();
            }
            else if(i % 3 == 0){
                m3.unlock();
            }
            else{
                printNumber(i);
                m1.unlock();
            }

        }
        
    }
};
