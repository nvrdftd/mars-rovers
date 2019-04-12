#ifndef MARS_GRID_H
#define MARS_GRID_H

#include <unordered_map>
#include <unordered_set>

namespace mars {
    class Grid {
        public:
            Grid(int, int);
            // If occupying a location is successful, then it returns true, or otherwise false.
            bool occupy(int, int);
            bool isOccupied(int, int) const;
            int getXMax() const;
            int getYMax() const;
            void print() const;
        private:
            int mxMax;
            int myMax;

            // Store occupied coordinates
            std::unordered_map<int, std::unordered_set<int> > occupied;
    };
}

#endif
