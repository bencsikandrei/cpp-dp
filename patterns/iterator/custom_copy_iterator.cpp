#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>

#include <iterator>

// Simulate a non-copyable struct that is our destination
struct Destination {
    Destination(Destination const &rhs) = delete;
    int x{2};
    friend std::ostream &operator<<(std::ostream &out, Destination const &);
};

std::ostream &operator<<(std::ostream &out, Destination const &obj) {
    out << obj.x;
    return out;
}
// Simulate the structure we want to copy from
struct Source {
    int y{4};
    friend std::ostream &operator<<(std::ostream &out, Source const &);
};

std::ostream &operator<<(std::ostream &out, Source const &obj) {
    out << obj.y;
    return out;
}

// The function used to "copy" field by field ..
void copyFromSource(Destination &dst, Source const &src) { dst.x = src.y; }

template <typename T> struct Type;

template <typename Container, typename Source>
class custom_copy_iterator
    : public std::iterator<std::output_iterator_tag, void, void, void, void> {
  public:
    using container_type = Container;
    using destination_type = typename Container::value_type;
    using iterator_type = decltype(std::declval<Container>().begin());
    using function_type =
        std::function<void(destination_type &, Source const &)>;

    custom_copy_iterator(Container &container, function_type func)
        : container_{&container}, copyFunc_{func}, currentPos_{
                                                       container.begin()} {}

    custom_copy_iterator &operator=(Source const &value) {
        copyFunc_(*currentPos_, value);
        return *this;
    }
    custom_copy_iterator &operator*() { return *this; }
    custom_copy_iterator &operator++() {
        ++currentPos_;
        return *this;
    }
    custom_copy_iterator operator++(int) {
        ++currentPos_;
        return *this;
    }

  protected:
    Container *container_;
    function_type copyFunc_;
    decltype(container_->begin()) currentPos_;
};

template <typename Container, typename Source>
using CopyFuncPtr = void (*)(typename Container::value_type &, Source const &);

template <typename Container, typename Source>
auto custom_copier(Container &cont, CopyFuncPtr<Container, Source> func) {
    return custom_copy_iterator<Container, Source>(cont, func);
}

template <typename Container> void print(Container &container) {
    for (auto const &val : container) {
        std::cout << val << " ";
    }
    std::cout << '\n';
}

int main() {
    // These are the containers you have
    std::array<Destination, 3>
        destinations{}; // Destination is the non-copyable one
    std::vector<Source> sources(
        3, {1}); // Source is copyable but this does not matter

    std::cout << "Before: Source contains\n";
    print(sources);
    std::cout << "Before: Destination contains\n";
    print(destinations);

    // use function pointer
    std::copy(sources.begin(), sources.end(),
              custom_copier(destinations, copyFromSource)); // use custom copier

    std::cout << "After: Destination contains\n";
    print(destinations);
    //
    // use a lambda
    std::fill(destinations.begin(), destinations.end(), Destination{255});
    std::cout << "Before: Destination contains\n";
    print(destinations);
}
