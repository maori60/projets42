#include "AForm.hpp"
#include "Bureaucrat.hpp"

static void	checkFormGrades(int signGrade, int execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(void)
	: _name("Default"), _is_signed(false), _sign_grade(150), _exec_grade(150)
{
}

AForm::AForm(const std::string &name, int sign_grade, int exec_grade)
	: _name(name), _is_signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	checkFormGrades(sign_grade, exec_grade);
}

AForm::AForm(const AForm &src)
	: _name(src._name), _is_signed(src._is_signed),
	  _sign_grade(src._sign_grade), _exec_grade(src._exec_grade)
{
}

AForm &AForm::operator=(const AForm &src)
{
	if (this != &src)
	{
		// _name, _sign_grade, _exec_grade sont const -> non assignables
		_is_signed = src._is_signed;
	}
	return *this;
}

AForm::~AForm(void)
{
}

const std::string	&AForm::getName(void) const
{
	return _name;
}

bool	AForm::getIsSigned(void) const
{
	return _is_signed;
}

int		AForm::getSignGrade(void) const
{
	return _sign_grade;
}

int		AForm::getExecGrade(void) const
{
	return _exec_grade;
}

void	AForm::beSigned(Bureaucrat const &signer)
{
	if (signer.getGrade() > _sign_grade)
		throw AForm::GradeTooLowException();
	_is_signed = true;
}

void	AForm::execute(Bureaucrat const &executor) const
{
	if (!_is_signed)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > _exec_grade)
		throw AForm::GradeTooLowException();
	executeAction();
}

const char	*AForm::GradeTooLowException::what(void) const throw()
{
	return "AForm grade too low";
}

const char	*AForm::GradeTooHighException::what(void) const throw()
{
	return "AForm grade too high";
}

const char	*AForm::FormNotSignedException::what(void) const throw()
{
	return "AForm not signed";
}

std::ostream	&operator<<(std::ostream &o, const AForm &f)
{
	o << f.getName()
	  << " (sign grade " << f.getSignGrade()
	  << ", exec grade " << f.getExecGrade()
	  << ", signed: " << (f.getIsSigned() ? "yes" : "no") << ")";
	return o;
}
