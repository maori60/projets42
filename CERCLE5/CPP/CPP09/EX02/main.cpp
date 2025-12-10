/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 20:00:09 by cgodecke          #+#    #+#             */
/*   Updated: 2025/12/10 20:20:54 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	try
	{
		// 1) Valider les entrées (sans rien afficher)
		validate_input(argv);

		// 2) Afficher la séquence initiale une seule fois
		print_before(argv);

		// ===================== std::list =====================
		std::list< std::pair<int, int> > listy;
		std::list<int> main_chain_list;
		int additional_value_list = -1;

		clock_t start_list = clock();
		create_pairs(&listy, argv, &additional_value_list);
		sort_pairs(&listy);
		mergeSort(listy.begin(), listy.end(), 0);
		init_main_chain(&main_chain_list, listy);
		insert_into_main_chain(listy, &main_chain_list, additional_value_list);
		clock_t end_list = clock();

		// 3) Afficher la séquence triée (à partir de la liste)
		print_after(main_chain_list);

		double time_list_us =
		    static_cast<double>(end_list - start_list) * 1e6 / CLOCKS_PER_SEC;
		size_t count = main_chain_list.size();

		// ===================== std::deque =====================
		std::deque< std::pair<int, int> > dequey;
		std::deque<int> main_chain_deque;
		int additional_value_deque = -1;

		clock_t start_deque = clock();
		create_pairs2(&dequey, argv, &additional_value_deque);
		sort_pairs2(&dequey);
		mergeSort2(dequey.begin(), dequey.end(), 0);
		init_main_chain2(&main_chain_deque, dequey);
		insert_into_main_chain2(dequey, &main_chain_deque,
		                        additional_value_deque);
		clock_t end_deque = clock();

		double time_deque_us =
		    static_cast<double>(end_deque - start_deque) * 1e6 / CLOCKS_PER_SEC;

		// 4) Afficher les temps comme dans le sujet (avec std::[..])
		std::cout << "Time to process a range of " << count
		          << " elements with std::list : "
		          << time_list_us << " us" << std::endl;
		std::cout << "Time to process a range of " << count
		          << " elements with std::deque : "
		          << time_deque_us << " us" << std::endl;
	}
	catch (const std::exception &)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}
	return 0;
}
