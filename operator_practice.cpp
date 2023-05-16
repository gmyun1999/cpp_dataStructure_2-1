#include <iostream>
#include <string>
#include <iostream>

class Point {
private:
    int x;
    int y;

public:
    Point(int a = 0, int b = 0);

    friend std::ostream &operator<<(std::ostream &out, const Point&ptr);

};

Point::Point(int a, int b) {
    x = a;
    y = b;
}

std::ostream &operator<<(std::ostream &out, const Point &ptr) {
    return (out << '[' << ptr.x << ',' << ptr.y << ']');
}



int main() {
    Point *point = new Point(3, 5);
    std::cout << point;
}