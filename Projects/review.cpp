#include <iostream>

int main() {
    // Add your code below
    double weighte, weightm, g = 3.7;
    std::cout << "Enter a weidht of  an item: ";
    std::cin >> weighte;
    weightm = weighte * g;
    std::out << "The weidht of the item on Mars: " << weightm << std::endl;

    double distm, distk, p = 1.60934;
    std::cout << "Enter a distance in miles ";
    std::cin >> distm;
    distk = distm * p;
    std::out << "The a distance in miles: " << distk << std::endl;

    return 0;
}