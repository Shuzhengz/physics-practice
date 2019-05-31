#include "profile.h"
#include <cmath>
#include <sstream>
#include <iostream>

double time;       //time total
double time_acc;   //time accelerating or decelerating
double time_const; //time at constance

double distance_while_acc;          //distance while accelerating or decelerating
double distance_traveled_after_acc;

double Vzero = 0;
double velocity_max = kMaxVelocity;
double velocity_goal;
double velocity_current;
double acceleration = kMaxAcceleration;

double position_beg;  //begginning position
double position_inp;  //goal position

const double Profile::GetTime() {

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
} //Profile:GetTime

const double Profile::GetSetpoint(){
  double t;                    //user inputed time
  std::string time;
  std::cout << "Velocity at: ";
  std::cin >> t;
  Vzero = current_.velocity;
  velocity_goal = goal_.velocity;

  position_beg = current_.position;
  position_inp = goal_.position;

  time_acc = std:abs(v_max-v_initial) / acceleration;
  distance_while_acc = 0.5 * std:abs(v_max + v_initial) * time_acc;

  distance_traveled_after_acc = position_inp - distance_while_acc - distance_while_acc;
  time_const = distance_after_acc / velocity_max;

  time = time_acc + time_const + time_acc;

  //check the velocity of the time on the graph

  if (t < time_acc) {
    velocity_current = Vzero + (velocity_max - Vzero) * (t) / time_acc;
  }
  else if (t >= time_acc && t <= (time_acc + time_const)) {
    velocity_current = velocity_max;
  }
  else if (t > (time_acc + time_const) && t <= time) {
    velocity_current = veocity_max + (velocity_goal - velocity_max) * (t - time_acc - time_const) / time_acc;
  }
  else {
    velocity_current = 0;
  }
  std::ostringstream strss;
  strs << velocity_current;
  std::string str = strss.str();
  std::cout << velocity_current << std::endl;
} //Profile::GetSetpoint