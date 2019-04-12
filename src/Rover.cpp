#include <mars/Rover.h>
#include <iostream>
#include <string>
#include <sstream>

namespace mars {
    Rover::Rover(int x, int y, int direct)
    {
        mx.push_back(x);
        my.push_back(y);
        mdirect.push_back(direct);
    }

    int Rover::getX() const
    {
        return mx.back();
    }
    int Rover::getY() const
    {
        return my.back();
    }
    int Rover::getDirect() const
    {
        return mdirect.back();
    }
    void Rover::updateStatus(int x, int y, int direct, char c)
    {
        mx.push_back(x);
        my.push_back(y);
        mdirect.push_back(direct);
        mCmd.push_back(c);
    }
    std::string Rover::getStatus() const
    {
        std::stringstream ss;
        ss << mx.back() << " " << my.back() << " ";
        switch (mdirect.back()) {
            case N:
                ss << "N";
                break;
            case W:
                ss << "W";
                break;
            case S:
                ss << "S";
                break;
            case E:
                ss << "E";
                break;
        }
        return ss.str();
    }
    std::string Rover::getRoute() const
    {
        std::stringstream ss;
        int n = mx.size();
        int i = 0;
        while (i < n) {
            ss << mx[i] << " " << my[i] << " ";
            switch (mdirect[i]) {
                case N:
                    ss << "N";
                    break;
                case W:
                    ss << "W";
                    break;
                case S:
                    ss << "S";
                    break;
                case E:
                    ss << "E";
                    break;
            }
            ++i;
            if (i != n) ss << " -> ";
        }
        return ss.str();
    }
    std::string Rover::getCmd() const
    {
        std::string cmd;
        for (const char c: mCmd) {
            cmd += c;
        }
        return cmd;
    }
}
