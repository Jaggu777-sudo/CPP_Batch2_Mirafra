#include <algorithm>
#include <cassert>
#include <vector>
#include <list>
#include<iostream>
using namespace std;
int main()
{
    const auto source = std::list{2, 7, 1};
    auto destination = std::vector{3, 1, 4};
//#ifdef __cpp_lib_containers_ranges
    destination.assign_range(source);
    for(const auto& x:destination)
    cout<<x<<endl;
//#else
    destination.assign(source.cbegin(), source.cend());
//#endif
 //   assert(std::ranges::equal(source, destination));
}
