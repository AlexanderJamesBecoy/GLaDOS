/*
 * Module to control the three servo motors.
 * Developed by: Alexander James Becoy
 * Created on: 28-05-2022
 * Last modified on: 29-05-2022
 */

#include <Servo.h>

// Create three servo objects to rotate the torso and the head.
Servo servo_torso;
Servo servo_head_pitch;
Servo servo_head_yaw;

uint8_t counter_torso;
uint8_t counter_head_pitch;
uint8_t counter_head_yaw;

void Servo_Init(void)
{
  // Initialize the servo objects to the corresponding pins.
  // Servo motors are powered by PWM signals, better to leave these to PWM-enabled pins.
  servo_torso.attach(SERVO_TORSO_PIN);
  servo_head_pitch.attach(SERVO_HEAD_PITCH_PIN);
  servo_head_pitch.attach(SERVO_HEAD_YAW_PIN);
}

void Servo_Run(void)
{
  
}

void Servo_Turn_Torso(void)
{
  
}

// Reset motors to zero function
