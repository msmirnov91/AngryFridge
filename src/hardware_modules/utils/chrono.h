class Chronometer {
public:
    Chronometer();
	
	void reset();
    unsigned long secondsPassed() const;

private:
    unsigned long _startTime;
};
