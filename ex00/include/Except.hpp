/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Except.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 21:15:26 by yparthen          #+#    #+#             */
/*   Updated: 2025/10/28 17:47:23 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPT_HPP
#define EXCEPT_HPP

#include <exception>

class ValueNotFound : public std::exception
{
	public:
		const char *what() const throw()
		{
			return ("value not found");
		}

};

#endif
