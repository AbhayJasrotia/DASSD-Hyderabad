#include <iostream>
using namespace std;

class Artist {
public:
    void showSkill() {
        cout << "Artistic Skill: Digital Painting" << endl;
    }
};

class Coder {
public:
    void showSkill() {
        cout << "Coding Skill: C++ and OOP" << endl;
    }
};

class TechArtist : public Artist, public Coder {
public:
    void showAllSkills() {
        cout << "--- TechArtist Skills ---" << endl;
        Artist::showSkill();   // resolve ambiguity
        Coder::showSkill();
    }
};

int main() {
    TechArtist t1;
    t1.showAllSkills();
    return 0;
}
