//*******************************************************************************
/*
* Copyright (C) 2019 MITUS Anzhelika Goncharova
*
* File              : main.c
* Version           : 8.32.3.20228
* Created File      : 09.06.2019
* Last modified     : 09.06.2019
*
* Support mail      : Lika_tsk@mail.com
*
* Target MCU        : MCU: Milandr MDR1986BE9x
* Description       : Work with bits: bit-banding, bit field and hadwork. 
*                   : 

********************************************************************************/

#define REG0_ADDR 0x20000000
#define REG0 *((volatile unsigned long *) (REG0_ADDR))

void set_bit(int bit_num) {
  *((volatile unsigned long *)(REG0_ADDR + 0x2000000 + bit_num*4)) = 1;
}

void reset_bit(int bit_num) {
  *((volatile unsigned long *)(REG0_ADDR + 0x2000000 + bit_num*4)) = 0;
}

struct bitField{
  char flag_a : 1; char flag_b : 1;
  char flag_c : 1; char flag_d : 1;
  char flag_e : 1; char flag_f : 1;
  char flag_g : 1; char flag_h : 1;
} _bitField;

static char bait = 0;

int main(void){
  // Work with Bit Field
  _bitField.flag_c = 1;
  _bitField.flag_c = 0;
  // Work with Bit Banding
  set_bit(2);
  reset_bit(2);
  // Handwork with bits
  
  bait |= (1<<2); // set 1 for 0th bit
  bait &=~(1<<2); // set 0 for 0th bit
  
  bait ^= (1<<2); // (Now, bit 0th = 0) inversion 
  bait ^= (1<<2); // (Now, bit 0th = 1) inversion
	return 0;	
}
