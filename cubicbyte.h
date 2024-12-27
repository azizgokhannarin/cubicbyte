/******************************************************************************
 * File Name    : cubicbyte.h
 * Coder        : Aziz Gökhan NARİN
 * E-Mail       : azizgokhannarin@yahoo.com
 * Explanation  : Cubic expression of byte value
 * Versiyon     : 1.0.0
 ******************************************************************************/

#ifndef CUBICBYTE_H
#define CUBICBYTE_H

#include <cinttypes>

class CubicByte
{
public:
    explicit CubicByte();
    virtual ~CubicByte();

    void encode(const uint8_t &value, uint8_t &encoded, const bool &changed);
    void decode(uint8_t &value, const uint8_t &encoded, const bool &changed);

protected:
    void maskValue(const uint8_t &value, uint8_t &mask, uint8_t &R);
    void unmaskValue(uint8_t &value, const uint8_t &mask, const uint8_t &R);
    void findCoordinates(const uint8_t &value, uint8_t &X, uint8_t &Y, uint8_t &Z, uint8_t &R);
    void findValue(uint8_t &value, const uint8_t &X, const uint8_t &Y, const uint8_t &Z, const uint8_t &R);
};

#endif // CUBICBYTE_H
