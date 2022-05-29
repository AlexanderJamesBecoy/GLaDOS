// Pin definitions
#define MOTOR_RIGHT_PIN   5
#define MOTOR_LEFT_PIN    6
#define SERVO_TORSO_PIN   9
#define SERVO_HEAD_PITCH_PIN  10
#define SERVO_HEAD_YAW_PIN    11
#define SHIFTREG_LATCH_PIN  1
#define SHIFTREG_CLOCK_PIN  2
#define SHIFTREG_DATA_PIN   3

// Motor driver definitions
#define MOTOR_BRAKE       0b00
#define MOTOR_LEFT        0b01
#define MOTOR_RIGHT       0b10
#define MOTOR_BRAKE_BOTH  0b11

// PWM definitions
#define PWM_MAX_SAMPLE 255
#define PWM_MAX_COUNTER 2041 // if f_s = 8 MHz, f_pwm = 490 Hz.

// Servo definitions
#define SERVO_MAX_COUNTER 255
#define SERVO_MIN 0
#define SERVO_MAX 180
