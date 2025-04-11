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
        ifstream file("bin/familia.csv");
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


            if (root == nullptr) {
                root = newMember;
            } else {
                FamilyMember* father = findMemberById(root, id_father);
                insertMember(father, newMember);
            }
            
            
            if (is_chief && !is_dead) {
                current_chief = newMember;
            }
        }
        
        file.close();
    }
    
    void loadContributors(string filename) {
        ifstream file("bin/contribuidores.csv");
        if (!file.is_open()) {
            cerr << "Error al abrir el archivo de contribuidores: " << filename << endl;
            return;
        }
        
        string line;
        getline(file, line); 
        
        while (getline(file, line)) {
            stringstream ss(line);
            string token;
            
            int member_id, contrib_id, age, grade;
            string name, desc;
            
            getline(ss, token, ',');
            member_id = stoi(token);
            
            getline(ss, name, ',');
            getline(ss, token, ',');
            age = stoi(token);
            
            getline(ss, token, ',');
            contrib_id = stoi(token);
            
            getline(ss, desc, ',');
            getline(ss, token, ',');
            grade = stoi(token);
            
            FamilyMember* member = findMemberById(root, member_id);
            if (member != nullptr) {
                Contributor* newContrib = new Contributor();
                newContrib->name = name;
                newContrib->age = age;
                newContrib->id = contrib_id;
                newContrib->contribution_desc = desc;
                newContrib->contribution_grade = grade;
                
                addContributorSorted(member->contributors, newContrib);
            }
        }
        
        file.close();
    }
    
    void displaySuccession() {
        if (current_chief == nullptr) {
            cout << "No hay lider actual." << endl;
            return;
        }
        
        cout << "Linea de sucesion actual:" << endl;
        printSuccession(current_chief);
    }
    
    void assignNewChief() {
        if (current_chief == nullptr || !current_chief->is_dead) {
            return;
        }
        
        FamilyMember* newChief = findMaleSuccessor(current_chief);
        
        if (newChief == nullptr) {
            newChief = findFemaleSuccessor(current_chief);
        }
        
        if (newChief != nullptr) {
            current_chief->is_chief = false;
            newChief->is_chief = true;
            newChief->was_chief = true;
            current_chief = newChief;
            cout << "Nuevo lider asignado: " << newChief->name << " " << newChief->last_name << endl;
        } else {
            cout << "No se pudo encontrar un sucesor adecuado." << endl;
        }
    }
    
    void displayChief() {
        if (current_chief == nullptr) {
            cout << "No hay lider actual." << endl;
            return;
        }
        
        cout << "Lider actual:" << endl;
        cout << "ID: " << current_chief->id << endl;
        cout << "Nombre: " << current_chief->name << " " << current_chief->last_name << endl;
        cout << "Edad: " << current_chief->age << " años" << endl;
        cout << "Genero: " << (current_chief->gender == 'H' ? "Hombre" : "Mujer") << endl;
        cout << "Estado: " << (current_chief->is_dead ? "Difunto" : "Vivo") << endl;
        
        
        if (current_chief->contributors != nullptr) {
            cout << "\nContribuidores:" << endl;
            Contributor* current = current_chief->contributors;
            int position = 1;
            while (current != nullptr) {
                cout << position++ << ". " << current->name << " (ID: " << current->id 
                     << ", Edad: " << current->age << ")" << endl;
                cout << "   Contribucion: " << current->contribution_desc << endl;
                cout << "   Grado: " << current->contribution_grade << "/10" << endl;
                current = current->next;
            }
        } else {
            cout << "\nNo hay contribuidores registrados." << endl;
        }
    }
    
    void checkAgeAndTransferLeadership() {
        if (current_chief != nullptr && current_chief->age > 70 && !current_chief->is_dead) {
            FamilyMember* successor = findMaleSuccessor(current_chief);
            if (successor != nullptr) {
                current_chief->is_chief = false;
                successor->is_chief = true;
                successor->was_chief = true;
                current_chief = successor;
                cout << "Liderazgo transferido por edad: " << successor->name << " " << successor->last_name << endl;
            }
        }
    }
    
    void updateMemberData(int id) {
        FamilyMember* member = findMemberById(root, id);
        if (member == nullptr) {
            cout << "Miembro no encontrado." << endl;
            return;
        }
        
        cout << "Actualizando datos de: " << member->name << " " << member->last_name << endl;
        
        int opcion;
        do {
            cout << "\nSeleccione dato a actualizar:" << endl;
            cout << "1. Nombre" << endl;
            cout << "2. Apellido" << endl;
            cout << "3. Edad" << endl;
            cout << "4. Estado de vida" << endl;
            cout << "5. Estado de liderazgo" << endl;
            cout << "0. Volver al menu principal" << endl;
            cout << "Opcion: ";
            cin >> opcion;
            cin.ignore(); 
            
            switch (opcion) {
                case 1: {
                    cout << "Nuevo nombre: ";
                    getline(cin, member->name);
                    break;
                }
                case 2: {
                    cout << "Nuevo apellido: ";
                    getline(cin, member->last_name);
                    break;
                }
                case 3: {
                    cout << "Nueva edad: ";
                    cin >> member->age;
                    break;
                }
                case 4: {
                    cout << "¿El miembro ha fallecido? (1=Sí, 0=No): ";
                    cin >> member->is_dead;
                    if (member->is_dead && member->is_chief) {
                        assignNewChief();
                    }
                    break;
                }
                case 5: {
                    cout << "¿Es ahora el líder? (1=Sí, 0=No): ";
                    bool was_chief = member->is_chief;
                    cin >> member->is_chief;
                    if (member->is_chief) {
                        member->was_chief = true;
                        if (current_chief != nullptr && current_chief != member) {
                            current_chief->is_chief = false;
                        }
                        current_chief = member;
                    } else if (was_chief) {
                        assignNewChief();
                    }
                    break;
                }
                case 0:
                    break;
                default:
                    cout << "Opcion no valida." << endl;
            }
        } while (opcion != 0);
    }
};
int main() {
    FamilyTree family;
    

    family.loadFromCSV("familia.csv");
    family.loadContributors("contribuidores.csv");
    
    int opcion;
    do {
        cout << "\nMenu del Clan del Shogun" << endl;
        cout << "1. Mostrar linea de sucesion" << endl;
        cout << "2. Asignar nuevo lider (si el actual murio)" << endl;
        cout << "3. Verificar edad del lider y transferir si es necesario" << endl;
        cout << "4. Mostrar lider actual" << endl;
        cout << "5. Actualizar datos de un miembro" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        
        switch (opcion) {
            case 1:
                family.displaySuccession();
                break;
            case 2:
                family.assignNewChief();
                break;
            case 3:
                family.checkAgeAndTransferLeadership();
                break;
            case 4:
                family.displayChief();
                break;
            case 5: {
                int id;
                cout << "Ingrese ID del miembro a actualizar: ";
                cin >> id;
                family.updateMemberData(id);
                break;
            }
            case 0:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opcion no valida." << endl;
        }
    } while (opcion != 0);
    
    return 0;
}

