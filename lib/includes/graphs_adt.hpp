#ifndef GRAPHS_ADT_HPP
#define GRAPHS_ADT_HPP

#include <vector>

namespace lib
{

    std::vector<std::vector<int>> find_all_paths(const std::vector<std::vector<int>> &graph, int source, int destination);

    std::vector<std::vector<int>> find_all_paths_helper(const int current, const int destination, const std::vector<std::vector<int>> &graph,
                                                        std::vector<std::vector<int>> &paths, std::vector<bool> visited, std::vector<int> current_path);

} // namespace lib

#endif
