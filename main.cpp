#include <iostream>
#include <cmath>

using namespace std;

class Vector3D {
  public:
    Vector3D() {
      x_ = 0;
      y_ = 0;
      z_ = 0;
    }
    ~Vector3D() {}
    double x() const {
      return x_;
    }
    double y() const {
      return y_;
    }
    double z() const {
      return z_;
    }
    double& x() {
      return x_;
    }
    double& y() {
      return y_;
    }
    double& z() {
      return z_;
    }
    void print() {
      cout << "x = " << x_ << ", y = " << y_ << ", z = " << z_ << endl;
    }
    Vector3D operator+(const Vector3D& v2) {
      Vector3D vec;
      vec.x_ = x_ + v2.x_;
      vec.y_ = y_ + v2.y_;
      vec.z_ = z_ + v2.z_;
      return vec;
    }
    Vector3D operator-(const Vector3D& v2) {
      Vector3D vec;
      vec.x_ = x_ - v2.x_;
      vec.y_ = y_ - v2.y_;
      vec.z_ = z_ - v2.z_;
      return vec;
    }
    Vector3D crossProduct(const Vector3D& v2) const {
      Vector3D vec;
      vec.x_ = y_ * v2.z_ - z_ * v2.y_;
      vec.y_ = z_ * v2.x_ - x_ * v2.z_;
      vec.z_ = x_ * v2.y_ - y_ * v2.x_;
      return vec;
    }
    double scalarProduct(const Vector3D& v2) const {
      return (x_ * v2.x_ + y_ * v2.y_ + z_ * v2.z_);
    }
    Vector3D operator*(const int& number) {
      Vector3D vec;
      vec.x_ = number * x_;
      vec.y_ = number * y_;
      vec.z_ = number * z_;
      return vec;
    }
    void compare(const Vector3D& v2) {
      if ((x_ == v2.x_) && (y_ == v2.y_) && (z_ == v2.z_))
        cout << "Вектора a и b совпадают" << endl;
      else
        cout << "Вектора a и b не совпадают" << endl;
    }
    double length() const {
        return sqrt(x_ * x_ + y_ * y_ + z_ * z_);
    }
    void compareLength(const Vector3D& v2) {
      double l1 = this->length();
      double l2 = v2.length();
      if (l1 == l2)
        cout << "Вектора a и b равны" << endl;
      else if(l1 > l2)
        cout << "Вектор a длиннее вектора b" << endl;
      else if(l1 < l2)
        cout << "Вектор a короче вектора b" << endl; 
    }
    double angle(const Vector3D& vec) const {
      if ((this->length() == 0) || (vec.length() == 0 ))
        return 0;
      const double half = 180/M_PI;
      double cosin = (this->scalarProduct(vec)) / (this->length() * vec.length()) ;
      if (cosin < -1) {
        return 180;
      }
      if (cosin > 1) {
        return 0;
      }
      return half*acos(cosin);
    }
  private:
    double x_;
    double y_;
    double z_;
};

int main() {
  Vector3D a, b;
  cout << "Bведите координаты вектора a" << endl;
  cin >> a.x() >> a.y() >> a.z();
  cout << "Bведите координаты вектора b" << endl;
  cin >> b.x() >> b.y() >> b.z();
  cout << "Введите число c" << endl;
  double num, c;
  cin >> c;
  cout << "Вектор a: ";
  a.print();
  cout << "Вектор b: ";
  b.print();
  cout << "Сумма векторов: ";
  Vector3D v;
  v = a + b;
  v.print();
  cout << "Разность векторов: ";
  v = a - b;
  v.print();
  cout << "Векторное произведение: ";
  v = a.crossProduct(b);
  v.print();
  cout << "Скалярное произведение: " << a.scalarProduct(b) << endl;
  cout << "a * c: ";
  v = a * c;
  v.print();
  cout << "b * c: ";
  v = b * c;
  v.print();
  a.compare(b);
  cout << "Вектор a = " << a.length() << endl;
  cout << "Вектор b = " << b.length() << endl;
  a.compareLength(b);
  cout << "Угол между векторами a и b = " << a.angle(b) << " градусов" << endl;
}
