/* 
    File: main.cpp 
    Description: 11.1: lambda functions and a Pizza Order Sorter
    Author: Xander Velasco
    Email: xanderv9994@student.vvc.edu
	Course#: cis202
	Section#: <30001>
    Date: 5/26/2025
*/

#include <cstddef>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

struct PizzaOrder {
    std::string name;
    int size;
};

struct PizzaOrderWithPrice {
    std::string name;
    int size;
    double price;
};

auto printOrders = [](const std::vector<PizzaOrder>& orders) {
    for (const auto& order : orders)
        std::cout << order.name << " " << order.size << " inches\n";
    std::cout << '\n';
};

auto printOrdersWithPrice = [](const std::vector<PizzaOrderWithPrice>& orders) {
    for (size_t i = 0; i < orders.size(); ++i) {
        const auto& order = orders[i];
        std::cout << order.name << " " << order.size << " inches $"
                  << std::fixed << std::setprecision(2) << order.price;
        if (i < orders.size() - 1) std::cout << '\n';
    }
};

int main() {

    std::cout << '\n';
    std::vector<PizzaOrder> orders = {
        {"Alice", 12}, {"Bob", 16}, {"Charlie", 10}, {"Diana", 14} 
    };

    std::cout << "Original Pizza Orders:\n";
    printOrders(orders);

    std::sort(orders.begin(), orders.end(), [](const PizzaOrder& a, const PizzaOrder& b) {
        return a.size < b.size;
    });
    std::cout << "Sorted by Size (Ascending):\n";
    printOrders(orders);

    std::sort(orders.begin(), orders.end(), [](const PizzaOrder& a, const PizzaOrder& b) {
        return a.name < b.name;
    });
    std::cout << "Sorted by Name (Alphabetical):\n";
    printOrders(orders);

    std::vector<PizzaOrderWithPrice> pricedOrders = {
        {"Alice", 12, 11.99},
        {"Bob", 16, 15.49},
        {"Charlie", 10, 9.99},
         {"Diana", 14, 13.75}
    };

    std::sort(pricedOrders.begin(), pricedOrders.end(), [](const PizzaOrderWithPrice& a, const PizzaOrderWithPrice& b) {
        return a.price < b.price;
    });

    std::cout << "Sorted by Price (Ascending):\n";
    printOrdersWithPrice(pricedOrders);

    return 0;
} 
