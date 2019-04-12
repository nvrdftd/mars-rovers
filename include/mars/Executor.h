#ifndef MARS_EXECUTOR_H
#define MARS_EXECUTOR_H

#include <mars/Grid.h>
#include <mars/Rover.h>
#include <string>
#include <vector>

namespace mars {
    class Executor {
        public:
            bool roverGo(Grid &, Rover &, std::string &);
            bool roverGo(Grid &, Rover &, char *);
            void printRovers() const;
            size_t numRovers() const;
        private:
            std::vector<Rover> mRovers;
    };
}

#endif
