class H2O {
private:
    mutex mH;
    mutex mO;
    int h_count;
public:
    H2O() {
        h_count = 0;
        mO.lock();
        mH.unlock();
    }

    void hydrogen(function<void()> releaseHydrogen) {
        mH.lock();
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        h_count ++;
        if(h_count == 2){
            h_count = 0;
            mO.unlock();
        }
        else{
            mH.unlock();
        }
    }

    void oxygen(function<void()> releaseOxygen) {
        mO.lock();
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        mH.unlock();
    }
};
