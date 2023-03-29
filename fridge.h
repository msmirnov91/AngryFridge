class Fridge {
public:
  Fridge();

  void perform();

  bool doorIsOpen() const;
  bool isCompressorTurnedOn() const;
  int getTemperature();
};

