//
// Created by joris on 20.08.19.
//

#pragma once
#include <vector>
#include "../utility/coordinates.h"
template <typename T>
class Grid2d {
private:
  int m_width;
  int m_height;
  std::vector<T> m_grid_matrix;
public:
  Grid2d(const int& width, const int& height);
  Grid2d(const int& width, const int& height, const T& init_val);
  T& operator[](const Coordinates& coords);
  T operator[](const Coordinates& coords) const;
  auto begin()
  {
      return m_grid_matrix.begin();
  }
  auto end()
  {
      return m_grid_matrix.end();
  }
  auto rbegin(){
      return m_grid_matrix.rbegin();
  }
  auto rend(){
      return m_grid_matrix.rend();
  }
  ~Grid2d(){
      if(std::is_pointer<T>::value) {
      for(T ptr : m_grid_matrix){
          delete ptr;
      }
      }
  }
};
template<typename T>
Grid2d<T>::Grid2d(const int &width, const int &height) : m_width(width), m_height(height), m_grid_matrix(width*height){}
template<typename T>
Grid2d<T>::Grid2d(const int &width, const int &height, const T& init_val) : m_width(width), m_height(height), m_grid_matrix(width*height){
    for(T& field : m_grid_matrix){
        field = init_val;
    }
}
template<typename T>
T& Grid2d<T>::operator[](const Coordinates &coords) {
  return m_grid_matrix[coords.x + coords.y * m_width];
}
template<typename T>
T Grid2d<T>::operator[](const Coordinates &coords) const {
  return m_grid_matrix[coords.x + coords.y * m_width];
}

