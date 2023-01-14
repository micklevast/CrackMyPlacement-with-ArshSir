#include <iostream>
#include <set>
#include <vector>

int main()
{
    std::set<std::vector<int>> my_set;
    std::vector<int> vec1 = {1, 2, 3};
    std::vector<int> vec2 = {4, 5, 6};
    std::vector<int> vec3 = {1, 2, 3};

    my_set.insert(vec1);
    my_set.insert(vec2);
    my_set.insert(vec3);

    for (const auto &vec : my_set)
    {
        for (int i : vec)
        {
            std::cout << i << ' ';
        }
        std::cout << std::endl;
    }
    return 0;
}
