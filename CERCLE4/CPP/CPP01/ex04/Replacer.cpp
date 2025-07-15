/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 20:16:53 by vbui              #+#    #+#             */
/*   Updated: 2025/07/01 20:18:06 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

Replacer::Replacer() {}

Replacer::~Replacer() {}

std::string Replacer::replaceAll(std::string content, const std::string& s1, const std::string& s2) {
    if (s1.empty())
        return content;

    std::string result;
    size_t pos = 0;
    size_t found;

    while ((found = content.find(s1, pos)) != std::string::npos) {
        result.append(content, pos, found - pos);
        result.append(s2);
        pos = found + s1.length();
    }

    result.append(content, pos);
    return result;
}
