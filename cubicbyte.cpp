/******************************************************************************
 * File Name    : cubicbyte.cpp
 * Coder        : Aziz Gökhan NARİN
 * E-Mail       : azizgokhannarin@yahoo.com
 * Explanation  : Cubic expression of byte value
 * Versiyon     : 1.0.0
 ******************************************************************************/

#include "cubicbyte.h"

#include <iostream>

CubicByte::CubicByte()
{

}

CubicByte::~CubicByte()
{

}

void CubicByte::encode(const uint8_t &value, uint8_t &encoded, const bool &changed)
{
    uint8_t X, Y, Z, R;

    findCoordinates(value, X, Y, Z, R);
    encoded &= 0x0000;

    if (changed) {
        encoded |= (Y & 0x03);
        encoded = (encoded << 2) | (X & 0x03);
    } else {
        encoded |= (X & 0x03);
        encoded = (encoded << 2) | (Y & 0x03);
    }

    encoded = (encoded << 2) | (Z & 0x03);
    encoded = (encoded << 2) | (R & 0x03);
}

void CubicByte::decode(uint8_t &value, const uint8_t &encoded, const bool &changed)
{
    uint8_t X   = changed ? (encoded & 0x30) >> 4 : (encoded & 0xC0) >> 6;
    uint8_t Y   = changed ? (encoded & 0xC0) >> 6 : (encoded & 0x30) >> 4;
    uint8_t Z   = (encoded & 0x0C) >> 2;
    uint8_t R   = (encoded & 0x03);

    findValue(value, X, Y, Z, R);
}

void CubicByte::maskValue(const uint8_t &value, uint8_t &mask, uint8_t &R)
{
    if (value < 64) {
        mask = value;
        R = 0;
    } else if (value >= 64 && value < 128) {
        mask = value - 64;
        R = 1;
    } else if (value >= 128 && value < 192) {
        mask = value - 128;
        R = 2;
    } else { // value >= 192
        mask = value - 192;
        R = 3;
    }
}

void CubicByte::unmaskValue(uint8_t &value, const uint8_t &mask, const uint8_t &R)
{
    if (mask > 63) {
        throw std::out_of_range(std::to_string(mask) + " is wrong to be a mask!");
    } else if (R > 3) {
        throw std::out_of_range(std::to_string(mask) + " is wrong to be a region!");
    } else {
        if (0 == R) {
            value = mask;
        } else if (1 == R) {
            value = mask + 64;
        } else if (2 == R) {
            value = mask + 128;
        } else { // 3 == region
            value = mask + 192;
        }
    }
}

void CubicByte::findCoordinates(const uint8_t &value, uint8_t &X, uint8_t &Y, uint8_t &Z, uint8_t &R)
{
    uint8_t mask = 0;
    maskValue(value, mask, R);

    X = mask % 4;
    Y = (mask / 4) % 4;
    Z = mask / 16;
}

void CubicByte::findValue(uint8_t &value, const uint8_t &X, const uint8_t &Y, const uint8_t &Z, const uint8_t &R)
{
    if ((X < 0) || (X > 3) || (Y < 0) || (Y > 3) || (Z < 0) || (Z > 3)) {
        throw std::out_of_range("Coordinates must be between 0 and 3.");
    } else {
        uint8_t mask = X + Y * 4 + Z * 16;
        unmaskValue(value, mask, R);
    }
}
