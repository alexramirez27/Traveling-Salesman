#ifndef _TSP_CYCLE_HPP
#define _TSP_CYCLE_HPP

#include <iostream>
#include <cmath>
#include <stdbool.h>
#include <iterator>
#include <list>

#include "listofpoints.hpp"

using namespace std;


//5) tspcycle.hpp---------------------------------------------------------
// the class stores a cycle that traverses all points in some order
// it is used to store the solution to the problem
// it is a subclass of ListOfPoints
class TSPCycle : public ListOfPoints {

  public:
    TSPCycle()     {
      cout << "default TSPCycle constructor" << endl;
    }
    
    // returns the length of the
    float getLength(TSPCycle m_solution) const;
    

};
#endif