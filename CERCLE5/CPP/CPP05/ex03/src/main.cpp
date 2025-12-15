#include <iostream>
#include <string>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

static void	header(const std::string &title)
{
	std::cout << "\n============================================================\n";
	std::cout << title << "\n";
	std::cout << "============================================================\n";
}

static void	rule(const std::string &r, const std::string &expected)
{
	std::cout << "RULE     : " << r << "\n";
	std::cout << "EXPECTED : " << expected << "\n";
	std::cout << "------------------------------------------------------------\n";
}

static void	state(const Bureaucrat &b, const AForm &f)
{
	std::cout << "STATE -> " << b << "\n";
	std::cout << "STATE -> " << f << "\n";
}

static void	step(int n, const std::string &msg)
{
	std::cout << "\n[" << n << "] " << msg << "\n";
}

static void	printFormOrNull(AForm *f)
{
	if (f)
		std::cout << "FORM  -> " << *f << "\n";
	else
		std::cout << "FORM  -> NULL\n";
}

int	main(void)
{
	/* ============================================================
	   TEST 1 - SIGNATURE REFUSED (grade too low)
	   Goal: show Bureaucrat cannot sign if grade is too low
	   ============================================================ */
	header("TEST 1 - SIGNATURE REFUSED (grade too low)");
	rule("to sign: bureaucrat grade must be <= form sign grade",
		 "signForm fails and prints an explicit error");
	{
		Bureaucrat				low("Default", 150);
		PresidentialPardonForm	pardon("target_1");

		state(low, pardon);

		step(1, "Try to sign PresidentialPardonForm with grade=150 (should fail: 150 > 25)");
		low.signForm(pardon);

		std::cout << "\nFINAL STATE\n";
		std::cout << "STATE -> " << pardon << "\n";
	}

	/* ============================================================
	   TEST 2 - EXECUTION RULES (not signed + grade checks)
	   Goal: show execute requires signed form + sufficient executor grade
	   ============================================================ */
	header("TEST 2 - EXECUTION RULES (not signed / grade checks)");
	rule("to execute: form must be signed AND executor grade must be <= exec grade",
		 "executeForm fails if not signed OR grade too low; succeeds otherwise");
	{
		Bureaucrat				assistant("Assistant", 145);
		Bureaucrat				ceo("CEO", 1);
		PresidentialPardonForm	pardon("target_2");

		state(assistant, pardon);
		state(ceo, pardon);

		step(1, "Execute BEFORE signing (should fail: not signed)");
		ceo.executeForm(pardon);

		step(2, "Assistant tries to SIGN (should fail: 145 > 25)");
		assistant.signForm(pardon);

		step(3, "CEO SIGNS (should succeed: 1 <= 25)");
		ceo.signForm(pardon);
		std::cout << "STATE -> " << pardon << "\n";

		step(4, "Assistant tries to EXECUTE (should fail: 145 > 5)");
		assistant.executeForm(pardon);

		step(5, "CEO EXECUTES (should succeed: 1 <= 5)");
		ceo.executeForm(pardon);

		std::cout << "\nFINAL STATE\n";
		std::cout << "STATE -> " << pardon << "\n";
	}

	/* ============================================================
	   TEST 3 - COPY CONSTRUCTOR (canonical behavior)
	   Goal: show copied form is still valid and can be used
	   ============================================================ */
	header("TEST 3 - COPY CONSTRUCTOR (canonical behavior)");
	rule("a copied form remains usable (same grades, signed state initially copied)",
		 "both original and copy can be signed then executed");
	{
		Bureaucrat				emperor("Emperor", 1);
		PresidentialPardonForm	original("target_3");
		PresidentialPardonForm	copy(original);

		state(emperor, original);
		state(emperor, copy);

		step(1, "Sign BOTH forms");
		emperor.signForm(original);
		emperor.signForm(copy);

		step(2, "Execute BOTH forms");
		emperor.executeForm(original);
		emperor.executeForm(copy);
	}

	/* ============================================================
	   TEST 4 - POLYMORPHISM (Robotomy + Shrubbery)
	   Goal: show executeForm calls the correct derived behavior (virtual execute)
	   ============================================================ */
	header("TEST 4 - POLYMORPHISM (Robotomy + Shrubbery)");
	rule("executeForm triggers AForm::execute() (checks) then derived form behavior (virtual dispatch)",
		 "Robotomy: drilling + random 50/50, Shrubbery: creates <target>_shrubbery file");
	{
		Bureaucrat				emperor("Emperor", 1);
		RobotomyRequestForm		robot("Bender");
		ShrubberyCreationForm	tree("christmas");

		state(emperor, robot);
		state(emperor, tree);

		step(1, "Sign BOTH forms");
		emperor.signForm(robot);
		emperor.signForm(tree);

		step(2, "Execute Robotomy 10 times (random success/failure)");
		const int attempts = 10;
		for (int i = 1; i <= attempts; i++)
		{
			std::cout << "\n--- Robotomy attempt " << i << " ---\n";
			emperor.executeForm(robot);
		}

		step(3, "Execute Shrubbery (creates 'christmas_shrubbery')");
		emperor.executeForm(tree);
	}

	/* ============================================================
	   TEST 5 - INTERN (factory dispatch + unknown form)
	   Goal: show Intern can create the right form type or return NULL
	   ============================================================ */
	header("TEST 5 - INTERN (factory dispatch + unknown form)");
	rule("Intern::makeForm(name, target) returns a new concrete AForm* or NULL if unknown",
		 "valid names create correct types; unknown name => NULL");
	{
		Intern		intern;
		Bureaucrat	boss("Boss", 1);
		Bureaucrat	peon("Peon", 150);

		step(1, "REQUEST -> name=\"shrubbery creation\", target=\"home\"");
		AForm *f1 = intern.makeForm("shrubbery creation", "home");
		printFormOrNull(f1);
		if (f1)
		{
			peon.signForm(*f1);   // should fail (150 > 145)
			boss.signForm(*f1);   // should succeed
			boss.executeForm(*f1);
			delete f1;
		}

		step(2, "REQUEST -> name=\"robotomy request\", target=\"Bender\"");
		AForm *f2 = intern.makeForm("robotomy request", "Bender");
		printFormOrNull(f2);
		if (f2)
		{
			boss.signForm(*f2);
			boss.executeForm(*f2);
			delete f2;
		}

		step(3, "REQUEST -> name=\"presidential pardon\", target=\"Arthur Dent\"");
		AForm *f3 = intern.makeForm("presidential pardon", "Arthur Dent");
		printFormOrNull(f3);
		if (f3)
		{
			boss.signForm(*f3);
			boss.executeForm(*f3);
			delete f3;
		}

		step(4, "REQUEST -> name=\"coffee making\" (unknown), target=\"nobody\"");
		AForm *fx = intern.makeForm("coffee making", "nobody");
		printFormOrNull(fx);
		if (!fx)
			std::cout << "OK -> unknown form => NULL\n";
		else
		{
			std::cout << "ERROR -> should have returned NULL\n";
			delete fx;
		}
	}

	return (0);
}
