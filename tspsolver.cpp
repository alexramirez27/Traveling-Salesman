#include "tspsolver.hpp"


//7) tspsolver.cpp-------------------------------------------------------


float TSPCycle::getLength(TSPCycle m_solution) const{

  float totalDistance = 0; //initialize totalDistance to 0

  //compute the distance between the last point and the first point
  totalDistance = totalDistance + (m_solution.component.begin())->getDistance(*(--m_solution.component.end()));
  
  //will loop through the list of the optimal path
  auto temp = m_solution.component.begin();
  for (temp = m_solution.component.begin(); temp != --m_solution.component.end(); temp++) {
    auto temp2 = temp;
    totalDistance = totalDistance + temp->getDistance(*(++temp2)); //accumulate the distances
  }

  return totalDistance; //returns the total distance of the optimal path

}


TSPSolver::TSPSolver(ListOfPoints &list) {
    m_list = list; //make m_list equal to the input list
}



TSPCycle& TSPSolver::getSolution() {

  Point first = m_list.component.front();
  m_solution.addPoint(first); //create a new list with optimal path
  m_list.component.pop_front(); //now we don't have the initial point
  Point second = m_list.component.front();
  m_solution.addPoint(second); //start off with the first two points

  //loop through the input list
  for (auto temp = ++m_list.component.begin(); temp!= m_list.component.end(); temp++) {
    //20*20 = 800. Therefore, max distance = sqrt(20^2 + 20^2 = 800)
    float smallestDistance = sqrt(800); //initialize to the maximum possible distance
    std::list<Point>::iterator min_sol_temp = m_solution.component.begin();

    //loop through the newly created list
    auto temp2 = m_solution.component.begin();
    for (temp2 = m_solution.component.begin(); temp2 != m_solution.component.end(); temp2++) {
      // compute the distance between temp and temp2
      float actualDistance = temp->getDistance(*temp2);
      //update smallestDistance and update the position of min_sol_temp
      if (actualDistance < smallestDistance) {
        smallestDistance = actualDistance;
        min_sol_temp = temp2;
      }
    }
    //use insert to put the point in the optimal spot
    m_solution.component.insert(++min_sol_temp, *temp);
  }

  return m_solution;
}