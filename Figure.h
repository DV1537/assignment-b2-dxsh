#ifndef FIGURE_H
#define FIGURE_H
#include <string>
#include <iostream>
#include <algorithm>

class Figure {
 private:
     unsigned int capacity;
     unsigned int nShapes;
     Shape** ppShapes = new Shape*[capacity];

     void realloc();
     void sort(int* dist, const int cap);

 public:
     Figure() : capacity{10}, nShapes{0} {}
     ~Figure();
     void addShape(Shape* const s);
     std::string getBoundingBox() const;
     Shape** getClosest(Shape const &location, const int n) const;
};

#endif
/* vim: set ts=4 sw=4 tw=79 ft=cpp et :*/
