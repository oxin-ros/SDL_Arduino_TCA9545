//
//   SDL_Arduino_TCA9545 Library
//   SDL_Arduino_TCA9545.cpp Arduino code - runs in continuous mode
//   Version 1.1
//   SwitchDoc Labs   April 10, 2015
//

#include "SDL_Arduino_TCA9545.h"

/**************************************************************************/
/*!
    @brief  Sends a single command byte over I2C
*/
/**************************************************************************/
void SDL_Arduino_TCA9545::wireWriteRegister(uint8_t reg, uint8_t value)
{
    // Configure the I2C device for writing.
    // This acquires a lock for the I2C device.
    Wire.beginTransmission(TCA9545_i2caddr);
    // Write the 8-bit value.
    Wire.write(value);
    // Release the lock for the I2C device.
    Wire.endTransmission();
}

/**************************************************************************/
/*!
    @brief  Reads an 8 bit values over I2C
*/
/**************************************************************************/
void SDL_Arduino_TCA9545::wireReadRegister(uint8_t reg, uint8_t *value)
{
    Wire.requestFrom(TCA9545_i2caddr, (uint8_t)1);
    // Shift values to create properly formed integer
    *value = Wire.read();
}

/**************************************************************************/
/*!
    @brief  Instantiates a new SDL_Arduino_TCA9545 class
*/
/**************************************************************************/
SDL_Arduino_TCA9545::SDL_Arduino_TCA9545(uint8_t addr):
TCA9545_i2caddr(addr)
{}

void SDL_Arduino_TCA9545::TCA9545SetConfig(void)
{
    // Set the config register to disable any buses.
    constexpr uint8_t NO_BUS_ENABLED = 0;
    wireWriteRegister(TCA9545_REG_CONFIG, NO_BUS_ENABLED);
}

void SDL_Arduino_TCA9545::read_control_register(uint8_t *value)
{
    wireReadRegister(TCA9545_REG_CONFIG, value);
}

void SDL_Arduino_TCA9545::write_control_register(uint8_t value)
{
    wireWriteRegister(TCA9545_REG_CONFIG, value);
}
