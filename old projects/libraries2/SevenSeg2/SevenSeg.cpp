#include "Arduino.h"
#include "Print.h"
#include "SevenSeg.h"

static uint8_t common;
static uint8_t driver;
static uint8_t disp;
static uint8_t cursr;
static uint8_t disply[8];
static uint8_t digit;
static uint8_t nbdigit;
static uint8_t pos;
static uint8_t dot[8];
static uint8_t Seg[8];
static uint8_t Dig[8];


const PROGMEM uint8_t seven_seg_digit[41]= {B0111111,  // = 0     Bgfedcba
                                            B0000110,  // = 1       ___
                                            B1011011,  // = 2      | a |
                                            B1001111,  // = 3     f|___|b
                                            B1100110,  // = 4      | g |
                                            B1101101,  // = 5     e|___|c
                                            B1111101,  // = 6        d
                                            B0000111,  // = 7
                                            B1111111,  // = 8
                                            B1101111,  // = 9
                                            B1110111,  // = A
                                            B1111100,  // = b
                                            B0111001,  // = C
                                            B1011110,  // = d
                                            B1111001,  // = E
                                            B1110001,  // = F
                                            B0111101,  // = G
                                            B1110110,  // = H
                                            B0110000,  // = I
                                            B0011110,  // = J
                                            B1110101,  // = k
                                            B0111000,  // = L
                                            B0110111,  // = M
                                            B1010100,  // = n
                                            B1011100,  // = o
                                            B1110011,  // = P
                                            B1100111,  // = q
                                            B1010000,  // = r
                                            B1101101,  // = S
                                            B1111000,  // = t
                                            B0111110,  // = U
                                            B0011100,  // = v
                                            B0011100,  // = W
                                            B1110110,  // = x
                                            B1100110,  // = y
                                            B1011011,  // = z
                                            B0000000,  // = ' '
                                            B1100011,  // = °
                                            B1000000,  // = -
                                            B0001000,  // = _
                                            B1001000}; // = =


SevenSeg::SevenSeg(uint8_t com, uint8_t drv , uint8_t SegA, uint8_t SegB, uint8_t SegC, uint8_t SegD, uint8_t SegE, uint8_t SegF, uint8_t SegG, uint8_t SegP, uint8_t Dig1, uint8_t Dig2)
{    init(com,drv,SegA,SegB,SegC,SegD,SegE,SegF,SegG,SegP,Dig1,Dig2,255,255,255,255,255,255);}

SevenSeg::SevenSeg(uint8_t com, uint8_t drv , uint8_t SegA, uint8_t SegB, uint8_t SegC, uint8_t SegD, uint8_t SegE, uint8_t SegF, uint8_t SegG, uint8_t SegP, uint8_t Dig1, uint8_t Dig2, uint8_t Dig3)
{    init(com,drv,SegA,SegB,SegC,SegD,SegE,SegF,SegG,SegP,Dig1,Dig2,Dig3,255,255,255,255,255);}

SevenSeg::SevenSeg(uint8_t com, uint8_t drv , uint8_t SegA, uint8_t SegB, uint8_t SegC, uint8_t SegD, uint8_t SegE, uint8_t SegF, uint8_t SegG, uint8_t SegP, uint8_t Dig1, uint8_t Dig2, uint8_t Dig3, uint8_t Dig4)
{    init(com,drv,SegA,SegB,SegC,SegD,SegE,SegF,SegG,SegP,Dig1,Dig2,Dig3,Dig4,255,255,255,255);}

SevenSeg::SevenSeg(uint8_t com, uint8_t drv , uint8_t SegA, uint8_t SegB, uint8_t SegC, uint8_t SegD, uint8_t SegE, uint8_t SegF, uint8_t SegG, uint8_t SegP, uint8_t Dig1, uint8_t Dig2, uint8_t Dig3, uint8_t Dig4, uint8_t Dig5)
{    init(com,drv,SegA,SegB,SegC,SegD,SegE,SegF,SegG,SegP,Dig1,Dig2,Dig3,Dig4,Dig5,255,255,255);}

SevenSeg::SevenSeg(uint8_t com, uint8_t drv , uint8_t SegA, uint8_t SegB, uint8_t SegC, uint8_t SegD, uint8_t SegE, uint8_t SegF, uint8_t SegG, uint8_t SegP, uint8_t Dig1, uint8_t Dig2, uint8_t Dig3, uint8_t Dig4, uint8_t Dig5, uint8_t Dig6)
{    init(com,drv,SegA,SegB,SegC,SegD,SegE,SegF,SegG,SegP,Dig1,Dig2,Dig3,Dig4,Dig5,Dig6,255,255);}

SevenSeg::SevenSeg(uint8_t com, uint8_t drv , uint8_t SegA, uint8_t SegB, uint8_t SegC, uint8_t SegD, uint8_t SegE, uint8_t SegF, uint8_t SegG, uint8_t SegP, uint8_t Dig1, uint8_t Dig2, uint8_t Dig3, uint8_t Dig4, uint8_t Dig5, uint8_t Dig6, uint8_t Dig7)
{    init(com,drv,SegA,SegB,SegC,SegD,SegE,SegF,SegG,SegP,Dig1,Dig2,Dig3,Dig4,Dig5,Dig6,Dig7,255);}

