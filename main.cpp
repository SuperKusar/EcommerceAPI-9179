Добре, ось основний код, який робить обробку даних, включаючи введення, сортування, пошук, редагування й видалення.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

// Definition of the Data structure
struct Data {
    std::string name;
    int score;

    // Comparator for sorting
    bool operator<(const Data& rhs) const {
        return name < rhs.name;
    }
};

// Function to find a data in the vector
std::vector<Data>::iterator findData(std::vector<Data> &data, const std::string &name) {
    for (auto it = data.begin(); it != data.end(); ++it) {
        if (it->name == name) 
            return it;
    }
    return data.end();
}

// Function to add data to the vector
void addData(std::vector<Data> &data, const std::string &name, int score) {
    data.push_back({name, score});
}

// Function to delete data from the vector
void deleteData(std::vector<Data> &data, const std::string &name) {
    auto it = findData(data, name);
    if (it != data.end()) 
        data.erase(it);
}

// Function to edit data in the vector
void editData(std::vector<Data> &data, const std::string &name, int newScore) {
    auto it = findData(data, name);
    if (it != data.end()) 
        it->score = newScore;
}

// Function to print the data
void printData(const std::vector<Data> &data) {
    for (const auto &d : data) {
        std::cout << "Name: " << d.name << ", Score: " << d.score << std::endl;
    }
}

// Function to sort the data
void sortData(std::vector<Data> &data) {
    std::sort(data.begin(), data.end());
}

int main() {
    std::vector<Data> data;

    addData(data, "Alice", 90);
    addData(data, "Bob", 85);
    addData(data, "Charlie", 92);

    std::cout << "Initial data:" << std::endl;
    printData(data);

    sortData(data);
    std::cout << "\nSorted data:" << std::endl;
    printData(data);

    editData(data, "Bob", 88);
    std::cout << "\nAfter editing Bob's score:" << std::endl;
    printData(data);

    deleteData(data, "Alice");
    std::cout << "\nAfter deleting Alice:" << std::endl;
    printData(data);

    return 0;
}
```

Цей код створює просту структуру даних з іменем та оцінкою. Він має функції для додавання, видалення, редагування, пошуку, сортування та друку цих даних. У функції `main()` демонструється використання цих функцій.