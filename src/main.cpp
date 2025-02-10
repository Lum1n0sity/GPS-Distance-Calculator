#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <sstream>

const double R = 6371.0;

std::string getInputs(std::string inst) {
  if (inst != "c1" && inst != "c2") {
    std::cerr << "Invalid instruction: " << inst << std::endl;
    exit(1);
  }

  std::string input;

  std::string msg = (inst == "c1") ? "First coordinate: " : "Second coordinate: ";
  std::cout << msg;
  std::getline(std::cin, input);

  if (std::cin.fail()) {
    std::cerr << "Input failed!" << std::endl;
    exit(1);
  }

  return input;
}

double toRadiants(double degrees) {
  return degrees * M_PI / 180.0;
}

int main(int argc, char* argv[]) {
  std::cout << "Make sure your coordinates are valid before entering!" << std::endl;
  std::cout << "Sepparate longitute and latitude using a space." << std::endl;
  std::cout << "\n";

  std::string c1 = getInputs("c1");
  std::string c2 = getInputs("c2");

  std::stringstream ss1(c1);
  double c1LatD, c1LongD;
  ss1 >> c1LatD >> c1LongD;

  std::stringstream ss2(c2);
  double c2LatD, c2LongD;
  ss2 >> c2LatD >> c2LongD;

  double c1Lat = toRadiants(c1LatD);
  double c1Long = toRadiants(c1LongD);

  double c2Lat = toRadiants(c2LatD);
  double c2Long = toRadiants(c2LongD);

  double difLong = c1Long - c2Long;
  double difLat = c1Lat - c2Lat;

  double a = pow(sin(difLat / 2), 2) + cos(c1Lat) * cos(c2Lat) * pow(sin(difLong/2), 2);
  double c = 2 * atan2(sqrt(a), sqrt(1 - a));

  double d = R * c;

  std::cout << "The distance is: " << d << "km" << std::endl;

  return 0;
}
