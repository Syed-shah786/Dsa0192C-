#include <iostream>
#include <string>

class Student {
protected:
    int roll_no;
    std::string name;
public:
    void getStudentInfo() {
        std::cout << "Enter roll number: ";
        std::cin >> roll_no;
        std::cin.ignore(); // To ignore the newline character left in the buffer
        std::cout << "Enter name: ";
        std::getline(std::cin, name);
    }
    void displayStudentInfo() const {
        std::cout << "Roll Number: " << roll_no << "\n";
        std::cout << "Name: " << name << "\n";
    }
};

class Test : virtual public Student {
protected:
    int subject_scores[5];
public:
    void getTestScores() {
        std::cout << "Enter scores for 5 subjects: ";
        for (int i = 0; i < 5; ++i) {
            std::cin >> subject_scores[i];
        }
    }
    void displayTestScores() const {
        std::cout << "Subject Scores: ";
        for (int i = 0; i < 5; ++i) {
            std::cout << subject_scores[i] << " ";
        }
        std::cout << "\n";
    }
};

class Sports : virtual public Student {
protected:
    int sports_score;
public:
    void getSportsScore() {
        std::cout << "Enter sports score: ";
        std::cin >> sports_score;
    }
    void displaySportsScore() const {
        std::cout << "Sports Score: " << sports_score << "\n";
    }
};

class Result : public Test, public Sports {
public:
    void displayResult() {
        displayStudentInfo();
        displayTestScores();
        displaySportsScore();
        
        int total_score = 0;
        for (int i = 0; i < 5; ++i) {
            total_score += subject_scores[i];
        }
        total_score += sports_score;
        
        std::cout << "Total Score: " << total_score << "\n";
    }
};

int main() {
    Result student;
    student.getStudentInfo();
    student.getTestScores();
    student.getSportsScore();
    student.displayResult();
    return 0;
}

