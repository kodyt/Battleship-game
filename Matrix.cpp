#include <cassert>
#include "Matrix.h"

// REQUIRES: mat points to a Matrix
//           0 < width && width <= MAX_MATRIX_WIDTH
//           0 < height && height <= MAX_MATRIX_HEIGHT
// MODIFIES: *mat
// EFFECTS:  Initializes *mat as a Matrix with the given width and height.
// NOTE:     Do NOT use new or delete here.
void Matrix_init(Matrix* mat, int width, int height) {
  mat -> height = height; //Can use either of these notations to initialize the data
  mat -> width = width; 
}

// REQUIRES: mat points to a valid Matrix
// MODIFIES: os
// EFFECTS:  First, prints the width and height for the Matrix to os:
//             WIDTH [space] HEIGHT [newline]
//           Then prints the rows of the Matrix to os with one row per line.
//           Each element is followed by a space and each row is followed
//           by a newline. This means there will be an "extra" space at
//           the end of each line.
void Matrix_print(const Matrix* mat, std::ostream& os) {
  int height = Matrix_height(mat);
  int width = Matrix_width(mat);
  for(int i = 0; i < height; i++){
    for(int j = 0; j < width; j++){
      os << (*mat).data[i * width + j] << " ";
    }
    os << "\n";
  }
}

// REQUIRES: mat points to an valid Matrix
// EFFECTS:  Returns the width of the Matrix.
int Matrix_width(const Matrix* mat) {
  return mat -> width;
}

// REQUIRES: mat points to a valid Matrix
// EFFECTS:  Returns the height of the Matrix.
int Matrix_height(const Matrix* mat) {
  return mat -> height;
}

// REQUIRES: mat points to a valid Matrix
//           ptr points to an element in the Matrix
// EFFECTS:  Returns the row of the element pointed to by ptr.
int Matrix_row(const Matrix* mat, const char* ptr) {
  const char* firstPtr = &(mat -> data[0]); 
  return (ptr-firstPtr)/Matrix_width(mat);
}

//LIKELY AN ERROR HERE

// REQUIRES: mat points to a valid Matrix
//           ptr point to an element in the Matrix
// EFFECTS:  Returns the column of the element pointed to by ptr.
int Matrix_column(const Matrix* mat, const char* ptr) {
  const char* firstPtr = &(mat -> data[0]); 
  return (ptr-firstPtr) % Matrix_width(mat);
}

//LIKELY AN ERROR HERE

// REQUIRES: mat points to a valid Matrix
//           0 <= row && row < Matrix_height(mat)
//           0 <= column && column < Matrix_width(mat)
//
// MODIFIES: (The returned pointer may be used to modify an
//            element in the Matrix.)
// EFFECTS:  Returns a pointer to the element in the Matrix
//           at the given row and column.
char* Matrix_at(Matrix* mat, int row, int column) {
  int index = row * Matrix_width(mat) + column;
  return &(mat->data[index]);
}


// REQUIRES: mat points to a valid Matrix
//           0 <= row && row < Matrix_height(mat)
//           0 <= column && column < Matrix_width(mat)
//
// EFFECTS:  Returns a pointer-to-const to the element in
//           the Matrix at the given row and column.
const char* Matrix_at(const Matrix* mat, int row, int column) {
  int index = row * mat -> width + column;
  return &(mat->data[index]);
}

// REQUIRES: mat points to a valid Matrix
// MODIFIES: *mat
// EFFECTS:  Sets each element of the Matrix to the given value.
void Matrix_fill(Matrix* mat, char value) {
  for(int i = 0; i < (mat->width)*(mat->height); i++){
    mat->data[i] = value;
  }
}

// REQUIRES: mat points to a valid Matrix
// MODIFIES: *mat
// EFFECTS:  Sets each element on the border of the Matrix to
//           the given value. These are all elements in the first/last
//           row or the first/last column.
void Matrix_fill_border(Matrix* mat, int value) {
  int height = Matrix_height(mat);
  int width = Matrix_width(mat);
  for(int i = 0; i < height; i++){
    *Matrix_at(mat, i, 0) = value;
    *Matrix_at(mat, i, width - 1) = value;
  }

  for(int j = 1; j < width-1; j++){
    *Matrix_at(mat, 0, j) = value;
    *Matrix_at(mat, mat->height-1, j) = value;
  }
}
