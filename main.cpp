#include <iostream>
#include <cstdlib>
#include <cmath>
#include <stdbool.h>
#include <iterator>
#include <list>

#include "point.hpp"
#include "listofpoints.hpp"
#include "tspsolver.hpp"
#include "tspcycle.hpp"

using namespace std;


//8) main.cpp------------------------------------------------------------
void testPoint() {
  Point origin(0,0,"ORIGIN");
  cout << "--print using printPoint():" << endl;
  origin.printPoint();
  cout << "--print using toString():" << endl;
  cout << origin.toString() << endl;
  cout << "--print using << operator:" << endl;
  cout << origin << endl;
  

  Point q(3,4,"Q");
  cout << "distance between ORIGIN and Q is " << q.getDistance(origin) << endl;


}


// gets a list of points and runs the solver on this list
// used in test1 and test2 below
void testSolver(ListOfPoints &input) {
  cout << "---run the solver---" << endl;
  TSPSolver solver(input);
  //solver.solve();
  TSPCycle solution = solver.getSolution();


  cout << "Solution found is: " << endl;
  solution.printList();
  cout << "the length of the solution is: " << solution.getLength(solution) << endl;
}

void test1() {
  Point p[4] = {Point(5,6,"C"),
                Point(2,6,"B"),
                Point(5,9,"D"),
                Point(2,2,"A")};

  cout << "Creating a list of points:" << endl;
  ListOfPoints inputTSP;
  for (int i=0;i<4;i++)
    inputTSP.addPoint(p[i]);
  
  cout << "Printing the list:" << endl;
  inputTSP.printList();  
  inputTSP.draw();  

  testSolver(inputTSP);
}


void test2() {
  ListOfPoints inputTSP;
  Point p(0,0,"A");
  cout << "Creating a list of points:" << endl;

  for (int i=0;i<10;i++) {
    p = Point(i,0,"P"+to_string(i));
    inputTSP.addPoint(p);
  }
  
  cout << "Printing the list:" << endl;
  inputTSP.printList();  
  inputTSP.draw();  

  testSolver(inputTSP);
}


void test3() {
  ListOfPoints inputTSP;
  Point p(0,0,"O");
  cout << "Creating a list of points:" << endl;

  for (int i=0;i<200;i++) {
    p = Point(rand() % 1000, rand() % 1000,"P"+to_string(i));
    inputTSP.addPoint(p);
  }
  
  testSolver(inputTSP);
}


void additional_test1() {
  Point p[4] = {Point(3,9,"G"),
                Point(9,5,"F"),
                Point(5,1,"H"),
                Point(4,7,"E")};

  cout << "Creating a list of points:" << endl;
  ListOfPoints inputTSP;
  for (int i=0;i<4;i++)
    inputTSP.addPoint(p[i]);
  
  cout << "Printing the list:" << endl;
  inputTSP.printList();  
  inputTSP.draw();  

  testSolver(inputTSP);
}

void additional_test2() {
  Point p[8] = {Point(5,6,"C"),
                Point(2,6,"B"),
                Point(5,9,"D"),
                Point(2,2,"A"),
                Point(3,9,"G"),
                Point(9,5,"F"),
                Point(5,1,"H"),
                Point(4,7,"E")};

  cout << "Creating a list of points:" << endl;
  ListOfPoints inputTSP;
  for (int i=0;i<8;i++)
    inputTSP.addPoint(p[i]);
  
  cout << "Printing the list:" << endl;
  inputTSP.printList();  
  inputTSP.draw();  

  testSolver(inputTSP);
}



int main() {

  cout << "**** Test point **" << endl;
  testPoint();
  cout << "**** End of test point **" << endl << endl;

  cout << "**** test1 **:" << endl;
  test1();
  cout << "**** end of test1 **:" << endl << endl;

// uncomment for more testing
  cout << "**** test2 **:" << endl;
  test2();
  cout << "**** end of test2 **:" << endl << endl;

 
  cout << "**** test3 **:" << endl;
  test3();
  cout << "**** end of test3 **:" << endl << endl;

  //Additional Tests:
  cout << "**** additional test 1 **:" << endl;
  additional_test1();
  cout << "**** end of test4 Made By Alex**:" << endl << endl;

  cout << "****additional test 2 **:" << endl;
  additional_test2();
  cout << "**** end of additional test 2 **:" << endl << endl;




  return 0;
}