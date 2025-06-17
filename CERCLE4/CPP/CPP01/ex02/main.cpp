#include <iostream>
#include <string>

int main() {
    std::string brain = "HI THIS IS BRAIN";

    std::string* stringPTR = &brain;
    std::string& stringREF = brain;

    // Affichage des adresses
    std::cout << "Adresse de la string      : " << &brain << std::endl;
    std::cout << "Adresse via stringPTR     : " << stringPTR << std::endl;
    std::cout << "Adresse via stringREF     : " << &stringREF << std::endl;

    // Affichage des valeurs
    std::cout << "Valeur de la string       : " << brain << std::endl;
    std::cout << "Valeur pointée par stringPTR : " << *stringPTR << std::endl;
    std::cout << "Valeur via stringREF      : " << stringREF << std::endl;

    return 0;
}
