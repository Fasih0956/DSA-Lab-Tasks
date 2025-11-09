#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;
class Combatant{
public:
    string name;
    int hp;
    int attack;
    Combatant(string n, int h, int a) : name(n), hp(h), attack(a) {}
};
class Node{
public:
    Combatant* c;
    Node* left;
    Node* right;
    Node(Combatant* combatant) : c(combatant), left(nullptr), right(nullptr) {}
};
class BST {
public:
    Node* root;
    BST() { root = nullptr; }

    Node* insert(Node* node, Combatant* c) {
        if (!node) return new Node(c);
        if (c->name < node->c->name) node->left = insert(node->left, c);
        else node->right = insert(node->right, c);
        return node;
    }
    Node* minNode(Node* node) {
        Node* current = node;
        while (current && current->left) current = current->left;
        return current;
    }
    Node* deleteNode(Node* node, string name) {
        if (!node) return node;
        if (name < node->c->name) node->left = deleteNode(node->left, name);
        else if (name > node->c->name) node->right = deleteNode(node->right, name);
        else {
            if (!node->left) {
                Node* temp = node->right;
                delete node->c;
                delete node;
                return temp;
            } else if (!node->right) {
                Node* temp = node->left;
                delete node->c;
                delete node;
                return temp;
            }
            Node* temp = minNode(node->right);
            node->c = temp->c;
            node->right = deleteNode(node->right, temp->c->name);
        }
        return node;
    }
    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->c->name << "(" << node->c->hp << ") ";
        inorder(node->right);
    }
    bool isEmpty() { return root == nullptr; }
};
int damage(int attack) { 
    return attack + rand() % 5;
 }
int main(){
    srand(time(0));
    BST heroes, enemies;

    // Initialize heroes
    heroes.root = heroes.insert(heroes.root, new Combatant("Pekka", 20, 5));
    heroes.root = heroes.insert(heroes.root, new Combatant("NightWitch", 22, 4));
    heroes.root = heroes.insert(heroes.root, new Combatant("Barbarian", 18, 6));
    heroes.root = heroes.insert(heroes.root, new Combatant("Giant", 25, 3));
    heroes.root = heroes.insert(heroes.root, new Combatant("Archer", 19, 5));

    // Initialize enemies
    enemies.root = enemies.insert(enemies.root, new Combatant("Goblin", 15, 4));
    enemies.root = enemies.insert(enemies.root, new Combatant("Ballon", 20, 5));
    enemies.root = enemies.insert(enemies.root, new Combatant("Bomber", 25, 3));
    enemies.root = enemies.insert(enemies.root, new Combatant("Zombie", 18, 4));
    enemies.root = enemies.insert(enemies.root, new Combatant("Vampire", 22, 6));

    int round = 1;
    while (!heroes.isEmpty() && !enemies.isEmpty()) {
        cout << "\n--- Round " << round++ << " ---\n";
        cout << "Heroes: "; heroes.inorder(heroes.root); cout << "\n";
        cout << "Enemies: "; enemies.inorder(enemies.root); cout << "\n";

        // Hero attacks
        Node* heroFront = heroes.minNode(heroes.root);
        Node* enemyFront = enemies.minNode(enemies.root);

        int dmg = damage(heroFront->c->attack);
        enemyFront->c->hp -= dmg;
        cout << heroFront->c->name << " attacks " << enemyFront->c->name << " for " << dmg << " damage.\n";

        if (enemyFront->c->hp <= 0) {
            cout << enemyFront->c->name << " is defeated!\n";
            enemies.root = enemies.deleteNode(enemies.root, enemyFront->c->name);
        }

        if (enemies.isEmpty()) break;

        // Enemy attacks 
        heroFront = heroes.minNode(heroes.root);
        enemyFront = enemies.minNode(enemies.root);

        dmg = damage(enemyFront->c->attack);
        heroFront->c->hp -= dmg;
        cout << enemyFront->c->name << " attacks " << heroFront->c->name << " for " << dmg << " damage.\n";

        if (heroFront->c->hp <= 0) {
            cout << heroFront->c->name << " is defeated!\n";
            heroes.root = heroes.deleteNode(heroes.root, heroFront->c->name);
        }
    }
    if (heroes.isEmpty()) cout << "Enemies win the battle!"<<endl;
    else cout << "Heroes win the battle!"<<endl;

    return 0;
}
