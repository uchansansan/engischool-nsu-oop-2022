#include "Matrix.h"

Matrix:: Matrix()
  : height(2), width(2)
{
  data = new float[height * width];
}

Matrix:: Matrix(const int &y, const int &x)
  : height(y), width(x)
{
  data = new float[height * width];
}

Matrix:: Matrix(const Matrix &x)
  : height(x.height), width(x.width), data(x.data)
{
}

Matrix Matrix::operator+(const int &x) const
{
  Matrix temp = *this;
  temp += x;

  return temp;
}

Matrix Matrix::operator+(const Matrix &x) const
{
  Matrix temp = *this;

  for (int i = 0; i < height * width; ++i)
  {
    temp.data[i] += x.data[i];
  }

  return temp;
}

Matrix Matrix::operator-(const int &x) const
{
  Matrix temp = *this;

  for (int i = 0; i < height * width; ++i)
  {
    temp.data[i] -= x;
  }

  return temp;
}

Matrix Matrix::operator-(const Matrix &x) const
{
  Matrix temp = *this;

  for (int i = 0; i < height * width; ++i)
  {
    temp.data[i] -= x.data[i];
  }

  return temp;
}

Matrix Matrix::operator*(const int &x) const
{
  Matrix temp = *this;

  for (int i = 0; i < height * width; ++i)
  {
    temp.data[i] *= x;
  }

  return temp;
}

Matrix Matrix::operator*(const float &x) const
{
  Matrix temp = *this;

  for (int i = 0; i < height * width; ++i)
  {
    temp.data[i] *= x;
  }

  return temp;
}

Matrix Matrix::operator*(const Matrix &x) const
{
  Matrix temp = *this;

  for (int i = 0; i < height * width; ++i)
  {
    temp.data[i] *= x.data[i];
  }

  return temp;
}

float* Matrix:: operator[](const int& x) const
{
  float* line = new float[width];

  for (int i = x * width; i < x * width + width; ++i)
  {
    line[i] = data[i];
  }

  return line;
}

Matrix& Matrix::operator= (const Matrix &x)
{
  height = x.height;
  width = x.width;
  data = new float[width * height];

  for (int i = 0; i < width * height; ++i)
  {
    data[i] = x.data[i];
  }
  
  return *this;
}

Matrix& Matrix::operator+=(const int &x) 
{
  Matrix temp = *this;

  for (int i = 0; i < height * width; ++i)
  {
    temp.data[i] += x;
  }

  return temp;
}

Matrix& Matrix::operator+=(const Matrix &x) 
{
  Matrix temp = *this;

  for (int i = 0; i < height * width; ++i)
  {
    temp.data[i] += x.data[i];
  }

  return temp;
}