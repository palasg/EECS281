#include "graphs_adt.hpp"
#include <algorithm>

namespace lib
{
    std::vector<std::vector<int>> find_all_paths(const std::vector<std::vector<int>> &graph, int source, int destination)
    {
        std::vector<std::vector<int>> all_paths{};
        const auto number_nodes = graph.size();
        std::vector<int> visited_node{};

        for (std::size_t i = 0; i < number_nodes; i++)
        {
            visited_node.push_back(i);
            const auto adjacent_nodes = graph[i];
            for (auto adjacent_node : adjacent_nodes)
            {
                if (std::find(visited_node.begin(), visited_node.end(), adjacent_node) == visited_node.end())
                {
                    visited_node.push_back(adjacent_node);
                }
            }
        }
    }

    std::vector<std::vector<int>> find_all_paths_helper(const int current, const int destination,
                                                        const std::vector<std::vector<int>> &graph, std::vector<std::vector<int>> &paths, std::vector<bool> visited, std::vector<int> current_path)
    {
        visited[current] = true;
        current_path.push_back(current);
        if (current == destination)
        {
            paths.push_back(current_path);
            return paths;
        }
        else
        {
            const auto& adjacent_nodes = graph[current];
            for (auto adjacent_node : adjacent_nodes)
            {
                if (not visited[adjacent_node])
                {
                    find_all_paths_helper(adjacent_node,destination,graph,paths,visited, current_path);

                }
                
            }
            
        }
        
    }

} // namespace lib
