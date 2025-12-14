//Fundamental generic programming algorithms:
//transform algorithm (map in other languages)
//accumulate algorithm (reducer in other languages)
//filter algorithm

#include <iostream>
#include <vector>

using namespace std;

template<typename Func>
void transform_inline (vector<float>& container, const Func& func) {
    for (auto it = container.begin(); it != container.end(); it++) {
        auto& item = *it;
        //pointing to an element in vector<float> instead of copying it
        func(item);
    }

}//transform inline (change the contents of the current container)

int main(int argc, char* argv[]) {

    auto v = vector<float>{1.1f, 2.2f, 3.3f};
    /* the content of the vector is stored in Heap whereas the attributes of the vector
    are stored in stack, one of those attributes points to the stored contents in Heap */

    transform_inline(v, [/* no attr */](float& item) {item * 10; });
    //this is a very small function, its footprint is pretty much 0 this is why we don't need to symbolically link it in the algorithm
    //but since we will not always know the size of the function, better to link it symbolically
    return 0;
}