/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 20:00:26 by cgodecke          #+#    #+#             */
/*   Updated: 2025/12/10 20:20:38 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

////////////////////////// shared functions ///////////////////////////////////

// Comparateur pour inplace_merge : on trie sur le second élément du pair (le plus grand)
bool custom_cmp(const std::pair<int, int> &a, const std::pair<int, int> &b)
{
	return (a.second < b.second);
}

// Valide tous les arguments : entiers > 0, pas de signe, pas de caractère non numérique
void validate_input(char **argv)
{
	for (int i = 1; argv[i]; ++i)
	{
		std::string input = argv[i];
		if (input.empty())
			throw std::runtime_error("Error");

		for (size_t j = 0; j < input.size(); ++j)
		{
			if (!std::isdigit(static_cast<unsigned char>(input[j])))
				throw std::runtime_error("Error");
		}

		long value = std::atol(input.c_str());
		if (value <= 0 || value > INT_MAX)
			throw std::runtime_error("Error");
	}
}

void print_before(char **argv)
{
	std::cout << "Before: ";
	for (int i = 1; argv[i]; ++i)
		std::cout << argv[i] << " ";
	std::cout << "\n";
}

////////////////////////// List functions //////////////////////////////////////

void create_pairs(std::list<std::pair<int, int> > *listy,
                  char **argv,
                  int *additional_value)
{
	int i = 1;

	while (argv[i])
	{
		if (argv[i] && argv[i + 1])
		{
			std::pair<int, int> pair_temp(std::atoi(argv[i]),
			                              std::atoi(argv[i + 1]));
			listy->push_back(pair_temp);
			i += 2;
		}
		else
		{
			*additional_value = std::atoi(argv[i]);
			i++;
		}
	}
}

void sort_pairs(std::list<std::pair<int, int> > *listy)
{
	for (std::list<std::pair<int, int> >::iterator it = listy->begin();
	     it != listy->end(); ++it)
	{
		if (it->first > it->second)
		{
			int temp = it->first;
			it->first = it->second;
			it->second = temp;
		}
	}
}

// Merge sort récursif (sur liste de paires), puis inplace_merge avec custom_cmp
void mergeSort(std::list<std::pair<int, int> >::iterator start,
               std::list<std::pair<int, int> >::iterator end,
               size_t size)
{
	if (size == 0 && start != end)
		size = std::distance(start, end);
	if (size <= 1)
		return;

	size_t firstHalf = size / 2;
	size_t secondHalf = size - firstHalf;
	std::list<std::pair<int, int> >::iterator center = start;
	std::advance(center, firstHalf);

	mergeSort(start, center, firstHalf);
	mergeSort(center, end, secondHalf);
	std::inplace_merge(start, center, end, custom_cmp);
}

void init_main_chain(std::list<int> *main_chain,
                     std::list<std::pair<int, int> > listy)
{
	for (std::list<std::pair<int, int> >::iterator it = listy.begin();
	     it != listy.end(); ++it)
		main_chain->push_back(it->second);

	// Premier "pend" = premier élément de la première paire
	if (!listy.empty())
		main_chain->push_front(listy.begin()->first);
}

// insertion binaire dans une std::list via std::lower_bound
void binary_search_insertion(std::list<int> *main_chain,
                             std::list<int>::iterator end,
                             int val)
{
	std::list<int>::iterator place_to_insert =
	    std::lower_bound(main_chain->begin(), end, val);
	main_chain->insert(place_to_insert, val);
}

void insert_into_main_chain(std::list<std::pair<int, int> > listy,
                            std::list<int> *main_chain,
                            int additional_value)
{
	size_t Jacobsthal[] = {
		1, 3, 5, 11, 21, 43, 85, 171, 341, 683,
		1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763,
		349525, 699051, 1398101, 2796203, 5592405, 11184811,
		22369621, 44739243, 89478485, 178956971, 357913941,
		715827883, 1431655765
	};
	int jacobsthal_idx = 1;

	std::list<int>::iterator slice_delim_it;
	std::list<std::pair<int, int> >::iterator pair_it;
	std::list<std::pair<int, int> >::iterator last_jacob_it = listy.begin();

	while (jacobsthal_idx < 31 && Jacobsthal[jacobsthal_idx] <= listy.size())
	{
		pair_it = listy.begin();
		std::advance(pair_it, Jacobsthal[jacobsthal_idx] - 1);
		last_jacob_it = pair_it;

		int insertion_counter = 0;
		while (Jacobsthal[jacobsthal_idx] - insertion_counter >
		       Jacobsthal[jacobsthal_idx - 1])
		{
			slice_delim_it =
			    std::find(main_chain->begin(), main_chain->end(),
			              pair_it->second);
			binary_search_insertion(main_chain, slice_delim_it,
			                        pair_it->first);
			pair_it--;
			insertion_counter++;
		}
		jacobsthal_idx++;
	}

	// Insérer les pend restants
	if (Jacobsthal[jacobsthal_idx] != listy.size())
	{
		pair_it = listy.end();
		if (pair_it != listy.begin())
			pair_it--;
		while (pair_it != last_jacob_it)
		{
			slice_delim_it =
			    std::find(main_chain->begin(), main_chain->end(),
			              pair_it->second);
			binary_search_insertion(main_chain, slice_delim_it,
			                        pair_it->first);
			pair_it--;
		}
	}

	// Si nombre supplémentaire (nombre impair d'arguments)
	if (additional_value != -1)
	{
		binary_search_insertion(main_chain, main_chain->end(), additional_value);
	}
}

void print_after(const std::list<int> &main_chain)
{
	std::cout << "After: ";
	for (std::list<int>::const_iterator it = main_chain.begin();
	     it != main_chain.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << '\n';
}

////////////////////////// Deque functions /////////////////////////////////////

void create_pairs2(std::deque<std::pair<int, int> > *dequey,
                   char **argv,
                   int *additional_value)
{
	int i = 1;

	while (argv[i])
	{
		if (argv[i] && argv[i + 1])
		{
			std::pair<int, int> pair_temp(std::atoi(argv[i]),
			                              std::atoi(argv[i + 1]));
			dequey->push_back(pair_temp);
			i += 2;
		}
		else
		{
			*additional_value = std::atoi(argv[i]);
			i++;
		}
	}
}

void sort_pairs2(std::deque<std::pair<int, int> > *dequey)
{
	for (std::deque<std::pair<int, int> >::iterator it = dequey->begin();
	     it != dequey->end(); ++it)
	{
		if (it->first > it->second)
		{
			int temp = it->first;
			it->first = it->second;
			it->second = temp;
		}
	}
}

void mergeSort2(std::deque<std::pair<int, int> >::iterator start,
                std::deque<std::pair<int, int> >::iterator end,
                size_t size)
{
	if (size == 0 && start != end)
		size = std::distance(start, end);
	if (size <= 1)
		return;

	size_t firstHalf = size / 2;
	size_t secondHalf = size - firstHalf;
	std::deque<std::pair<int, int> >::iterator center = start + firstHalf;

	mergeSort2(start, center, firstHalf);
	mergeSort2(center, end, secondHalf);
	std::inplace_merge(start, center, end, custom_cmp);
}

void init_main_chain2(std::deque<int> *main_chain,
                      std::deque<std::pair<int, int> > dequey)
{
	for (std::deque<std::pair<int, int> >::iterator it = dequey.begin();
	     it != dequey.end(); ++it)
		main_chain->push_back(it->second);
	if (!dequey.empty())
		main_chain->push_front(dequey.begin()->first);
}

void binary_search_insertion2(std::deque<int> *main_chain,
                              std::deque<int>::iterator end,
                              int val)
{
	std::deque<int>::iterator place_to_insert =
	    std::lower_bound(main_chain->begin(), end, val);
	main_chain->insert(place_to_insert, val);
}

void insert_into_main_chain2(std::deque<std::pair<int, int> > dequey,
                             std::deque<int> *main_chain,
                             int additional_value)
{
	size_t Jacobsthal[] = {
		1, 3, 5, 11, 21, 43, 85, 171, 341, 683,
		1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763,
		349525, 699051, 1398101, 2796203, 5592405, 11184811,
		22369621, 44739243, 89478485, 178956971, 357913941,
		715827883, 1431655765
	};
	int jacobsthal_idx = 1;

	std::deque<int>::iterator slice_delim_it;
	std::deque<std::pair<int, int> >::iterator pair_it;
	std::deque<std::pair<int, int> >::iterator last_jacob_it = dequey.begin();

	while (jacobsthal_idx < 31 && Jacobsthal[jacobsthal_idx] <= dequey.size())
	{
		pair_it = dequey.begin() + (Jacobsthal[jacobsthal_idx] - 1);
		last_jacob_it = pair_it;

		int insertion_counter = 0;
		while (Jacobsthal[jacobsthal_idx] - insertion_counter >
		       Jacobsthal[jacobsthal_idx - 1])
		{
			slice_delim_it =
			    std::find(main_chain->begin(), main_chain->end(),
			              pair_it->second);
			binary_search_insertion2(main_chain, slice_delim_it,
			                         pair_it->first);
			pair_it--;
			insertion_counter++;
		}
		jacobsthal_idx++;
	}

	if (Jacobsthal[jacobsthal_idx] != dequey.size())
	{
		pair_it = dequey.end();
		if (pair_it != dequey.begin())
			pair_it--;
		while (pair_it != last_jacob_it)
		{
			slice_delim_it =
			    std::find(main_chain->begin(), main_chain->end(),
			              pair_it->second);
			binary_search_insertion2(main_chain, slice_delim_it,
			                         pair_it->first);
			pair_it--;
		}
	}

	if (additional_value != -1)
	{
		binary_search_insertion2(main_chain, main_chain->end(),
		                         additional_value);
	}
}

void print_after2(const std::deque<int> &main_chain)
{
	std::cout << "After: ";
	for (std::deque<int>::const_iterator it = main_chain.begin();
	     it != main_chain.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << '\n';
}

/*
	Le gros commentaire explicatif de ton algo Ford–Johnson peut rester ici
	si tu veux le garder pour la soutenance/documentation.
*/
