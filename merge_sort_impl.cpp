# include <iostream>
# include <vector>
# include <cmath>

std::vector<int> merge_sort_impl(const std::vector<int> &l) {
    if (l.size() < 2) {
        return l;
    }
    auto center = l.begin();
    std::advance(center, floor(std::distance(l.begin(), l.end()) / 2));
    std::vector<int> ll = merge_sort_impl(std::vector<int>(l.begin(), center));
    std::vector<int> lr = merge_sort_impl(std::vector<int>(center, l.end()));
    std::vector<int> container;
    auto it1 = ll.begin();
    auto it2 = lr.begin();
    while (!(it1 == ll.end() && it2 == lr.end())) {
        if (it1 == ll.end()) {
            container.push_back(*it2++);
        } else if (it2 == lr.end()) {
            container.push_back(*it1++);
        } else if (*it1 <= *it2) {
            container.push_back(*it1++);
        }else{
            container.push_back(*it2++);
        }
    }
//    std::cout << "combined container: ";
//    for (const auto &alem: container) {
//        std::cout << alem << ",";
//    }
//    std::cout << "" << std::endl;
    return container;
}


int main() {
    std::vector<int> list1 = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    auto merged_list1 = merge_sort_impl(list1);
    std::cout<<"merged_list:";
    for (const auto &alem: merged_list1) {
        std::cout << alem << ",";
    }
    std::cout << std::endl;

    std::vector<int> list2 = {8, 1, 2, 3, 4, 7, 9, 6, 5};
    auto merged_list2 = merge_sort_impl(list2);
    std::cout<<"merged_list:";
    for (const auto &alem: merged_list2) {
        std::cout << alem << ",";
    }
    std::cout << std::endl;

    std::vector<int> list3 = {6, 5};
    auto merged_list3 = merge_sort_impl(list3);
    std::cout<<"merged_list:";
    for (const auto &alem: merged_list3) {
        std::cout << alem << ",";}
    std::cout << std::endl;

    std::vector<int> list4 = {6};
    auto merged_list4 = merge_sort_impl(list4);
    std::cout<<"merged_list:";
    for (const auto &alem: merged_list4) {
        std::cout << alem << ",";
    }
}