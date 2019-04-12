#include <gtest/gtest.h>
#include <mars/Executor.h>
#include <mars/Grid.h>
#include <mars/Rover.h>

using namespace mars;


// Test if a rover can be moved
class DeadRoverTest: public ::testing::Test {

    protected:
        void SetUp() override
        {
            exe.roverGo(grid, rover_1, cmd_1);
            exe.roverGo(grid, rover_2, cmd_2);
        }
        Executor exe;
        Grid grid {10, 10};
        Rover rover_1 {-1, -3, N};
        Rover rover_2 {11, 18, S};
        std::string cmd_1 {""};
        std::string cmd_2 {""};
};

TEST_F(DeadRoverTest, NumRovers)
{
    EXPECT_EQ(exe.numRovers(), 0);
}

TEST_F(DeadRoverTest, RoverStatus)
{
    EXPECT_STREQ(rover_1.getStatus().c_str(), "-1 -3 N");
    EXPECT_STREQ(rover_2.getStatus().c_str(), "11 18 S");
    EXPECT_STREQ(rover_1.getCmd().c_str(), "");
    EXPECT_STREQ(rover_2.getCmd().c_str(), "");
    exe.printRovers();
    grid.print();
}

// Test if a rover is not moving
class StillRoverTest: public ::testing::Test {

    protected:
        void SetUp() override
        {
            exe.roverGo(grid, rover_1, cmd_1);
        }
        Executor exe;
        Grid grid {3, 3};
        Rover rover_1 {1, 2, W};
        std::string cmd_1 {""};
};

TEST_F(StillRoverTest, NumRovers)
{
    EXPECT_EQ(exe.numRovers(), 1);
}

TEST_F(StillRoverTest, RoverStatus)
{
    EXPECT_STREQ(rover_1.getStatus().c_str(), "1 2 W");
    EXPECT_STREQ(rover_1.getCmd().c_str(), "");
    exe.printRovers();
    grid.print();
}

// Test if a rover can move out of the boundaries
class GridBoundaryTest: public ::testing::Test {

    protected:
        void SetUp() override
        {
            exe.roverGo(grid, rover_1, cmd_1);
            exe.roverGo(grid, rover_2, cmd_2);
        }
        Executor exe;
        Grid grid {9, 8};
        Rover rover_1 {0, 8, N};
        Rover rover_2 {4, 1, E};
        std::string cmd_1 {"MMMMMMMMM"};
        std::string cmd_2 {"MMMMMMMMM"};
};

TEST_F(GridBoundaryTest, NumRovers)
{
    EXPECT_EQ(exe.numRovers(), 2);
}

TEST_F(GridBoundaryTest, RoverStatus)
{
    EXPECT_STREQ(rover_1.getStatus().c_str(), "0 8 N");
    EXPECT_STREQ(rover_2.getStatus().c_str(), "9 1 E");
    exe.printRovers();
    grid.print();
}

// Test to move two rovers sequentially
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
    EXPECT_STREQ(rover_1.getStatus().c_str(), "1 3 N");
    EXPECT_STREQ(rover_2.getStatus().c_str(), "5 1 E");
    exe.printRovers();
    grid.print();
}

// Test that rovers cannot occupy the same place at the same time
class ConflictTest: public ::testing::Test {

    protected:
        void SetUp() override
        {
            exe.roverGo(grid, rover_1, cmd_1);
            exe.roverGo(grid, rover_2, cmd_2);
            exe.roverGo(grid, rover_3, cmd_3);
        }
        Executor exe;
        Grid grid {10, 10};
        Rover rover_1 {4, 2, N};
        Rover rover_2 {4, 7, E};
        Rover rover_3 {4, 8, S};
        std::string cmd_1 {"LRMLRMMMM"};
        std::string cmd_2 {"MMRRM"};
        std::string cmd_3 {"MM"};
};

TEST_F(ConflictTest, NumRovers)
{
    EXPECT_EQ(exe.numRovers(), 2);
}

TEST_F(ConflictTest, RoverStatus)
{
    EXPECT_STREQ(rover_1.getStatus().c_str(), "4 7 N");
    EXPECT_STREQ(rover_2.getStatus().c_str(), "4 7 E");
    EXPECT_STREQ(rover_3.getStatus().c_str(), "4 8 S");
    exe.printRovers();
    grid.print();
}

// Test to add rovers from the same location, where each one of them ends up in a different place
class SameStartTest: public ::testing::Test {

    protected:
        void SetUp() override
        {
            exe.roverGo(grid, rover_1, cmd_1);
            exe.roverGo(grid, rover_2, cmd_2);
            exe.roverGo(grid, rover_3, cmd_3);
            exe.roverGo(grid, rover_4, cmd_4);
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
    EXPECT_STREQ(rover_1.getStatus().c_str(), "1 3 N");
    EXPECT_STREQ(rover_2.getStatus().c_str(), "2 0 W");
    EXPECT_STREQ(rover_3.getStatus().c_str(), "2 1 S");
    EXPECT_STREQ(rover_4.getStatus().c_str(), "0 2 W");
    exe.printRovers();
    grid.print();
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
