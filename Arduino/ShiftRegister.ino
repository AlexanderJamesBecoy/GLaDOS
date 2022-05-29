/*
 * Module to create five extra pins by administering the shift registers.
 * Developed by: Alexander James Becoy
 * Created on: 29-05-2022
 * Last modified on: 29-05-2022
 */

void ShiftRegister_Init(void)
{
  // Initialize the shift register.
  pinMode(SHIFTREG_LATCH_PIN, OUTPUT);
  pinMode(SHIFTREG_CLOCK_PIN, OUTPUT);
  pinMode(SHIFTREG_DATA_PIN, OUTPUT);
}

void ShiftRegister_Update(uint8_t data)
{
  // Update the shift register pins information in a byte, LSB first.
  digitalWrite(SHIFTREG_LATCH_PIN, LOW);
  shiftOut(SHIFTREG_DATA_PIN, SHIFTREG_CLOCK_PIN, LSBFIRST, data);
  digitalWrite(SHIFTREG_LATCH_PIN, HIGH);
}
