#ifndef _POINT_HPP
#define _POINT_HPP

#include <iostream>
#include <cmath>
#include <stdbool.h>
#include <iterator>
#include <list>

using namespace std;


//1) point.hpp-------------------------------------------------------
// the class represents a point in 2D and its name
class Point
{
  private:
    int m_x; //attributes of Point
    int m_y;
    string m_name;

  public:
    Point() { //default constructor
      m_x = 0;
      m_y = 0; 
      m_name = "0";
    }
    
    Point(int x, int y, string name)
      : m_x(x), m_y(y), m_name(name) 
    {}

    int getX() const {return m_x;}
    void setX(int x) {m_x=x;}

    int getY() const {return m_y;}
    void setY(int y) {m_y=y;}

    string getName() const {return m_name;}

    float getDistance(const Point &other);  

    string toString() const;

    void printPoint() const;

    // used for printing Point using << operator. For example:
    // Point p(1,2,"A");
    // cout << p << endl;
    // used for printing Point using << operator
    friend ostream& operator<<(ostream &os, const Point &p);

};


#endif