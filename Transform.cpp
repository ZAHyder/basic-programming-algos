//Fundamental generic programming algorithms:
//transform algorithm (map in other languages)
//accumulate algorithm (reducer in other languages)
//filter algorithm

#include <iostream>
#include <vector>

using namespace std;

// template<typename Container>
void print(auto& v) {
    for (const auto& item : v) {
        cout << item << ", ";
    }
    cout << endl;
}//auto does the same thing as template

void transform_inline(auto& container, const auto& func) {
 for (auto it = container.begin(); it != container.end(); it++) {
        auto& item = *it;
        //pointing to an element in vector<float> instead of copying it
        item = func(item);
    }
}//transform inline (change the contents of the current container)

template<typename Container>
Container transform(const Container& container, const auto& func) {
    auto new_cont = Container();
    for (auto it = container.begin(); it != container.end(); it++) {
        auto& item = *it;
        new_cont.push_back(func(item));
    }
    return new_cont;
}//creates new copy of the container with transformed elements

int main(int argc, char* argv[]) {
    auto v = vector<float>{1.1f, 2.2f, 3.3f};
    /* the content of the vector is stored in Heap whereas the attributes of the vector
    are stored in stack, one of those attributes points to the stored contents in Heap */

    print(v);
    transform_inline(v, [/* no attr */](float& item) {return item * 10; });
    //this is a very small function, its footprint is pretty much 0 this is why we don't need to symbolically link it in the algorithm
    //but since we will not always know the size of the function, better to link it symbolically
    print(v);

    auto new_cont = transform(v, [](const float& item) {return item * 10; });
    print(new_cont);

    return 0;
}