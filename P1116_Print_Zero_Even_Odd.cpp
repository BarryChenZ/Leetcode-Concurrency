#include <semaphore.h>;

class ZeroEvenOdd {
private:
    int n;
    sem_t zeroJob;
    sem_t oddJob;
    sem_t evenJob;
    
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        sem_init(&zeroJob, 0, 1);
        sem_init(&oddJob, 0, 0);
        sem_init(&evenJob, 0, 0);
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for(int i = 1; i <= this->n; i++){
            sem_wait(&zeroJob);
            printNumber(0);
            if(i % 2 == 0){
                sem_post(&evenJob);
            }
            else{
                sem_post(&oddJob);
            }
        }
        
        
        
    }

    void even(function<void(int)> printNumber) {
        for(int i = 2; i <= this->n; i += 2){
            sem_wait(&evenJob);
            printNumber(i);
            sem_post(&zeroJob);
        }
    }

    void odd(function<void(int)> printNumber) {
        for(int i = 1; i <= this->n; i += 2){
            sem_wait(&oddJob);
            printNumber(i);
            sem_post(&zeroJob);
        }
    }
};
