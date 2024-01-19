/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:07:12 by seoson            #+#    #+#             */
/*   Updated: 2024/01/19 14:33:36 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

static void print_int(int x)
{
  std::cout << x << std::endl;
  return;
}

static void print_char(char x)
{
  std::cout << x << std::endl;
  return;
}

int main() {
  int ex_int[] = {0, 1, 2, 3, 4};
  char ex_char[] = "HELLO WORLD!";
  iter(ex_int, 5, print_int);
  iter(ex_char, 12, print_char);
  return 0;
}
