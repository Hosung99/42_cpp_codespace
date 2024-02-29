/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:17:33 by Sungho            #+#    #+#             */
/*   Updated: 2024/02/29 13:30:41 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		long long_temp = atol(argv[i]);
		std::string str(argv[i]);
		if (long_temp <= 0 || long_temp > 2147483647 || str.length() == 0)
			throw(std::logic_error("Error"));
		vec.push_back(static_cast<int>(long_temp));
		deq.push_back(static_cast<int>(long_temp));
	}
	vec_temp = vec;
	check_dup();
	std::cout << "Before: ";
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << "\n";
	merge_insert_sort_vec();
	merge_insert_sort_deque();
	std::cout << "After std::vector : ";
	for (size_t i = 0; i < main_chain_vec.size(); i++)
	{
		std::cout << main_chain_vec[i] << " ";
	}
	std::cout << "\nAfter std::deque : ";
	for (size_t i = 0; i < main_chain_deq.size(); i++)
	{
		std::cout << main_chain_deq[i] << " ";
	}
	std::cout << "\n";
	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << std::fixed << time_taken_vec << " us" << std::endl;
	std::cout << "Time to process a range of " << vec.size() << " elements with std::deque : " << std::fixed << time_taken_deq << " us" << std::endl;
}

void PmergeMe::merge_insert_sort_vec()
{
	std::clock_t start_t = clock();

	if (vec.size() == 1)
		main_chain_vec.push_back(vec[0]);
	else
	{
		make_pair_vec();
		sort_pair_vec();
		merge_sort_vec(0, vec_pair.size() - 1);
		set_chain_vec();
		set_jacobsthal_vec();
		sort_main_chain_vec();
	}
	std::clock_t end_t = clock();
	std::clock_t elapsed = end_t - start_t;
	this->time_taken_vec = ((double)elapsed / CLOCKS_PER_SEC);
}

void PmergeMe::make_pair_vec()
{
	int pair_cnt = this->vec.size() / 2;
	int index = 0;
	while (pair_cnt)
	{
		this->vec_pair.push_back(std::make_pair(this->vec[index], this->vec[index + 1]));
		index += 2;
		pair_cnt--;
	}
}

void PmergeMe::sort_pair_vec()
{
	size_t index = 0;
	int temp;
	while (index < vec_pair.size())
	{
		if (vec_pair[index].first < this->vec_pair[index].second)
		{
			temp = vec_pair[index].first;
			vec_pair[index].first = vec_pair[index].second;
			vec_pair[index].second = temp;
		}
		index++;
	}
}

void PmergeMe::merge_sort_vec(int begin, int end)
{
	if (begin >= end)
		return;
	int mid = (begin + end) / 2;
	merge_sort_vec(begin, mid);
	merge_sort_vec(mid + 1, end);
	merge_vec(begin, mid, end);
}

void PmergeMe::merge_vec(int begin, int mid, int end)
{
	std::vector<std::pair<int, int> > left(vec_pair.begin() + begin, vec_pair.begin() + mid + 1);
	std::vector<std::pair<int, int> > right(vec_pair.begin() + mid + 1, vec_pair.begin() + end + 1);

	size_t left_index = 0;
	size_t right_index = 0;
	size_t merged_index = begin;
	while (left_index < left.size() && right_index < right.size())
	{
		if (left[left_index].first <= right[right_index].first)
		{
			vec_pair[merged_index] = left[left_index];
			left_index++;
		}
		else
		{
			vec_pair[merged_index] = right[right_index];
			right_index++;
		}
		merged_index++;
	}
	while (left_index < left.size())
	{
		vec_pair[merged_index] = left[left_index];
		left_index++;
		merged_index++;
	}
	while (right_index < right.size())
	{
		vec_pair[merged_index] = right[right_index];
		right_index++;
		merged_index++;
	}
}

void PmergeMe::set_chain_vec()
{
	for (size_t i = 0; i < vec_pair.size(); i++)
	{
		main_chain_vec.push_back(vec_pair[i].first);
		pending_chain_vec.push_back(vec_pair[i].second);
	}
	// std::cout << "main chain :";
	// for (size_t i = 0; i < main_chain_vec.size(); i++)
	// {
	// 	std::cout << main_chain_vec[i] << " ";
	// }
	// std::cout << "\n";
	// std::cout << "pending chain :";
	// for (size_t i = 0; i < pending_chain_vec.size(); i++)
	// {
	// 	std::cout << pending_chain_vec[i] << " ";
	// }
}

int PmergeMe::jacobsthal(int index)
{
	if (index == 0)
		return 0;
	else if (index == 1)
		return 1;
	else
		return jacobsthal(index - 1) + 2 * jacobsthal(index - 2);
}

void PmergeMe::set_jacobsthal_vec()
{
	size_t jacobindex;
	int index = 1;
	while (1)
	{
		jacobindex = jacobsthal(index);
		if (jacobindex > pending_chain_vec.size() + 1)
			break;
		jacobsthal_vec.push_back(jacobindex);
		index++;
	}
	int start = 1;
	jacobsthal_index_vec.push_back(0);
	for (size_t i = 2; i < jacobsthal_vec.size(); i++)
	{
		start = jacobsthal_vec[i - 1];
		int end = jacobsthal_vec[i];
		for (int j = end; j > start; j--)
		{
			if (jacobsthal_index_vec.size() == pending_chain_vec.size())
				break;
			jacobsthal_index_vec.push_back(j - 1);
		}
		start = end + 1;
	}
	// std::cout << "\njacob: ";
	// for (size_t i = 0; i < jacobsthal_index_vec.size(); i++)
	// {
	// 	std::cout << jacobsthal_index_vec[i] << " ";
	// }
	// std::cout << "\n";
}

void PmergeMe::sort_main_chain_vec()
{
	size_t jacob_index = 0;
	while (jacob_index < jacobsthal_index_vec.size())
	{
		size_t temp = jacobsthal_index_vec[jacob_index];
		while (temp >= pending_chain_vec.size())
			temp--;
		int pos = binary_search_vec(pending_chain_vec[temp]);
		main_chain_vec.insert(main_chain_vec.begin() + pos, pending_chain_vec[temp]);
		jacob_index++;
	}
	if (vec.size() % 2 == 1)
	{
		int pos = binary_search_vec(vec[vec.size() - 1]);
		main_chain_vec.insert(main_chain_vec.begin() + pos, vec[vec.size() - 1]);
	}
}

int PmergeMe::binary_search_vec(int key)
{
	int left = 0;
	int right = main_chain_vec.size() - 1;
	int mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (key == main_chain_vec[mid])
			return mid;
		else if (key < main_chain_vec[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}
	if (key > main_chain_vec[mid])
		return mid + 1;
	else
		return mid;
}

void PmergeMe::merge_insert_sort_deque()
{
	std::clock_t start_t = clock();

	if (vec.size() == 1)
		main_chain_deq.push_back(deq[0]);
	else
	{
		make_pair_deq();
		sort_pair_deq();
		merge_sort_deq(0, deq_pair.size() - 1);
		set_chain_deq();
		set_jacobsthal_deq();
		sort_main_chain_deq();
	}
	std::clock_t end_t = clock();
	std::clock_t elapsed = end_t - start_t;
	this->time_taken_deq = ((double)elapsed / CLOCKS_PER_SEC);
}

void PmergeMe::make_pair_deq()
{
	int pair_cnt = this->deq.size() / 2;
	int index = 0;
	while (pair_cnt)
	{
		this->deq_pair.push_back(std::make_pair(this->deq[index], this->deq[index + 1]));
		index += 2;
		pair_cnt--;
	}
}

void PmergeMe::sort_pair_deq()
{
	size_t index = 0;
	int temp;
	while (index < deq_pair.size())
	{
		if (deq_pair[index].first < this->deq_pair[index].second)
		{
			temp = deq_pair[index].first;
			deq_pair[index].first = deq_pair[index].second;
			deq_pair[index].second = temp;
		}
		index++;
	}
}

void PmergeMe::merge_sort_deq(int begin, int end)
{
	if (begin >= end)
		return;
	int mid = (begin + end) / 2;
	merge_sort_deq(begin, mid);
	merge_sort_deq(mid + 1, end);
	merge_deq(begin, mid, end);
}

void PmergeMe::merge_deq(int begin, int mid, int end)
{
	std::deque<std::pair<int, int> > left(deq_pair.begin() + begin, deq_pair.begin() + mid + 1);
	std::deque<std::pair<int, int> > right(deq_pair.begin() + mid + 1, deq_pair.begin() + end + 1);

	size_t left_index = 0;
	size_t right_index = 0;
	size_t merged_index = begin;
	while (left_index < left.size() && right_index < right.size())
	{
		if (left[left_index].first <= right[right_index].first)
		{
			deq_pair[merged_index] = left[left_index];
			left_index++;
		}
		else
		{
			deq_pair[merged_index] = right[right_index];
			right_index++;
		}
		merged_index++;
	}
	while (left_index < left.size())
	{
		deq_pair[merged_index] = left[left_index];
		left_index++;
		merged_index++;
	}
	while (right_index < right.size())
	{
		deq_pair[merged_index] = right[right_index];
		right_index++;
		merged_index++;
	}
}

void PmergeMe::set_chain_deq()
{
	for (size_t i = 0; i < deq_pair.size(); i++)
	{
		main_chain_deq.push_back(deq_pair[i].first);
		pending_chain_deq.push_back(deq_pair[i].second);
	}
}

void PmergeMe::set_jacobsthal_deq()
{
	size_t jacobindex;
	int index = 1;
	while (1)
	{
		jacobindex = jacobsthal(index);
		if (jacobindex > pending_chain_deq.size() + 1)
			break;
		jacobsthal_deq.push_back(jacobindex);
		index++;
	}
	int start = 1;
	jacobsthal_index_deq.push_back(0);
	for (size_t i = 2; i < jacobsthal_deq.size(); i++)
	{
		start = jacobsthal_deq[i - 1];
		int end = jacobsthal_deq[i];
		for (int j = end; j > start; j--)
		{
			if (jacobsthal_index_deq.size() == pending_chain_deq.size())
				break;
			jacobsthal_index_deq.push_back(j - 1);
		}
		start = end + 1;
	}
}

int PmergeMe::binary_search_deq(int key)
{
	int left = 0;
	int right = main_chain_deq.size() - 1;
	int mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (key == main_chain_deq[mid])
			return mid;
		else if (key < main_chain_deq[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}
	if (key > main_chain_deq[mid])
		return mid + 1;
	else
		return mid;

}

void PmergeMe::sort_main_chain_deq()
{
	size_t jacob_index = 0;
	while (jacob_index < jacobsthal_index_deq.size())
	{
		size_t temp = jacobsthal_index_deq[jacob_index];
		while (temp >= pending_chain_deq.size())
			temp--;
		int pos = binary_search_deq(pending_chain_deq[temp]);
		main_chain_deq.insert(main_chain_deq.begin() + pos, pending_chain_deq[temp]);
		jacob_index++;
	}
	if (vec.size() % 2 == 1)
	{
		int pos = binary_search_deq(vec[vec.size() - 1]);
		main_chain_deq.insert(main_chain_deq.begin() + pos, vec[vec.size() - 1]);
	}
}

void PmergeMe::check_dup()
{
	std::sort(vec_temp.begin(), vec_temp.end());
	for (size_t i = 0; i < vec_temp.size() - 1; i++)
	{
		if (vec_temp[i] == vec_temp[i + 1])
			throw(std::logic_error("Error"));
	}
}

PmergeMe::~PmergeMe() {}