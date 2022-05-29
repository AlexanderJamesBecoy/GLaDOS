/*
 * Module for the serial communication between Arduino and PC/Raspberry Pi.
 * Developed by: Alexander James Becoy
 * Created on: 28-05-2022
 * Last modified on: 28-05-2022
 */

void Serial_Init(void)
{
  // Initialize the serial protocol.
  Serial.begin(9600);
  Serial.println("The program is ready!");
}
