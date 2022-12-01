/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   easyfind.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsinke <lsinke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/01 02:20:47 by lsinke        #+#    #+#                 */
/*   Updated: 2022/12/01 02:20:47 by lsinke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template<typename C>
typename C::iterator easyfind(C &container, int val) {
	return std::find(container.begin(), container.end(), val);
}