SevenSeg::SevenSeg(uint8_t com, uint8_t drv , uint8_t SegA, uint8_t SegB, uint8_t SegC, uint8_t SegD, uint8_t SegE, uint8_t SegF, uint8_t SegG, uint8_t SegP, uint8_t Dig1, uint8_t Dig2, uint8_t Dig3, uint8_t Dig4, uint8_t Dig5, uint8_t Dig6, uint8_t Dig7, uint8_t Dig8)
{    init(com,drv,SegA,SegB,SegC,SegD,SegE,SegF,SegG,SegP,Dig1,Dig2,Dig3,Dig4,Dig5,Dig6,Dig7,Dig8);}

void SevenSeg::init(uint8_t com, uint8_t drv , uint8_t SegA, uint8_t SegB, uint8_t SegC, uint8_t SegD, uint8_t SegE, uint8_t SegF, uint8_t SegG, uint8_t SegP, uint8_t Dig1, uint8_t Dig2, uint8_t Dig3, uint8_t Dig4, uint8_t Dig5, uint8_t Dig6, uint8_t Dig7, uint8_t Dig8)
{
    common=com;
    driver=drv;
    Seg[0]=SegA;
    Seg[1]=SegB;
    Seg[2]=SegC;
    Seg[3]=SegD;
    Seg[4]=SegE;
    Seg[5]=SegF;
    Seg[6]=SegG;
    Seg[7]=SegP;
    nbdigit=8;
    Dig[0]=Dig1;
    Dig[1]=Dig2;
    if (Dig8!=255){Dig[7]=Dig8;} else {nbdigit=7;}
    if (Dig7!=255){Dig[6]=Dig7;} else {nbdigit=6;}
    if (Dig6!=255){Dig[5]=Dig6;} else {nbdigit=5;}
    if (Dig5!=255){Dig[4]=Dig5;} else {nbdigit=4;}
    if (Dig4!=255){Dig[3]=Dig4;} else {nbdigit=3;}
    if (Dig3!=255){Dig[2]=Dig3;} else {nbdigit=2;}
    for (int i=0; i<=7;i++) {pinMode(Seg[i],OUTPUT);}
    for (int i=0; i<nbdigit;i++) {
      pinMode(Dig[i],INPUT);
      if (driver) {digitalWrite(Dig[i],!common);} else {digitalWrite(Dig[i],common);}
	  }
    for (int i=0;i<nbdigit;i++){
      dot[i]= false;
      disply[i]=' ';
    }
    cursr=false;                                         //cursor off
    disp=true;                                           //dispaly on
    digit =0;
    pos=0;
}

void SevenSeg::clear()
{
    pos=0;
    for (int i=0;i<nbdigit;i++){
      dot[i]= false;
      disply[i]=' ';
    }
}

void SevenSeg::home()
{
    pos=0;
}

void SevenSeg::setCursor(uint8_t col)
{
    pos=col-1;
}

void SevenSeg::cursor()
{
    cursr=true;
}

void SevenSeg::noCursor()
{
    cursr=false;
}

void SevenSeg::display()
{
    disp=true;
}

void SevenSeg::noDisplay()
{
    disp=false;
}

void segwrite(char carac) {
    char index = 36;                                              // ' ' par defaut
    if (carac>=0 && carac <= 9) index = carac;                    // 0 à 9
    if (carac == '°') index = 37;
    if (carac == '-') index = 38;
    if (carac == '_') index = 39;
    if (carac == '=') index = 40;
    if (carac == ' ') index = 36;
    if (carac >= '0' && carac <='9') index = (carac - '0');       // '0' à '9'
    if (carac >= 'A' && carac <='Z') index = (carac - 55);        // 'A' à 'Z'
    if (carac >= 'a' && carac <='z') index = (carac - 87);        // 'a' à 'z'
    for (int i=0;i<=6;i++) {
        if (!bitRead(pgm_read_byte(&seven_seg_digit[index]),i)) {digitalWrite(Seg[i],common);}
        else {digitalWrite(Seg[i],!common);};
    }
}

inline size_t SevenSeg::write(uint8_t chr) {
     if ((chr==10) ||(chr==13)) {                     //CR ou LF
         pos=0;                                       //curseur au debut
         return 1;
     }
     if ((chr=='.') || (chr==',')) {                  //gestion du point decimal
         if ((pos>0) && (pos<=nbdigit))
         dot[pos-1]=true;
     }
     else {                                           //
         if (pos<nbdigit) {
             disply[pos]=chr;
             dot[pos]=false;
             pos++;
         }
         else {return 0;}
     }
     return 1;
}

void SevenSeg::multiplex()
{
    if (digit!=0) {pinMode(Dig[digit-1],INPUT);} else {pinMode(Dig[nbdigit-1],INPUT);}
    if (disp) {                                                   //si affichage valide
        if (cursr && (digit == pos) && ((millis()%1000)<500))   //affichage du curseur
             {segwrite ('_');            }
        else {segwrite (disply[digit]);}                        //ou du caractere
        if (dot[digit]) {digitalWrite(Seg[7],!common);}         //affichage du point
        else {digitalWrite(Seg[7],common);}
        }
    else {
        segwrite (' ');
        digitalWrite(Seg[7],common);
        }
    if (driver) {digitalWrite(Dig[digit],!common);} else {digitalWrite(Dig[digit],common);};
    pinMode (Dig[digit],OUTPUT);
    digit ++;
    if (digit == nbdigit) digit = 0;
  }
  
