/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 20:00:26 by cgodecke          #+#    #+#             */
/*   Updated: 2025/12/10 20:20:30 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <list>
# include <deque>
# include <utility>
# include <algorithm>
# include <ctime>
# include <climits>
# include <cstdlib>
# include <cctype>
# include <string>
# include <iterator>

// Comparateur pour std::inplace_merge : compare le second élément (le plus grand du pair)
bool custom_cmp(const std::pair<int, int> &a, const std::pair<int, int> &b);

// Validation + affichage "Before"
void validate_input(char **argv);
void print_before(char **argv);

// === Version std::list ===
void create_pairs(std::list<std::pair<int, int> > *listy,
                  char **argv,
                  int *additional_value);
void sort_pairs(std::list<std::pair<int, int> > *listy);
void mergeSort(std::list<std::pair<int, int> >::iterator start,
               std::list<std::pair<int, int> >::iterator end,
               size_t size);
void init_main_chain(std::list<int> *main_chain,
                     std::list<std::pair<int, int> > listy);
void binary_search_insertion(std::list<int> *main_chain,
                             std::list<int>::iterator end,
                             int val);
void insert_into_main_chain(std::list<std::pair<int, int> > listy,
                            std::list<int> *main_chain,
                            int additional_value);
void print_after(const std::list<int> &main_chain);

// === Version std::deque ===
void create_pairs2(std::deque<std::pair<int, int> > *dequey,
                   char **argv,
                   int *additional_value);
void sort_pairs2(std::deque<std::pair<int, int> > *dequey);
void mergeSort2(std::deque<std::pair<int, int> >::iterator start,
                std::deque<std::pair<int, int> >::iterator end,
                size_t size);
void init_main_chain2(std::deque<int> *main_chain,
                      std::deque<std::pair<int, int> > dequey);
void binary_search_insertion2(std::deque<int> *main_chain,
                              std::deque<int>::iterator end,
                              int val);
void insert_into_main_chain2(std::deque<std::pair<int, int> > dequey,
                             std::deque<int> *main_chain,
                             int additional_value);
void print_after2(const std::deque<int> &main_chain);

#endif
