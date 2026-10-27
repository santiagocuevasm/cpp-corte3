#include <iostream>

#include "AuctionSystem.h"

int main() {
    AuctionSystem subasta;

    subasta.addBid(1, 7, 5);
    subasta.addBid(2, 7, 6);
    std::cout << "Mejor postor del item 7: " << subasta.getHighestBidder(7) << '\n';

    subasta.updateBid(1, 7, 8);
    std::cout << "Mejor postor del item 7: " << subasta.getHighestBidder(7) << '\n';

    subasta.removeBid(2, 7);
    std::cout << "Mejor postor del item 7: " << subasta.getHighestBidder(7) << '\n';

    std::cout << "Mejor postor del item 3: " << subasta.getHighestBidder(3) << '\n';

    // Prueba extra: empate de montos, gana el userId mayor
    subasta.addBid(3, 9, 10);
    subasta.addBid(4, 9, 10);
    std::cout << "Empate en item 9 (usuarios 3 y 4): " << subasta.getHighestBidder(9) << '\n';
    return 0;
}
