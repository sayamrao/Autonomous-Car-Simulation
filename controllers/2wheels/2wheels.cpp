
#include <webots/Motor.hpp>
#include <webots/Robot.hpp>
#include <webots/GPS.hpp>


#define TIME_STEP 100
using namespace webots;

int main(int argc, char **argv) {
  Robot *robot = new Robot();

  

  
  GPS *gp;
  gp=robot->getGPS("global");
  gp-> enable(TIME_STEP);
  
 
  
  Motor *wheels[2];
  char wheels_names[2][8] = {"wheel3", "wheel4"};
  for (int i = 0; i < 2; i++) {
    wheels[i] = robot->getMotor(wheels_names[i]);
    wheels[i]->setPosition(INFINITY);
    wheels[i]->setVelocity(0.0);
  }
  
 
    
    double leftSpeed = 1.0;
    double rightSpeed =  -1.0;
    wheels[0]->setVelocity(leftSpeed);
    wheels[1]->setVelocity(rightSpeed);
    

    while (robot->step(TIME_STEP) != -1) {
    std::cout<<"X : "<<gp->getValues()[0]<<std::endl;
    std::cout<<"Y : "<<gp->getValues()[1]<<std::endl;
    std::cout<<"Z : "<<gp->getValues()[2]<<std::endl;
    std::cout<< std::endl;
  
  }
  delete robot;
  return 0;  // EXIT_SUCCESS
}
