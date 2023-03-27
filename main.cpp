#include <iostream>
#include <string>
#include <memory>

// Описание структуры Node с полями типа string, int, double
struct Node {
std::string name;
int integer;
double floating_point;

std::shared_ptr<Node> next;

Node(const std::string& name, int integer, double floating_point) :
name(name), integer(integer), floating_point(floating_point), next(nullptr) {}
};

// Описание класса LinkedList для работы со списком на базе структуры Node
class LinkedList {
public:
// Конструктор класса, инициализирует пустой список
LinkedList() : head(nullptr), tail(nullptr) {}

// Функция добавления элемента в начало списка
void add_to_beginning(const std::string& name, int integer, double floating_point) {
std::shared_ptr<Node> new_node = std::make_shared<Node>(name, integer, floating_point);
new_node->next = head;
head = new_node;
if (tail == nullptr) {
tail = head;
}
}

// Функция добавления элемента в конец списка
void add_to_end(const std::string& name, int integer, double floating_point) {
std::shared_ptr<Node> new_node = std::make_shared<Node>(name, integer, floating_point);
if (tail != nullptr) {
tail->next = new_node;
}
tail = new_node;
if (head == nullptr) {
head = tail;
}
}

// Функция добавления элемента после заданного элемента с именем target_name
void add_after(const std::string& target_name, const std::string& name, int integer, double floating_point) {
std::shared_ptr<Node> current = head;
while (current != nullptr && current->name != target_name) {
current = current->next;
}
if (current == nullptr) {
return;
}
std::shared_ptr<Node> new_node = std::make_shared<Node>(name, integer, floating_point);
new_node->next = current->next;
current->next = new_node;
if (tail == current) {
tail = new_node;
}
}

// Функция добавления элемента перед заданным элементом с именем target_name
void add_before(const std::string& target_name, const std::string& name, int integer, double floating_point) {
if (head == nullptr || head->name == target_name) {
add_to_beginning(name, integer, floating_point);
return;
}
std::shared_ptr<Node> current = head;
while (current->next != nullptr && current->next->name != target_name) {
current = current->next;
}
if (current->next == nullptr) {
return;
}
std::shared_ptr<Node> new_node = std::make_shared<Node>(name, integer, floating_point);
new_node->next = current->next;
current->next = new_node;
}

// Функция удаления элемента с заданным именем name
void remove(const std::string& name) {
if (head == nullptr) {
return;
}
if (head->name == name) {
head = head->next;
if (head == nullptr) {
tail = nullptr;
}
return;
}
std::shared_ptr<Node> current = head;
while (current->next != nullptr && current->next->name != name) {
current = current->next;
}
if (current->next == nullptr) {
return;
}
current->next = current->next->next;
if (current->next == nullptr) {
tail = current;
}
}

// Функция вывода содержания списка на экран
void display() const {
std::shared_ptr<Node> current = head;
while (current != nullptr) {
std::cout << "Name: " << current->name << ", Integer: " << current->integer << ", Double: " << current->floating_point << std::endl;
current = current->next;
}
}

private:
std::shared_ptr<Node> head;
std::shared_ptr<Node> tail;
};
// Функция, содержащая сценарий работы со списком с использованием разработанного инструментария
void test_scenario() {
LinkedList list;

// Добавление элементов в начало и конец списка
list.add_to_beginning("A", 1, 1.1);
list.add_to_end("C", 3, 3.3);
list.add_to_beginning("B", 2, 2.2);

// Добавление элементов после и перед заданным элементом
list.add_after("A", "D", 4, 4.4);
list.add_before("D", "E", 5, 5.5);

// Вывод содержания списка на экран
list.display();

// Удаление элемента с заданным именем
list.remove("D");

// Вывод содержания списка на экран
list.display();
}
int main() {
test_scenario();
return 0;
}
