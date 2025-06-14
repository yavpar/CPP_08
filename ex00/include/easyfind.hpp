/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 20:25:48 by yparthen          #+#    #+#             */
/*   Updated: 2025/06/13 18:45:47 by yparthen         ###   ########.fr       */
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

template <typename T>
typename T::const_iterator easyfind(T & container, int & val)
{
	typename T::iterator it;

	it = find(container.begin(), container.end(), val);

	if (it == container.end())
		throw ValueNotFound();
	
	return (it);
}

#endif
