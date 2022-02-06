using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor frontLeftDrive;
extern motor frontRightDrive;
extern motor backLeftDrive;
extern motor backRightDrive;
extern digital_out Pneumatics;
extern motor clampGear;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );