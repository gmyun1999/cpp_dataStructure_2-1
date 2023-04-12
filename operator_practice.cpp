#include <iostream>
#include <string>
#include <iostream>

class Point {
private:
    int x;
    int y;

public:
    Point(int a = 0, int b = 0);

    friend std::ostream &operator<<(std::ostream &out, const Point *ptr);


};

Point::Point(int a, int b) {
    x = a;
    y = b;
}

std::ostream &operator<<(std::ostream &out, const Point *ptr) {
    return (out << '[' << ptr->x << ',' << ptr->y << ']');
}

//이거 &를 사용했을때는 객체의 주솟값을 이용한다는 의미가 되지만 실상 이거는 매개변수에 넣어줄때는
//객체 자체를 넣어줘야함 즉 주솟값을 넘겨주면안된다는소리임.
//std::ostream &operator<<(std::ostream &out, const Point &ptr) {
//    return (out << '[' << ptr.x << ',' << ptr.y << ']');
//}

int main() {
    Point *point = new Point(3, 5);
    std::cout << point;
}