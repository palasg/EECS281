#include "string_utils.hpp"
#include <cmath>
#include <iostream>

namespace lib
{
    int string_search_brute_force(std::string_view entire_string, std::string_view target_string)
    {
        const auto entire_string_len = entire_string.size();
        const auto target_string_len = target_string.size();

        for (size_t i = 0; i <= entire_string_len - target_string_len; i++)
        {
            const auto substring = entire_string.substr(i, target_string_len);

            if (substring == target_string)
            {
                return i;
            }
        }

        return -1;
    }

    struct stringTransformar
    {
        const int m_base_value{0};
        stringTransformar(const int base_value) : m_base_value(base_value) {};
        std::int32_t transform(std::string_view str)
        {
            int32_t transform_value{0};
            for (auto &&c : str)
            {
                transform_value = transform_value * m_base_value + static_cast<int32_t>(c);
            }
            return transform_value;
        }
        inline std::int32_t updateTransformValue(int32_t old_value, const char old_char, const char new_char, int len_str)
        {
            return old_value - static_cast<int32_t>(old_char) * std::pow(m_base_value, len_str - 1) + static_cast<int32_t>(new_char);
        }
    };

    int string_search_Rabin_karp(std::string_view main_string, std::string_view target_string)
    {
        constexpr int transformer_base = {10};
        stringTransformar tranformaer_engine{transformer_base};
        const auto target_string_value = tranformaer_engine.transform(target_string);
        const auto target_string_len = target_string.length();
        const auto main_string_len = main_string.length();
        char left_most_char = '\0';
        int32_t string_window_value{0};
        for (size_t i = 0; i <= main_string_len - target_string_len; i++)
        {
            const auto string_window = main_string.substr(i, target_string_len);

            if (i == 0)
            {
                string_window_value = tranformaer_engine.transform(string_window);
            }
            else
            {
                const char right_most_char = *std::prev(string_window.end());
                string_window_value = string_window_value - (static_cast<int32_t>(left_most_char)) * std::pow(transformer_base, target_string_len - 1);
                string_window_value = string_window_value * transformer_base + static_cast<int32_t>(right_most_char);
            }
            left_most_char = string_window[0];

            if (string_window_value == target_string_value)
            {
                return i;
            }
        }
        return -1;
    }

} // namespace lib
