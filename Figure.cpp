#include "Figure.h"

void Figure::realloc() {                                                          
    auto tmp = new Shape*[this->capacity](); // zero init                         
                                                                                  
    for (size_t i = 0; i < this->nShapes; i++) {                                  
        tmp[i] = this->ppShapes[i];                                               
    }                                                                             
                                                                                  
    delete[] this->ppShapes;                                                      
    this->ppShapes = tmp;                                                         
}                                                                                 
                                                                                  
void Figure::addShape(Shape* const s) {                                           
    if (this->nShapes >= this->capacity) {                                        
        this->capacity *= 2;                                                      
        realloc();                                                                
    }                                                                             
                                                                                  
    this->nShapes++;                                                                                                                                                                                                                          
    this->ppShapes[this->nShapes - 1] = s;                                        
}            

std::string Figure::getBoundingBox() const {
    double minX = this->ppShapes[0]->getXcoords();
    double minY =  this->ppShapes[0]->getYcoords();
    double maxX = minX;
    double maxY = minY;

    for (size_t i = 1; i < this->nShapes; i++) {
        auto x = this->ppShapes[i]->getXcoords();
        auto y = this->ppShapes[i]->getYcoords();

        if (x > maxX)
            maxX = x;
        if (x < minX)
            minX = x;
        if (y > maxY)
            maxY = y;
        if (y < minY)
            minY = y;
    }

    /* TODO: finish below */
    auto topLeft = minX + minY;
    auto bttmRight = maxX + maxY;

    std::string str = "Top left corner: " + std::to_string(topLeft)
        + "\nBottom right corner:  " + std::to_string(bttmRight);

    return str;

}

Shape** Figure::getClosest(Shape const &location, const int n) const {
    int* dist = new int[this->capacity];
    Shape** closestShapes = new Shape*[n];

    for (int i = 0; i < this->capacity; i++) {
        dist[i] = this->ppShapes[i]->getDistanceFrom(location);
    }

    sort(dist, this->capacity);

    for (int i = 0; i < n; i++) {
        closestShapes[i] = this->ppShapes[i];
    }
    
    delete[] dist;
    return closestShapes;
}

/*
 * Sort array ppShapes recursively.
 *
 * An array containing distances is kept and updated alongside ppShapes
 * throughout the sorting process.
 */
void sort(int* dist, const int cap) {
    if (cap == 1) return;

    for (int i = 0; i < (cap - 1); i++) {
        int nextElem = i + 1;
        if (dist[i] > dist[nextElem]) {
            std::swap(dist[i], dist[nextElem]);
            std::swap(this->ppShapes[i], this->ppShapes[nextElem]);
        }
    }
    sort(dist, (cap - 1));
}

Figure::~Figure() {
    delete[] this->ppShapes;
}
/* vim: set ts=4 sw=4 tw=79 ft=cpp et :*/
