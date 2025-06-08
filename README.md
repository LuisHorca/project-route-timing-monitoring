# Route timing monitoring Project

## Problem
In contexts such as urban logistics, personal transportation or route planning, the need to calculate the estimated travel time between two locations using different means of transport is common. Each type of vehicle has particular characteristics, such as maximum speed or load limitations, which directly influence the travel time. Solving such situations in a structured way allows better decisions to be made in real-world environments such as goods delivery, tourism or daily mobility.

I find this project interesting because it allows us to understand, in a simplified way, how applications such as Google Maps work when estimating travel times. Although more complex factors such as traffic, weather or variable speed limits are not considered, the project provides a solid basis for understanding the logic behind route calculation. By relating the distance between two points to the maximum speed of a vehicle, we can take a small global survey of how route telemetry operates. This helps to visualize how, from basic data such as distance and speed, it is possible to build systems that effectively guide mobility decisions.


## Project Description
This project proposes a simple and modular solution using object-oriented programming in C++. Classes are defined for different types of vehicles (car, bicycle and truck), all of them derived from a base class Vehicle, which allows inheritance and polymorphism to be applied when calculating the maximum speed of each one. The user selects a point of origin, a destination and a means of transportation, and the program estimates the time required to complete the route based on a predefined distance between places. The design makes it easy to add more locations or vehicles without altering the main logic, and reinforces key concepts of encapsulation, code reuse and abstraction.

## Classes and Justifications

- **Vehicle (abstract)**  
  Defines the common interface (`maxSpeed()`, `travelTime()`) and holds the shared attributes (`brand`, `model`).  Forces all subclasses to implement their own top‐speed logic.

- **Car**  
  Uses `horsepower` to calculate `maxSpeed()`.  Overloads `operator==` to compare two cars by brand, model *and* horsepower.

- **Bicycle**  
  Stores a simple `hasGears` flag to choose between two realistic top speeds.  Demonstrates overriding without extra attributes.

- **Truck**  
  Provides a fixed highway speed.  Illustrates a subclass with no extra data members.

- **Motorcycle**  
  Uses `engineCapacity` (cc) to derive `maxSpeed()`.  Shows another variation of speed calculation.

- **Foot**  
  Represents walking with a single constant speed.  Ensures the menu can handle “on‐foot” travel.

- **Route**  
  Manages a list of locations and their pairwise distances.  Supports adding/removing locations and querying distances.  Enables the core routing functionality of the program.

---

## Key Features

- **Abstract Class & Polymorphism**  
  `Vehicle` is abstract; the menu stores and uses `Vehicle*` to call `travelTime` on any subtype.

- **Method Overriding & Overloading**  
  Each subclass overrides `maxSpeed()`.  `Vehicle` overloads `travelTime(distance)` vs. `travelTime(distance, inMinutes)`.

- **Operator Overloading**  
  `operator<<` to print a vehicle’s identifier; `operator==` and `operator<` for comparisons and ordering.

- **Dynamic Route Management**  
  Add or remove locations at runtime and recalculate distances.

- **Interactive Menu**  
  Simple console interface with “or ‘b’ to go back” at each prompt.

---

## How to Use the Program

1. **Download the Project Files**  
   Clone the repository or download the ZIP:
   ```bash
   git clone https://github.com/yourusername/route-tracker.git
   cd route-tracker
   
## Set Up Your Environment & Interact with the Program

1. **Install** a C++ compiler with C++11 (or newer) support (e.g. `g++` or `clang++`).  
2. **Ensure** your include path finds the `.h` and `.cpp` files in the project root.  
3. **Compile & Run**:
   ```bash
   g++ -std=c++11 \
     main.cpp \
     Vehicle.cpp \
     Car.cpp \
     Bicycle.cpp \
     Truck.cpp \
     Motorcycle.cpp \
     Foot.cpp \
     Route.cpp \
     -o route_app
   ./route_app
4. **Use the menu**

    1.- List locations — shows all current locations.  
    2.-Add location — enter a name and distances to existing points (or `b` to go back).  
    3.- Remove location — choose an index (or `b` to go back).  
    4.- Get distance — pick origin & destination indices (or `b` to go back).  
    5.- Estimate travel time — after selecting a vehicle, pick two indices to see time & distance.  
    6.- Change vehicle — choose a type, enter its parameters (or `b` to go back).  
    0.- Exit — quits the program.  


### UML Class Diagram

![proyecto drawio (1)](https://github.com/user-attachments/assets/f4d4230e-310f-43a0-85bc-414d84a51ea2)

