#ifndef MARS_ROVER_H
#define MARS_ROVER_H

#define N 0
#define W 1
#define S 2
#define E 3

#include <string>
#include <vector>

namespace mars {
    class Rover {
        public:
            Rover(int, int, int);
            int getX() const;
            int getY() const;
            int getDirect() const;
            void updateStatus(int, int, int);
            std::string getStatus() const;
            void printStatus() const;
            std::string getRoute() const;
            void printRoute() const;
        private:
            std::vector<int> mx;
            std::vector<int> my;
            std::vector<int> mdirect;
    };
}

#endif
