# Toy Robot Code Challenge

## Description

* The application is a simulation of a toy robot moving on a square tabletop, of dimensions 5 units x 5 units. There are no other obstructions on the table surface.
* The robot is free to roam around the surface of the table, but must be prevented from falling to destruction. Any movement that would result in the robot falling from the table must be prevented, however further valid movement commands must still be allowed.
* Create an application that can read in commands of the following form:

PLACE X,Y,F
MOVE
LEFT
RIGHT
REPORT

* PLACE will put the toy robot on the table in position X,Y and facing NORTH, SOUTH, EAST or WEST.
* The origin (0,0) can be considered to be the SOUTH WEST most corner.
* The first valid command to the robot is a PLACE command, after that, any sequence of commands may be issued, in any order, including another PLACE command. The application should discard all commands in the sequence until a valid PLACE command has been executed
* MOVE will move the toy robot one unit forward in the direction it is currently facing.
* LEFT and RIGHT will rotate the robot 90 degrees in the specified direction without changing the position of the robot.
* REPORT will announce the X,Y and F of the robot. This can be in any form, but standard output is sufficient.
* A robot that is not on the table can choose to ignore the MOVE, LEFT, RIGHT and REPORT commands.
* Input can be from a file, or from standard input, as the developer chooses.
* Provide test data to exercise the application.

## Constraints

* The toy robot must not fall off the table during movement. This also includes the initial placement of the toy robot.
* Any move that would cause the robot to fall must be ignored.

## Example Input and Output:

### Example a

PLACE 0,0,NORTH
MOVE
REPORT

#### Expected output:

0,1,NORTH

### Example b

PLACE 0,0,NORTH
LEFT
REPORT

#### Expected output:

0,0,WEST

### Example c

PLACE 1,2,EAST
MOVE
MOVE
LEFT
MOVE
REPORT

#### Expected output

3,3,NORTH

## Deliverables

Please provide your source code, and any test code/data you using in developing your solution.

## Getting the project

### git

Clone the repository from one of the following locations:  

* GitHub Original
    * ssh: `git@github.com:sk-ws-stan/robot.git`
    * https: `https://github.com/sk-ws-stan/robot.git`
* GitHub fork of sk-ws-stan (Iress account)
    * ssh: `git@github.com:StanleyKlemme/robot.git`
    * https: `https://github.com/StanleyKlemme/robot.git`
* BitBucket fork of StanleyKlemme/robot
    * ssh: `git@bitbucket.devel.iress.com.au:7999/~stanley.klemme/robot.git`
    * https: `https://Stanley.Klemme@bitbucket.devel.iress.com.au/scm/~stanley.klemme/robot.git`

### TFS

A legacy check-in is provided at `$\Iress\UserProjects\stanley.klemme\Training\main\robot`

## Building the project

The project compiles with C++11 as `toy_robot` in your build directory. The unit test project compiles as `test/test_toy_robot`.

It is recommended to build the project with `CMake` and out of source, however in-source builds are supported.
Alternatively the project supports building with `Conan`.
For legacy reasons it is aspired to support a IressSource build for Windows, but as this is a legacy system the support (is as mentioned aspirational and) might be out of date.

### Dependencies

The project includes headers for the boost libraries `algorithm` and `lexical_cast` and the unit test project links against the `boost unit test framework`. Tested versions are `1.50.0` with `gcc 4.6.3`, and `1.61.0` with `v140`.

Get boost at `https://www.boost.org/users/download/`


### CMake (2.8.4 and newer)

Run cmake-gui and configure from the source root of the project. Point the required setting `THIRD_PARTY_ROOT` to the directory that contains your boost install. To build the unit tests project set the option `BUILD_UNIT_TESTS`.

#### Commandline

For the source root, run `cmake` with the options `-DTHIRD_PARTY_ROOT=<path to your 3rd Party root` and optionally `BUILD_UNIT_TEST=ON`.

Example
```
sk@ws-stan:~/dev/src/robot (master)$ cmake . -DTHIRD_PARTY_ROOT=~/dev/src/3rd -DBUILD_UNIT_TEST=ON
```

### Conan (1.4 and newer)

The project supports building with conan. First run `conan install -s build_type=Release -s arch=x86 .` to generate the required local conanfiles and obtain the boost libraries. Then run `conan build .` to build the project for the build_type Release in 32bit. The conan build will currently not build the unit test project.

### Iress Source (Windows only)

coming soon
