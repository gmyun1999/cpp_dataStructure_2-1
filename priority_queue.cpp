#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

template<typename T>
void print_queue(T q) {
    while (!q.empty()) {
        std::cout << q.top() << ' ';
        q.pop();
    }
    std::cout << '\n';
}

int main() {
    priority_queue<int> q;
    const auto data = {1, 8, 5, 6, 3, 4, 0, 9, 7, 2};
    for (int n: data){
        q.push(n);
    }
    print_queue(q);
    std::priority_queue<int, std::vector<int>, std::greater<int>>
            q2(data.begin(), data.end());
    print_queue(q2);
}
