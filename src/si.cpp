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
 FamilyMember* createMember(int id, string name, string last_name, char gender, 
                             int age, int id_father, bool is_dead, bool was_chief, bool is_chief) {
        FamilyMember* newMember = new FamilyMember();
        newMember->id = id;
        newMember->name = name;
        newMember->last_name = last_name;
        newMember->gender = gender;
        newMember->age = age;
        newMember->id_father = id_father;
        newMember->is_dead = is_dead;
        newMember->was_chief = was_chief;
        newMember->is_chief = is_chief;
        return newMember;
    }
  void insertMember(FamilyMember* parent, FamilyMember* newMember) {
        if (parent == nullptr) return;
        
        newMember->father = parent;
        
        if (parent->left == nullptr) {
            parent->left = newMember;
        } else {
            
            FamilyMember* sibling = parent->left;
            while (sibling->right != nullptr) {
                sibling = sibling->right;
            }
            sibling->right = newMember;
        }
    }
    
    FamilyMember* findMemberById(FamilyMember* node, int id) {
        if (node == nullptr) return nullptr;
        if (node->id == id) return node;
        
       
        FamilyMember* found = findMemberById(node->left, id);
        if (found != nullptr) return found;
        
       
        return findMemberById(node->right, id);
    }
    
    void printSuccession(FamilyMember* node) {
        if (node == nullptr || node->is_dead) return;
        
        cout << node->id << ": " << node->name << " " << node->last_name 
             << " (" << node->age << " años)" << endl;
        
        
        FamilyMember* child = node->left;
        while (child != nullptr) {
            if (!child->is_dead && child->gender == 'H') {
                printSuccession(child);
            }
            child = child->right;
        }
        
      
        child = node->left;
        while (child != nullptr) {
            if (!child->is_dead && child->gender == 'M') {
                printSuccession(child);
            }
            child = child->right;
        }
    }
    
    FamilyMember* findMaleSuccessor(FamilyMember* node) {
        if (node == nullptr) return nullptr;
        
        
        FamilyMember* child = node->left;
        while (child != nullptr) {
            if (!child->is_dead && child->gender == 'H') {
                return child;
            }
            child = child->right;
        }
        
        
        child = node->left;
        while (child != nullptr) {
            if (!child->is_dead && child->gender == 'M') {
                FamilyMember* grandson = child->left;
                while (grandson != nullptr) {
                    if (!grandson->is_dead && grandson->gender == 'H') {
                        return grandson;
                    }
                    grandson = grandson->right;
                }
            }
            child = child->right;
        }
        
       
        if (node->father != nullptr) {
            FamilyMember* sibling = node->father->left;
            while (sibling != nullptr) {
                if (sibling != node && !sibling->is_dead) {
                    if (sibling->gender == 'H') {
                        return sibling;
                    } else {
                       
                        if (sibling->left == nullptr) {
                            return sibling;
                        }
                    }
                }
                sibling = sibling->right;
            }
        }
        
     
        if (node->father != nullptr && node->father->father != nullptr) {
            FamilyMember* uncle = node->father->father->left;
            while (uncle != nullptr) {
                if (uncle != node->father && !uncle->is_dead) {
                    if (uncle->gender == 'H') {
                        return uncle;
                    } else {
                        
                        if (uncle->left == nullptr) {
                            return uncle;
                        }
                    }
                }
                uncle = uncle->right;
            }
        }
        
       
        FamilyMember* ancestor = node;
        while (ancestor->father != nullptr) {
            ancestor = ancestor->father;
            int childCount = 0;
            FamilyMember* child = ancestor->left;
            while (child != nullptr) {
                childCount++;
                child = child->right;
            }
            
            if (childCount >= 2) {
                child = ancestor->left;
                while (child != nullptr) {
                    if (!child->is_dead && child->gender == 'H') {
                        return child;
                    }
                    child = child->right;
                }
            }
        }
        
        return nullptr;
    }
    
    FamilyMember* findFemaleSuccessor(FamilyMember* node) {
        if (node == nullptr) return nullptr;
        
        
        FamilyMember* child = node->left;
        while (child != nullptr) {
            if (!child->is_dead && child->gender == 'M') {
                return child;
            }
            child = child->right;
        }
        
      
        child = node->left;
        while (child != nullptr) {
            if (!child->is_dead && child->gender == 'H') {
                FamilyMember* granddaughter = child->left;
                while (granddaughter != nullptr) {
                    if (!granddaughter->is_dead && granddaughter->gender == 'M') {
                        return granddaughter;
                    }
                    granddaughter = granddaughter->right;
                }
            }
            child = child->right;
        }
        
      
        if (node->father != nullptr) {
            FamilyMember* sibling = node->father->left;
            while (sibling != nullptr) {
                if (sibling != node && !sibling->is_dead && sibling->gender == 'M') {
                    return sibling;
                }
                sibling = sibling->right;
            }
        }
        
       
        if (node->father != nullptr && node->father->father != nullptr) {
            FamilyMember* aunt = node->father->father->left;
            while (aunt != nullptr) {
                if (aunt != node->father && !aunt->is_dead && aunt->gender == 'M') {
                    return aunt;
                }
                aunt = aunt->right;
            }
        }
        
       
        FamilyMember* ancestor = node;
        while (ancestor->father != nullptr) {
            ancestor = ancestor->father;
            int childCount = 0;
            FamilyMember* child = ancestor->left;
            while (child != nullptr) {
                childCount++;
                child = child->right;
            }
            
            if (childCount >= 2) {
                child = ancestor->left;
                while (child != nullptr) {
                    if (!child->is_dead && child->gender == 'M') {
                        return child;
                    }
                    child = child->right;
                }
            }
        }
        
        return nullptr;
    }
    
    void updateChiefStatus(FamilyMember* node) {
        if (node == nullptr) return;
        
        if (node->is_chief && node->is_dead) {
            assignNewChief();
        }
        
        updateChiefStatus(node->left);
        updateChiefStatus(node->right);
    }
    
    void addContributorSorted(Contributor*& head, Contributor* newContrib) {
        if (head == nullptr || 
            (newContrib->contribution_grade > head->contribution_grade) ||
            (newContrib->contribution_grade == head->contribution_grade && newContrib->age > head->age)) {
            newContrib->next = head;
            head = newContrib;
        } else {
            Contributor* current = head;
            while (current->next != nullptr && 
                   ((current->next->contribution_grade > newContrib->contribution_grade) ||
                    (current->next->contribution_grade == newContrib->contribution_grade && 
                     current->next->age > newContrib->age))) {
                current = current->next;
            }
            newContrib->next = current->next;
            current->next = newContrib;
        }
    }
    
public:
    FamilyTree() : root(nullptr), current_chief(nullptr) {}
    
    void loadFromCSV(string filename) {
        ifstream file("familia.csv");
        if (!file.is_open()) {
            cerr << "Error al abrir el archivo: " << filename << endl;
            return;
        }
        
        string line;
        getline(file, line); 
        
        while (getline(file, line)) {
            stringstream ss(line);
            string token;
            
            int id, age, id_father;
            string name, last_name;
            char gender;
            bool is_dead, was_chief, is_chief;
            
           
            getline(ss, token, ',');
            id = stoi(token);
            
            getline(ss, name, ',');
            getline(ss, last_name, ',');
            
            getline(ss, token, ',');
            gender = token[0];
            
            getline(ss, token, ',');
            age = stoi(token);
            
            getline(ss, token, ',');
            id_father = stoi(token);
            
            getline(ss, token, ',');
            is_dead = (token == "1");
            
            getline(ss, token, ',');
            was_chief = (token == "1");
            
            getline(ss, token, ',');
            is_chief = (token == "1");

            FamilyMember* newMember = createMember(id, name, last_name, gender, age, 
                                                 id_father, is_dead, was_chief, is_chief);
