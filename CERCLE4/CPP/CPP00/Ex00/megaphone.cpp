#include <iostream>

int main(int argc, char *argv[])
{
    int j = 1; // Commence à argv[1] (argv[0] est le nom du programme)
    
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    }
    else
    {
        while (j < argc) // Parcourt tous les arguments
        {
            int i = 0;
            while (argv[j][i]) // Parcourt chaque caractère de l'argument actuel
            {
                if (argv[j][i] >= 'a' && argv[j][i] <= 'z')
                    argv[j][i] = argv[j][i] - 32; // Convertit en majuscule
                
                std::cout.write(&argv[j][i], 1);
                i++;
            }
            
            // if (j < argc - 1) // Ajoute un espace entre les arguments (évite un espace à la fin)
            //     std::cout << " ";
            
            j++; // Passe à l'argument suivant
        }
    }

    std::cout << std::endl;
    return 0;
}
