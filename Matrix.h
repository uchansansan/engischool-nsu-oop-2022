class Matrix
{
public:
  Matrix();
  Matrix(const int &y, const int &x);
  Matrix(const Matrix &x);

  Matrix operator+ (const int &x) const;
  Matrix operator+ (const Matrix &x) const;
  Matrix operator- (const int &x) const;
  Matrix operator- (const Matrix &x) const;
  Matrix operator* (const int &x) const;
  Matrix operator* (const float &x) const;
  Matrix operator* (const Matrix &x) const;
  float* operator[] (const int &x) const;
  Matrix& operator= (const Matrix &x);
  Matrix& operator+= (const int &x);
  Matrix& operator+= (const Matrix &x);


private:
  int height, width;
  float* data;
};