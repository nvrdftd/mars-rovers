#include <gtest/gtest.h>
#include <mars/Executor.h>
#include <mars/Grid.h>
#include <mars/Rover.h>

using namespace mars;

class TwoRoverTest: public ::testing::Test {

    protected:
        void SetUp() override
        {
            exe.roverGo(grid, rover_1, cmd_1);
            exe.roverGo(grid, rover_2, cmd_2);
        }
        Executor exe;
        Grid grid {5, 5};
        Rover rover_1 {1, 2, N};
        Rover rover_2 {3, 3, E};
        std::string cmd_1 {"LMLMLMLMM"};
        std::string cmd_2 {"MMRMMRMRRM"};
};

TEST_F(TwoRoverTest, NumRovers)
{
    EXPECT_EQ(exe.numRovers(), 2);
}

TEST_F(TwoRoverTest, RoverStatus)
{
    std::string status_1 {"1 3 N"};
    std::string status_2 {"5 1 E"};
    EXPECT_STREQ(rover_1.getStatus().c_str(), status_1.c_str());
    EXPECT_STREQ(rover_2.getStatus().c_str(), status_2.c_str());
    exe.printRovers();
    grid.print();
}

class SameStartTest: public ::testing::Test {

    protected:
        void SetUp() override
        {
            exe.roverGo(grid, rover_1, cmd_1);
            exe.roverGo(grid, rover_2, cmd_2);
            exe.roverGo(grid, rover_3, cmd_3);
            exe.roverGo(grid, rover_4, cmd_4);
        }
        void TearDown() override
        {
            exe.printRovers();
            grid.print();
        }
        Executor exe;
        Grid grid {5, 5};
        Rover rover_1 {1, 2, N};
        Rover rover_2 {1, 2, E};
        Rover rover_3 {1, 2, S};
        Rover rover_4 {1, 2, W};
        std::string cmd_1 {"LMLMLMLMM"};
        std::string cmd_2 {"MMRMMRM"};
        std::string cmd_3 {"LMLMLMLMM"};
        std::string cmd_4 {"MMRLM"};
};

TEST_F(SameStartTest, NumRovers)
{
    EXPECT_EQ(exe.numRovers(), 4);
}

TEST_F(SameStartTest, RoverStatus)
{
    // std::string status_1 {"1 3 N"};
    // std::string status_2 {"5 1 E"};
    // EXPECT_STREQ(rover_1.getStatus().c_str(), status_1.c_str());
    // EXPECT_STREQ(rover_2.getStatus().c_str(), status_2.c_str());
    exe.printRovers();
    grid.print();
}

class BoundaryTest: public ::testing::Test {

    protected:
        void SetUp() override
        {
            exe.roverGo(grid, rover_1, cmd_1);
        }
        Executor exe;
        Grid grid {10, 10};
        Rover rover_1 {0, 8, N};
        std::string cmd_1 {"MMMMMMMMM"};
};

TEST_F(BoundaryTest, NumRovers)
{
    EXPECT_EQ(exe.numRovers(), 1);
}

TEST_F(BoundaryTest, RoverStatus)
{
    std::string status_1 {"0 10 N"};
    EXPECT_STREQ(rover_1.getStatus().c_str(), status_1.c_str());
    exe.printRovers();
    grid.print();
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
