/*
 * File:   CS2300CP.c
 * Author: Gunnar
 *
 * Created on January 25, 2020, 3:14 PM
 */

#include <xc.h>
#include "I2C.h"
#include <stdint.h>

#define CS2300CP_ADDR    0b1001110

void CS2300CP_write(unsigned char reg, char data) {
    I2C_Master_Start();
    I2C_Master_Write(CS2300CP_ADDR << 1);            
    I2C_Master_Write(reg);
    I2C_Master_Write(data);   
    I2C_Master_Stop();    
}

void CS2300CP_init() {
    CS2300CP_write(0x17, 0b00001000);   //high accuracy 
    CS2300CP_write(0x03, 0b00000001);
    CS2300CP_write(0x05, 0b00000001);
    CS2300CP_write(0x016, 0b10010000);
    
    //RUD 512x2^20 = 536870912 = 0x2000 0000
    CS2300CP_write(0x06, 0x20);
    CS2300CP_write(0x07, 0x00);
    CS2300CP_write(0x08, 0x00);
    CS2300CP_write(0x09, 0x00);
    
    CS2300CP_write(0x02, 0b00000010);
}