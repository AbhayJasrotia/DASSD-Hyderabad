#include <iostream>
#include <cstring>
using namespace std;

class Student {
private:
    char* name;
    int studentId;
    char** courses;  // Array of course names
    int numCourses;
    int maxCourses;
    
public:
    // Parameterized constructor
    Student(const char* studentName, int id, int maxCourses = 5);
    
    // Deep copy constructor
    Student(const Student& other);
    
    // Destructor
    ~Student();
    
    // Assignment operator (bonus)
    Student& operator=(const Student& other);
    
    // Member functions
    void addCourse(const char* courseName);
    void display() const;
    void setName(const char* newName);
    
    // Helper function
    int getNumCourses() const { return numCourses; }
};