
#ifndef    SevenSeg_h
#define    SevenSeg_h

#include "Print.h"

#define Cathode LOW
#define Anode   HIGH
#define Direct  LOW
#define Transistor HIGH

class SevenSeg : public Print
{
  public:
    SevenSeg(uint8_t com, uint8_t drv ,uint8_t SegA, uint8_t SegB, uint8_t SegC, uint8_t SegD, uint8_t SegE, uint8_t SegF, uint8_t SegG, uint8_t SegP, uint8_t Dig1, uint8_t Dig2);
    SevenSeg(uint8_t com, uint8_t drv , uint8_t SegA, uint8_t SegB, uint8_t SegC, uint8_t SegD, uint8_t SegE, uint8_t SegF, uint8_t SegG, uint8_t SegP, uint8_t Dig1, uint8_t Dig2, uint8_t Dig3);
    SevenSeg(uint8_t com, uint8_t drv , uint8_t SegA, uint8_t SegB, uint8_t SegC, uint8_t SegD, uint8_t SegE, uint8_t SegF, uint8_t SegG, uint8_t SegP, uint8_t Dig1, uint8_t Dig2, uint8_t Dig3, uint8_t Dig4);
    SevenSeg(uint8_t com, uint8_t drv , uint8_t SegA, uint8_t SegB, uint8_t SegC, uint8_t SegD, uint8_t SegE, uint8_t SegF, uint8_t SegG, uint8_t SegP, uint8_t Dig1, uint8_t Dig2, uint8_t Dig3, uint8_t Dig4, uint8_t Dig5);
    SevenSeg(uint8_t com, uint8_t drv , uint8_t SegA, uint8_t SegB, uint8_t SegC, uint8_t SegD, uint8_t SegE, uint8_t SegF, uint8_t SegG, uint8_t SegP, uint8_t Dig1, uint8_t Dig2, uint8_t Dig3, uint8_t Dig4, uint8_t Dig5, uint8_t Dig6);
    SevenSeg(uint8_t com, uint8_t drv , uint8_t SegA, uint8_t SegB, uint8_t SegC, uint8_t SegD, uint8_t SegE, uint8_t SegF, uint8_t SegG, uint8_t SegP, uint8_t Dig1, uint8_t Dig2, uint8_t Dig3, uint8_t Dig4, uint8_t Dig5, uint8_t Dig6, uint8_t Dig7);
    SevenSeg(uint8_t com, uint8_t drv , uint8_t SegA, uint8_t SegB, uint8_t SegC, uint8_t SegD, uint8_t SegE, uint8_t SegF, uint8_t SegG, uint8_t SegP, uint8_t Dig1, uint8_t Dig2, uint8_t Dig3, uint8_t Dig4, uint8_t Dig5, uint8_t Dig6, uint8_t Dig7, uint8_t Dig8);
    void init(uint8_t com, uint8_t drv , uint8_t SegA, uint8_t SegB, uint8_t SegC, uint8_t SegD, uint8_t SegE, uint8_t SegF, uint8_t SegG, uint8_t SegP, uint8_t Dig1, uint8_t Dig2, uint8_t Dig3, uint8_t Dig4, uint8_t Dig5, uint8_t Dig6, uint8_t Dig7, uint8_t Dig8);
    void home();
    void clear();
    void setCursor(uint8_t);
    void cursor();
    void noCursor();
    void display();
    void noDisplay();
    void multiplex();
    virtual size_t write(uint8_t);
    using Print::write;
};
#endif

