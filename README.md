# Mars Rovers

On a plateau of the Mars, we shall assume that it is not allowed to move beyond the circumference of the plateau and avoid the rovers' falling. This means that whenever a rover tries to leave the grid that is comprised of the coordinates from (0, 0) to (Xmax, Ymax), the program should stop it from moving. Also, it is obvious that any rover cannot occupy the same place at the same time, and thus, a rover will stop moving forward if there is another rover in front of it unless it changes its direction.

## Program Execution

The program consists of three main components: **Executor**, **Rover**, and **Grid**.
**Executor** takes the responsibility for moving a rover given a series of commands. Each command will cause the status update of the current rover by **Executor**. With Google Testing Framework, which will be downloaded by the CMake script, we eventually print out all the rover lists and grids where each rover is located.

## Mathematical Approach to Deciding the Next Direction

```
} else if (c == 'L') {
    direct = (direct + 1) % 4;
} else if (c == 'R') {
    direct = (direct - 1 + 4) % 4;
}
```

## Build and Run

Please ensure that **CMake** is installed before building the program.
Under the unzipped folder, type in the following command.

```
cmake . && make && ./build/MarsTest
```
