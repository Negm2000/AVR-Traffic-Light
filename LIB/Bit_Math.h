#ifndef BITS_H_
#define BITS_H_

#define setPin(reg, pin) (reg) |= (1 << (pin)) // Set pin value to 1
#define clrPin(reg, pin) (reg) &= ~(1 << (pin))  // Set pin value to 0
#define togPin(reg, pin) (reg) ^= (1 << (pin))  // Toggle pin value
#define getPin(reg, pin) (reg >> (pin)) & 1  // Get pin value


#endif