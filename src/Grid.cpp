#include <mars/Grid.h>
#include <utility>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <iostream>

namespace mars {
    Grid::Grid(int xMax, int yMax): mxMax(xMax), myMax(yMax) {}
    bool Grid::occupy(int x, int y)
    {
        if (occupied.count(x) == 1) {
            if (occupied[x].count(y) == 1) return false;
            occupied[x].insert(y);
        } else {
            // Both x and y were not occupied
            std::unordered_set<int> ySet;
            ySet.insert(y);
            occupied.insert(make_pair(x, std::move(ySet)));
        }
        return true;
    }

    bool Grid::isOccupied(int x, int y) const
    {
        // Consider the area that is out of the grid as occupied.
        if (x < 0 || y < 0 || x > mxMax || y > myMax) return true;

        if ((occupied.count(x) == 1) && (occupied.at(x).count(y) == 1)) return true;

        return false;
    }

    int Grid::getXMax() const
    {
        return mxMax;
    }

    int Grid::getYMax() const
    {
        return myMax;
    }

    void Grid::print() const
    {
        // Print out the grid from upper-left to bottom-right corner
        std::cout << std::endl;
        std::cout << "Rover Grid: " << std::endl;

        for (int y = myMax; y >= 0; --y) {
            std::cout << y << " ";
            for (int x = 0; x <= mxMax; ++x) {
                if (isOccupied(x, y)) {
                    std::cout << " x ";
                } else {
                    std::cout << " - ";
                }
            }
            std::cout << std::endl;
        }

        std::cout << "  ";
        for (int x = 0; x <= mxMax; ++x) std::cout << " " << x << " ";
        std::cout << "  " << std::endl;

        std::cout << std::endl;
    }

}
