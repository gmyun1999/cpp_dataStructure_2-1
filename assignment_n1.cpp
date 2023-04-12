
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    long studentCode;
    string name;
    int midTermScore;
    int finalTermScore;
    float finalScore = 0.0;

    Student(long studentCode, string name, int midTermScore, int finalTermScore) : studentCode(studentCode), name(name),
                                                                                   midTermScore(midTermScore),
                                                                                   finalTermScore(finalTermScore) {}


    //final score return func
    float func_finalScore() {
        float score = ((float) (midTermScore + finalTermScore)) / 2.0;
        this->finalScore = score;
        return (this->finalScore);
    }

    //operator overloading
    friend ostream &operator<<(std::ostream &out, const Student &student) {
        return (out << '[' << student.studentCode << ',' << student.name << ',' << student.finalScore <<
                    ']');
    }

};

void addStudent(vector<Student> &students) {
    long studentCode;
    string studentName;
    int midTermScore;
    int finalTermScore;
    cout << "studentID: ";
    cin >> studentCode;
    cout << "name: ";
    cin >> studentName;
    cout << "midTerm Grade: ";
    cin >> midTermScore;
    cout << "finalTerm Grade:";
    cin >> finalTermScore;
    for (const auto& student: students){
        if (student.studentCode==studentCode){
            cout<<"The student already exists.";
            return ;
        }
    }
    Student *stu = new Student(studentCode,studentName,midTermScore,finalTermScore);
    students.push_back(*stu);
    return ;
}

int main() {
    vector<Student> studentList;
    int exit = 0;
    while (1) {
        for (Student stu: studentList) {
            cout << stu;
        }
        int operation_code;
        try {
            cin >> operation_code;
        } catch (exception) {
            cout << "Wrong code";
            break;
        }
        if (0 >= operation_code or 8 < operation_code) {
            cout << "Wrong code";
            break;
        }
        switch (operation_code) {
            case 1:
                addStudent(studentList);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                exit = 1;
                break;
        }
        if (exit==1){
            break;
        }
    }

}