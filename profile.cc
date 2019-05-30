#include "profile.h"
#include <cmath>
#include <sstream>
#include <iostream>

const double Profile::GetTime() {
  double time;
  double time_acc; //time accelerating or deceleration
  double time_const; //time at constance

  double distance_while_acc;
  double distance_traveled_after_acc;

  double Vzero = 0;
  double velocity_max = kMaxVelocity;
  double acceleration = kMaxAcceleration;

  if (ignore_max_velocity == true){
    time = (Vzero + sqrt(sqrt(Vzero) +
     4 * 0.5 * acceleration * (1.0)))
     / acceleration;
  }
  else {
     time_acc = (velocity_max - Vzero) / acceleration;
     distance_while_acc = velocity_max * time_acc / 2;
     distance_traveled_after_acc = 0.0 - 2 * distance_while_acc;
     time_const = distance_while_acc / velocity_max;
     time = 2 * time_acc + time_const;
  }
  std::ostringstream strs;
  strs << time;
  std::string str = strs.str();
  std::cout << time << std::endl;

  return 0.0;
}

const double Profile::GetSetpoint(){
  double t;
  std::string time;
  std::cout << "Velocity at: ";
  std::cin >> t;
}