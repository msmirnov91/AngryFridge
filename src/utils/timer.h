class Timer {
public:
    Timer(unsigned int intervalSeconds);
    bool ready();

private:
    unsigned long _lastReadyTime;
    const unsigned long _interval;
};

unsigned long millis();
