#include "Bureaucrat.hpp"

int main(void)
{
	/* ============================================================
	   BLOC 1
	   Test du constructeur par défaut + limites autour de 150
	   ============================================================ */
	{
		// Affichage juste pour indiquer ce qu’on fait (couleur bleue)
		std::cout << "\033[34mConstructing\033[0m" << std::endl;

		// Création d’un Bureaucrat avec le constructeur par défaut
		// → name = "Default"
		// → grade = 150 (le pire grade autorisé)
		Bureaucrat *a = new Bureaucrat();
		std::cout << std::endl;

		// On affiche l’état actuel du bureaucrate
		std::cout << "\033[34mTesting\033[0m" << std::endl;
		std::cout << *a;

		// On essaie d’AMÉLIORER le grade (150 -> 149)
		// Ça doit marcher
		try
		{
			a->incrementGrade();
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			// Si une exception arrive, on affiche l’erreur
			std::cerr << "\033[33mIncrementing grade of " << a->getName()
				<< " failed: " << e.what() << "\033[0m" << std::endl;
		}
		// On affiche le grade après la tentative
		std::cout << *a;

		// On essaie de BAISSER le grade (149 -> 150)
		// Ça doit marcher
		try
		{
			a->decrementGrade();
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "\033[33mDecrementing grade of " << a->getName()
				<< " failed: " << e.what() << "\033[0m" << std::endl;
		}
		std::cout << *a;

		// On essaie encore de BAISSER le grade (150 -> 151)
		// ❌ Interdit → exception attendue
		try
		{
			a->decrementGrade();
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "\033[33mDecrementing grade of " << a->getName()
				<< " failed: " << e.what() << "\033[0m" << std::endl;
		}

		// Le grade doit être RESTÉ à 150
		std::cout << *a << std::endl;

		// Destruction de l’objet
		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
		delete a;
		std::cout << std::endl;
	}

	std::cout << "-------------------------------------------------------" << std::endl;

	/* ============================================================
	   BLOC 2
	   Test des limites autour de 1 (meilleur grade)
	   ============================================================ */
	{
		std::cout << std::endl;
		std::cout << "\033[34mConstructing\033[0m" << std::endl;

		// Création d’un Bureaucrat avec le meilleur grade possible
		Bureaucrat *a = new Bureaucrat(1);
		std::cout << std::endl;

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		std::cout << *a;

		// On baisse le grade (1 -> 2) → autorisé
		try
		{
			a->decrementGrade();
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "\033[33mDecrementing grade of " << a->getName()
				<< " failed: " << e.what() << "\033[0m" << std::endl;
		}
		std::cout << *a;

		// On remonte le grade (2 -> 1) → autorisé
		try
		{
			a->incrementGrade();
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << "\033[33mIncrementing grade of " << a->getName()
				<< " failed: " << e.what() << "\033[0m" << std::endl;
		}
		std::cout << *a;

		// On essaie encore de monter (1 -> 0)
		// ❌ Interdit → exception attendue
		try
		{
			a->incrementGrade();
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << "\033[33mIncrementing grade of " << a->getName()
				<< " failed: " << e.what() << "\033[0m" << std::endl;
		}

		std::cout << *a << std::endl;

		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
		delete a;
		std::cout << std::endl;
	}

	std::cout << "-------------------------------------------------------" << std::endl;

	/* ============================================================
	   BLOC 3
	   Test constructeur avec grade interdit (< 1)
	   ============================================================ */
	{
		std::cout << std::endl;
		std::cout << "\033[34mConstructing\033[0m" << std::endl;

		// Pointeur initialisé à NULL
		Bureaucrat *a = NULL;

		// On essaie de créer un Bureaucrat avec un grade interdit (0)
		try
		{
			a = new Bureaucrat(0);
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			// L’exception est NORMALE ici
			std::cerr << "\033[33mConstructing default failed: "
				<< e.what() << "\033[0m" << std::endl;
		}

		// Si l’objet n’a pas été créé, on ne delete pas
		if (a != NULL)
		{
			std::cout << "\033[34mDeconstructing a\033[0m" << std::endl;
			delete a;
		}
		std::cout << std::endl;
	}

	std::cout << "-------------------------------------------------------" << std::endl;

	/* ============================================================
	   BLOC 4
	   Test constructeur avec grade interdit (> 150)
	   ============================================================ */
	{
		std::cout << std::endl;
		std::cout << "\033[34mConstructing\033[0m" << std::endl;

		Bureaucrat *a = NULL;

		// On essaie de créer un Bureaucrat avec un grade interdit (160)
		try
		{
			a = new Bureaucrat(160);
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "\033[33mConstructing default failed: "
				<< e.what() << "\033[0m" << std::endl;
		}

		if (a != NULL)
		{
			std::cout << "\033[34mDeconstructing a\033[0m" << std::endl;
			delete a;
		}
		std::cout << std::endl;
	}

	std::cout << "-------------------------------------------------------" << std::endl;

	/* ============================================================
	   BLOC 5
	   Test constructeur avec nom + copie
	   ============================================================ */
	{
		std::cout << std::endl;
		std::cout << "\033[34mConstructing\033[0m" << std::endl;

		// Création normale
		Bureaucrat *a = new Bureaucrat("Peter", 120);
		std::cout << std::endl;

		std::cout << "\033[34mTesting a\033[0m" << std::endl;
		std::cout << *a;

		// Modification du grade
		a->decrementGrade();
		std::cout << *a << std::endl;

		// Création d’un NOUVEL objet par copie
		std::cout << "\033[34mConstructing b\033[0m" << std::endl;
		Bureaucrat *b = new Bureaucrat(*a);
		std::cout << std::endl;

		// On détruit a
		std::cout << "\033[34mDeconstructing a\033[0m" << std::endl;
		delete a;
		std::cout << std::endl;

		// b doit toujours fonctionner (copie indépendante)
		std::cout << "\033[34mTesting b\033[0m" << std::endl;
		std::cout << *b;
		b->decrementGrade();
		std::cout << *b << std::endl;

		std::cout << "\033[34mDeconstructing b\033[0m" << std::endl;
		delete b;
		std::cout << std::endl;
	}
}
