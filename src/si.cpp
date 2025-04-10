#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

// Estructura para los contribuidores
struct Contributor {
    string name;
    int age;
    int id;
    string contribution_desc;
    int contribution_grade;
    Contributor* next;
    
    Contributor() : next(nullptr) {}
};

// Estructura para los nodos del árbol genealógico
struct FamilyMember {
    int id;
    string name;
    string last_name;
    char gender; // 'H' o 'M'
    int age;
    int id_father;
    bool is_dead;
    bool was_chief;
    bool is_chief;
    
    FamilyMember* left;   // Hijo izquierdo (primer hijo)
    FamilyMember* right;  // Hijo derecho (hermano)
    FamilyMember* father; // Referencia al padre
    
    Contributor* contributors; // Lista de contribuidores
    
    FamilyMember() : left(nullptr), right(nullptr), father(nullptr), contributors(nullptr) {}
};

