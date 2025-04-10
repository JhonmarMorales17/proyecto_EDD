#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;


struct Contributor {
    string name;
    int age;
    int id;
    string contribution_desc;
    int contribution_grade;
    Contributor* next;
    
    Contributor() : next(nullptr) {}
};


struct FamilyMember {
    int id;
    string name;
    string last_name;
    char gender; 
    int age;
    int id_father;
    bool is_dead;
    bool was_chief;
    bool is_chief;
    
    FamilyMember* left;   
    FamilyMember* right;  
    FamilyMember* father; 
    
    Contributor* contributors; 
    
    FamilyMember() : left(nullptr), right(nullptr), father(nullptr), contributors(nullptr) {}
};

class FamilyTree {
private:
    FamilyMember* root;
    FamilyMember* current_chief;
    
    
