#include "profile.h"
#include <iostream>

int main() {
  Profile::ProfilePoint current;
  Profile::ProfilePoint goal;
  {
    goal.position = 1.0;
    goal.velocity = 0.0;
  }
  Profile profile(current);
  profile.SetGoal(goal);

  std::string maxVignore;
  std::cout << "Ignore max velocity? ";
  std::cin >> maxVignore;
  if (maxVignore == "yes"){
    ignore_max_velocity = true;
  }
  else if (maxVignore == "no"){
    ignore_max_velocity = false;
  }
  std::cout << profile.GetTime() << std::endl;
}
