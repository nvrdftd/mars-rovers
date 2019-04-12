#include <mars/Executor.h>
#include <mars/Grid.h>
#include <mars/Rover.h>
#include <string>
#include <iostream>

namespace mars {
    bool Executor::roverGo(Grid &grid, Rover &rvr, std::string &cmd)
    {
        int x = rvr.getX();
        int y = rvr.getY();
        int direct = rvr.getDirect();

        // If the location is occupied, then the rover cannot move even though the command exists.
        if (grid.isOccupied(x, y)) return false;

        int tmpX;
        int tmpY;

        for (const char c: cmd) {
            if (c == 'M') {
                tmpX = x;
                tmpY = y;
                switch (direct) {
                    case N:
                        ++tmpY;
                        break;
                    case W:
                        --tmpX;
                        break;
                    case S:
                        --tmpY;
                        break;
                    case E:
                        ++tmpX;
                        break;
                }

                if (!grid.isOccupied(tmpX, tmpY)) {
                    x = tmpX;
                    y = tmpY;
                }
            } else if (c == 'L') {
                direct = (direct + 1) % 4;
            } else if (c == 'R') {
                direct = (direct - 1 + 4) % 4;
            }
            rvr.updateStatus(x, y, direct, c);
        }

        // After all the moves and direction changes, update the grid.
        grid.occupy(x, y);

        mRovers.push_back(rvr);

        return true;
    }
    bool Executor::roverGo(Grid &grid, Rover &rvr, char *cmd)
    {
        std::string str {cmd};
        return roverGo(grid, rvr, str);
    }
    void Executor::printRovers() const
    {
        std::cout << std::endl;
        std::cout << "Rover List: " << std::endl;
        for (auto rvr: mRovers) {
            std::cout << rvr.getStatus() << " (" << rvr.getRoute() << ", " << rvr.getCmd() << ")" << std::endl;
        }
        std::cout << std::endl;
    }
    size_t Executor::numRovers() const
    {
        return mRovers.size();
    }
}
