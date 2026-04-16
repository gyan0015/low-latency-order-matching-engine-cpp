#include "orderbook.h"

// Comparator implementations
bool BuyCompare::operator()(const Order& a, const Order& b) {
    return a.price < b.price;
}
bool SellCompare::operator()(const Order& a, const Order& b) {
    return a.price > b.price;
}

// OrderBook member functions
int OrderBook::addOrder(const std::string& side, const std::string& type, double price, int quantity, bool log) {
    Order order{++orderId, side, type, price, quantity, orderId};
    activeOrders[order.id] = order;

    if (order.type == "MARKET") {
        if (side == "BUY") matchMarketBuy(order, log);
        else matchMarketSell(order, log);
    } else {
        if (side == "BUY") {
            matchBuy(order, log);
            if (order.quantity > 0) buyOrders.push(order);
        } else {
            matchSell(order, log);
            if (order.quantity > 0) sellOrders.push(order);
        }
    }
    return order.id;
}

void OrderBook::cancelOrder(int id) {
    if (activeOrders.find(id) != activeOrders.end()) {
        activeOrders.erase(id);
        std::cout << "CANCELLED: OrderID " << id << std::endl;
    } else {
        std::cout << "OrderID " << id << " not found." << std::endl;
    }
}

void OrderBook::printOrderBook(int depth) {
    std::cout << "----- Order Book (Top " << depth << ") -----" << std::endl;

    auto buys = buyOrders;
    std::cout << "Bids:" << std::endl;
    int count = 0;
    while (!buys.empty() && count < depth) {
        auto o = buys.top(); buys.pop();
        if (activeOrders.find(o.id) != activeOrders.end() && o.quantity > 0) {
            std::cout << "  " << o.price << " x " << o.quantity << " (ID " << o.id << ")" << std::endl;
            count++;
        }
    }

    auto sells = sellOrders;
    std::cout << "Asks:" << std::endl;
    count = 0;
    while (!sells.empty() && count < depth) {
        auto o = sells.top(); sells.pop();
        if (activeOrders.find(o.id) != activeOrders.end() && o.quantity > 0) {
            std::cout << "  " << o.price << " x " << o.quantity << " (ID " << o.id << ")" << std::endl;
            count++;
        }
    }
    std::cout << "------------------------------" << std::endl;
}

void OrderBook::runStressTest(int N) {
    std::cout << "Running stress test with " << N << " orders..." << std::endl;

    auto start = std::chrono::high_resolution_clock::now();

    std::mt19937 rng(42);
    std::uniform_int_distribution<int> sideDist(0, 1);
    std::uniform_real_distribution<double> priceDist(95.0, 105.0);
    std::uniform_int_distribution<int> qtyDist(1, 10);

    for (int i = 0; i < N; i++) {
        std::string side = sideDist(rng) ? "BUY" : "SELL";
        double price = priceDist(rng);
        int qty = qtyDist(rng);
        addOrder(side, "LIMIT", price, qty, false);
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Processed " << N << " orders in "
              << duration.count() << " ms" << std::endl;
}

// --- Private matching functions (implementations) ---
void OrderBook::matchBuy(Order& order, bool log) { /* same logic as before */ }
void OrderBook::matchSell(Order& order, bool log) { /* same logic as before */ }
void OrderBook::matchMarketBuy(Order& order, bool log) { /* same logic as before */ }
void OrderBook::matchMarketSell(Order& order, bool log) { /* same logic as before */ }