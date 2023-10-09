#include <iostream>
#include <string>

class Animal {
public:
    Animal (const std::string& name, double weight, const std::string& species, const std::string& birthday)
        : name(name), weight(weight), species(species), birthday(birthday), age (0) {}

         // Increment age.
         virtual void incrementAge() {
         age++;

}

 // Display Animal information
 void displayInfo() const {
      std::cout <<"Name: " << name << std::endl;
      std::cout <<"Species: " << species << std::endl;
      std::cout <<"Weight: " << weight << " kg" << std::endl;
      std::cout <<"Birthday: " << birthday << std::endl;
      std::cout <<"Age: " << age << " years" << std::endl;
      std::cout << std::endl;
 }

std:: string getName() const {
    return name;

}

double getWeight() const {
    return weight;

}

std::string getSpecies() const {
     return species;

}

std::string getBirthday() const {
    return birthday;

}

int getAge() const {
    return age;

}

private:
    std::string name;
    double weight;
    std::string species;
    std::string birthday;
    int age;

};

class AnimalLinkedList {
private:
    struct Node {
    Animal* data;
    Node* next;

    Node(Animal* animal) : data(animal), next(nullptr) {}

};

public:
    AnimalLinkedList() : head(nullptr) {}

    //Add an Animal to the Linked List
    void addAnimal(Animal* animal) {
    if (!head) {
       head = newNode;
        } else {
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
    }


    //Display information of All Animals in the linked list
    void displayAllAnimalsInfo() const {
        Node* current = head;
        while (current) {
            current->data->displayInfo();
            current = current->next;
        }
    }


    // Find and Display information of a specific animal by Name
    void displayAnimalInfoByName(const std::string& name) const {
    Node* current = head;
    bool found = false;
    while (current) {
        if (current->data->getName() == name) {
            current->data->displayInfo();
            found = true;
            break;
        }
        current = current->next;
    }
    if (!found) {
        std::cout << "Animal with name '" << name "' not found." << std::endl;
    }
}

// Destructor to free memory
~AnimalLinkedList() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current->data;
        delete current;
        current = next;
    }
}

private:
    Node* head;
};


int main() {
    AnimalLinkedList animalList;

    // Create Animals and add them to the Linked List
    Animal* lion1 = new Animal("Simba", 200, "03/23/2001");
    Animal* lion2 = new Animal("Nala", 173, "02/02/2003");
    Animal* lion3 = new Animal("Mufasa", 230, "08/14/1996");
    Animal* lion4 = new Animal("Scar", 220, "11/08/1994");

    Animal* tiger1 = new Animal("Rajah", 180, "04/21/1977");
    Animal* tiger2 = new Animal("Shere Khan", 220, "07/29/1972");
    Animal* tiger3 = new Animal("Bagheera", 209, "01/11/1973");
    Animal* tiger4 = new Animal("Tony", 200, "12/02/1970");

    Animal* bear1 = new Animal("Baloo", 356, "05/29/1990");
    Animal* bear2 = new Animal("Smokey", 342, "03/16/1989");
    Animal* bear3 = new Animal("Yogi", 316, "09/20/1995");
    Animal* bear4 = new Animal("Paddington", 326, "01/05/1997");

    Animal* hyens1 = new Animal("Ed", 90, "01/23/1991");
    Animal* hyens2 = new Animal("Shenzi", 86, "07/17/1994");
    Animal* hyens3 = new Animal("Banzai", 84, "06/09/1993");
    Animal* hyens4 = new Animal("Kamari", 87, "12/01/1992");

    // Add animals to the Linked List
    animalList.addAnimal(&lion1);
    animalList.addAnimal(&lion2);
    animalList.addAnimal(&lion3);
    animalList.addAnimal(&lion4);
    animalList.addAnimal(&tiger1);
    animalList.addAnimal(&tiger2);
    animalList.addAnimal(&tiger3);
    animalList.addAnimal(&tiger4);
    animalList.addAnimal(&bear1);
    animalList.addAnimal(&bear2);
    animalList.addAnimal(&bear3);
    animalList.addAnimal(&bear4);
    animalList.addAnimal(&hyena1);
    animalList.addAnimal(&hyena2);
    animalList.addAnimal(&hyena3);
    animalList.addAnimal(&hyena4);

    //Display option and allow the user to select an animal by name
    while (true) {
        std::cout << "Choose an animal to display ( or type 'quit' to exit): ";
        std::string input;
        std::cin >> input;

        if (input == "quit") {
            break;
        } else {
            animalList.displayAnimalInfoByName(input);
        }
    }

    // Clean up memory by deleting dynamically allocated animals
    delete lion1;
    delete lion2;
    delete lion3;
    delete lion4;
    delete tiger1;
    delete tiger2;
    delete tiger3;
    delete tiger4;
    delete bear1;
    delete bear2;
    delete bear3;
    delete bear4;
    delete hyena1;
    delete hyena2;
    delete hyena3;
    delete hyena4;



};
    return 0;
}

