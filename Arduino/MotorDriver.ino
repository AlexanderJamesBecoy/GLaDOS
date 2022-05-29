/*
 * Module for the motor driver which consist of one H-drive for one DC motor.
 * Developed by: Alexander James Becoy
 * Created on: 28-05-2022
 * Last modified on: 28-05-2022
 */

uint8_t state;  // Determines the direction of the motor. Default: at brake.
uint8_t pwm;    // The PWM duty cycle which determines the speed of the motor. Ranges between 0 to 255.
uint16_t timestamp;  // The counter for the PWM duty cycle.

void MotorDriver_Start(void);
void MotorDriver_Stop(void);

void MotorDriver_Init(void)
{
  // Initialize the pin mode and state of the motor driver.
  pinMode(MOTOR_RIGHT_PIN, OUTPUT);
  pinMode(MOTOR_LEFT_PIN, OUTPUT);
  
  // Default values
  state = 0b00;
  pwm = 0;
  timestamp = PWM_MAX_COUNTER + 1;
}

void MotorDriver_Run(void)
{
  unsigned long counter = micros();
  unsigned int duty_width = timestamp + map(pwm, 0, PWM_MAX_SAMPLE, 0, PWM_MAX_COUNTER);

  // Set the motor on-duty when the PWM recycles.
  if (counter - timestamp >= PWM_MAX_COUNTER)
  {
    MotorDriver_Start();
    timestamp = micros();
    return;
  }

  // Shift the timestamp and PWM duty cycle when the counter overflows.
  if (timestamp > counter)
  {
    unsigned long timestamp_shift = pow(2,15) - timestamp;
    unsigned int new_duty_width = duty_width - timestamp_shift; // TODO
    duty_width = new_duty_width;
  }

  // Set the motor off-duty when the counter is beyond the duty width.
  if (counter - timestamp >= duty_width)
    MotorDriver_Stop();
}

void MotorDriver_Start(void)
{
  // Decode the next state for each pair of 2 transistors.
  int new_right_state = (int) ((state >> 1) & 0b1);
  int new_left_state = (int) (state & 0b1);

  // Write the next state.
  digitalWrite(MOTOR_RIGHT_PIN, new_right_state);
  digitalWrite(MOTOR_LEFT_PIN, new_left_state);
}

void MotorDriver_Stop(void)
{
  // Stop the motor.
  digitalWrite(MOTOR_RIGHT_PIN, LOW);
  digitalWrite(MOTOR_LEFT_PIN, LOW);
}

void MotorDriver_NextState(uint8_t next_state)
{
  // Determine the next state of the motor driver through certain code.
  // 00, 11 = brake; 10 = motor goes right; 01 = motor goes left;
  state = next_state;
}

void MotorDriver_NewPWM(uint8_t new_pwm)
{
  // Set the new PWM duty cycle.
  pwm = new_pwm;
}
