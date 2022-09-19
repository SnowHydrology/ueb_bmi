#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

#include "ControlFile.hxx"
#include <bmi.hxx>


int main(int argc, char *argv[])
{

  if (argc != 2) {
    printf("Usage: run_bmiuebcxx CONTROL_FILE\n\n");
    printf("Run the uebcxx model through its BMI with a control file.\n");
    return bmi::BMI_SUCCESS;
  }

  ueb::ControlFile confile( argv[1] );

  std::cout << confile  << std::endl;

  return bmi::BMI_SUCCESS;
}
