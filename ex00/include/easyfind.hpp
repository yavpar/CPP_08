/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 20:25:48 by yparthen          #+#    #+#             */
/*   Updated: 2025/10/28 18:48:13 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <list>
#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include "Except.hpp"

# define BLUE "\033[1;34m"
# define RED "\033[1;31m"
# define MARRON "\033[1;33m"
# define GREEN "\033[1;32m"
# define MAGENTA "\033[1;35m"
# define NEUTRAL "\033[0m"

template <typename T>
typename T::const_iterator easyfind(T & container, int & val)
{
	typename T::const_iterator it;

	it = find(container.begin(), container.end(), val);

	if (it == container.end())
		throw ValueNotFound();
	
	return (it);
}

#endif
