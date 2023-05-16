
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

    Student(long studentCode, string name, int midTermScore, int finalTermScore) : studentCode(studentCode),
                                                                                   name(std::move(name)),
                                                                                   midTermScore(midTermScore),
                                                                                   finalTermScore(finalTermScore) {
        func_finalScore();
    }


    //final score return func
    float func_finalScore() {
        float score = static_cast<float>( midTermScore + finalTermScore) / 2.0f;
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
    try {
        cout << "studentID: ";
        cin >> studentCode;
        cout << "name: ";
        cin >> studentName;
        cout << "midTerm Grade: ";
        cin >> midTermScore;
        cout << "finalTerm Grade:";
        cin >> finalTermScore;
    } catch (exception ex) {
        cout << "Incorrect input format";
        return;
    }
    for (const auto &student: students) {
        if (student.studentCode == studentCode) {
            cout << "The student already exists." << endl;
            return;
        }
    }
    students.emplace_back(studentCode, studentName, midTermScore, finalTermScore);
}

void deleteStudent(vector<Student> &students) {
    int studentCode;
    cout << "Enter the studentID you want to erase: ";
    try {
        cin >> studentCode;
    } catch (exception) {
        cout << "Incorrect input format";
    }
    int i = 0;
    for (auto &student: students) {
        if (student.studentCode == studentCode) {
            students.erase(students.begin() + i);
            return;
        }
        i += 1;
    }
    cout << "No such student" << endl;
}

bool modifyTermScore(int caseNum, vector<Student> &students) {
    int studentCode;
    int score_toBeChanged;
    cout << "Enter the studentID you want to modify the term score:";
    cin >> studentCode;
    cout << "Enter the score you want to change: ";
    cin >> score_toBeChanged;
    auto student_it = find_if(students.begin(), students.end(),
                              [studentCode](const Student &s) { return s.studentCode == studentCode; });

    if (student_it == students.end()) {
        cout << "No such student" << endl;
        return false;
    }

    if (caseNum == 3) {
        student_it->midTermScore = score_toBeChanged;
    } else if (caseNum == 4) {
        student_it->finalTermScore = score_toBeChanged;
    }
    student_it->func_finalScore();
    return true;
}

void sortArr(vector<Student> &students, int caseNum) {
    if (students.size() < 2) {
        return;
    }
    if (caseNum == 5) {
        sort(students.begin(), students.end(), [](const Student &a, const Student &b) {
            return a.studentCode > b.studentCode;
        });
    } else {
        sort(students.begin(), students.end(), [](const Student &a, const Student &b) {
            return a.finalScore < b.finalScore;
        });
    }
}

void findName(vector<Student> &students) {
    vector<Student *> matchingStudents;
    string name;
    cout << "Tell me the name you're looking for: ";
    cin >> name;
    for (auto &student: students) {
        if (name == student.name) {
            matchingStudents.push_back(&student);
        }
    }
    if (matchingStudents.empty()) {
        return;
    }
    cout << "students you looking for:" << endl;
    for (auto &student: matchingStudents) {
        cout << student->studentCode << endl;
    }
}

int main() {
    vector<Student> studentList;
    int exit = 0;
    while (true) {
        cout << "---------------------------------------------" << endl;
        cout << "students:" << endl;
        for (const Student &stu: studentList) {
            cout << stu << endl;
        }
        cout << "---------------------------------------------" << endl;
        cout << endl;
        cout << "enter the operation_code: ";
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
                deleteStudent(studentList);
                break;
            case 3:
                modifyTermScore(3, studentList);
                break;
            case 4:
                modifyTermScore(4, studentList);
                break;
            case 5:
                sortArr(studentList, 5);
                break;
            case 6:
                sortArr(studentList, 6);
                break;
            case 7:
                findName(studentList);
                break;
            case 8:
                exit = 1;
                break;
            default:
                break;
        }
        if (exit == 1) {
            break;
        }
    }
    studentList.clear();
}