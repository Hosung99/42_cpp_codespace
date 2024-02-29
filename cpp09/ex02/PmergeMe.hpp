/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:53:53 by Sungho            #+#    #+#             */
/*   Updated: 2024/02/29 13:24:08 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <deque>
#include <utility>

class PmergeMe
{
private:
	std::deque<std::pair<int, int> > deq_pair;
	std::vector<std::pair<int, int> > vec_pair;
	std::vector<int> vec;
	std::vector<int> vec_temp;
	std::deque<int> deq;
	std::vector<int> main_chain_vec;
	std::deque<int> main_chain_deq;
	std::vector<int> pending_chain_vec;
	std::deque<int> pending_chain_deq;
	std::vector<int> jacobsthal_vec;
	std::deque<int> jacobsthal_deq;
	std::vector<int> jacobsthal_index_vec;
	std::deque<int> jacobsthal_index_deq;
	double time_taken_vec;
	double time_taken_deq;
	PmergeMe();
	PmergeMe(const PmergeMe &);
	PmergeMe &operator=(const PmergeMe &);
	void merge_insert_sort_vec();
	void merge_insert_sort_deque();
	void make_pair_deq();
	void sort_pair_deq();
	void make_pair_vec();
	void sort_pair_vec();
	void merge_sort_vec(int, int);
	void merge_sort_deq(int, int);
	void merge_vec(int, int, int);
	void merge_deq(int, int, int);
	void set_chain_vec();
	void set_chain_deq();
	int jacobsthal(int);
	void set_jacobsthal_vec();
	void set_jacobsthal_deq();
	void sort_main_chain_vec();
	void sort_main_chain_deq();
	int binary_search_vec(int);
	int binary_search_deq(int);
	void check_dup();
public:
	~PmergeMe();
	PmergeMe(int, char **);
};

#endif