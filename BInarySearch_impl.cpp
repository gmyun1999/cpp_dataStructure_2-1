# include <iostream>
# include <vector>
int binarySearch_rec(int val, const std::vector<int> & list, int first, int last){
    int center = (first+last)/2;
    if (first>last){
        return 0;
    }
    if (val==list[center]){
        return val;
    }else if(val<list[center]){
        binarySearch_rec(val, list, first, center-1);
    }else{
        binarySearch_rec(val, list, center+1, last);
    }
}



int main(){
    std::vector<int> list = {3,4,5,6,7,8,9,10,13,15};
    int result = binarySearch_rec(3,list,0,9);
    std::cout<<result<<std::endl;
    result = binarySearch_rec(15,list,0,9);
    std::cout<<result<<std::endl;
    result = binarySearch_rec(7,list,0,9);
    std::cout<<result<<std::endl;
    result = binarySearch_rec(12,list,0,9);
    std::cout<<result<<std::endl;
    result = binarySearch_rec(14,list,0,9);
    std::cout<<result<<std::endl;
    result = binarySearch_rec(20,list,0,9);
    std::cout<<result<<std::endl;
    result = binarySearch_rec(-1,list,0,9);
    std::cout<<result<<std::endl;
    result = binarySearch_rec(5,list,0,9);
    std::cout<<result<<std::endl;
}