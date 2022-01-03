#ifndef _LIST_OF_POINT_HPP
#define _LIST_OF_POINT_HPP

#include <vector>
#include <iostream>
#include <cmath>
#include <stdbool.h>
#include <iterator>
#include <list>



#include "point.hpp"


//3) listofpoints.hpp-----------------------------------------------------
// the class stores an ordered list of points
// used to store the input to the problem
// may be also used to store a partial solution to the TSP problem

class ListOfPoints //LinkedList probably
{
  public:
    list <Point> component; //Linked List of Points
    ListOfPoints();
    
    // adds a new point to the end of the list
    void addPoint(Point &newPt); 
    
    // prints the list of points
    void printList() const;
    
    // draws the points
    void draw() const;

    //float getLength() const;

};

#endif