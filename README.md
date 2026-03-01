# Restaurant Simulation System

## Overview

The **Restaurant Simulation System** is a sophisticated C++ command-line application designed to simulate the day-to-day operations and order processing of a busy restaurant. The system models various types of customer orders and carefully manages different specialized chefs, simulating real-world queueing, assignment, preparation, and delivery.

The simulation accurately tracks individual order wait times, service times, and finish times to calculate and report restaurant efficiency, displaying average waiting and serving metrics.

## Features

- **Multiple Order Types:**
  The restaurant serves different categories of orders, each with distinct priorities and processing behaviors:
  - **VIP (Very Important Person) Orders**: Highest priority; processed before any other type using a Priority Queue.
  - **Vegan Orders**: Must be prepared by specialized Vegan chefs if available.
  - **Normal Orders**: Standard orders processed in regular order.
  - **Fast Food Orders**: Represent quick, on-the-go meals, managed in their separate queue.
  - **SeaFood Orders**: Require specialized Seafood chefs and often an assistant to prepare.

- **Specialized Chefs:**
  Chefs have variable preparation speeds, break durations, and capabilities:
  - **VIP Chefs**: Fast, handle VIP orders, but can fall back to normal orders if idle.
  - **Vegan Chefs (G)**: Exclusively prepare Vegan meals.
  - **Normal Chefs (N)**: Handle standard non-specialized meals.
  - **SeaFood Chefs (S)**: Handle complex SeaFood orders (may work in pairs).
  - **FastFood Chefs (F)**: Quickly process Fast Food.

- **Simulation Modes:**
  The system provides two distinct ways to observe the simulation dynamics:
  1. **Interactive Mode**: Step-by-step visibility for each time tick. You can see the instantaneous status of all queues (Available Orders, Available Chefs, In-Service Orders, Delivered Orders). Press any key to advance the tick.
  2. **Silent Mode**: Ideal for batch processing or large datasets. The simulation entirely computes the events without console output and dumps the final delivery sequence and statistics into an `Output.txt` file.

- **Data Structures in Use:**
  - Robust **Queue ADT**: Implemented via `LinkedQueue` for standard First-In-First-Out handling.
  - **Priority Queue**: Implemented to manage VIP orders effectively based on calculated priority metrics.

## File Organization & Input/Output Structure

### `Input.txt`
The simulation consumes a precisely formatted input file defining the restaurant settings and upcoming orders.
* **Line 1:** Number of chefs per category (`N G V S F`)
* **Lines 2 to Total_Chefs:** Defines individual chef parameters (ID, Speed, Break Duration, Recovery Time).
* **Next Line:** Total number of orders (`M`)
* **Remaining Lines:** Order details (`Order_Type Arrival_Time Order_ID Size Price`)

### `Output.txt`
When run in Silent mode, an output file will be generated showing:
1. Chronological list of delivered orders. Columns: `FinishTime ID ArrivalTime WaitTime ServiceDuration`
2. Aggregated statistics: Total orders per category, average wait time, average serve time.

## Requirements and Compilation

### Prerequisites
- Operating System: Windows (uses `<conio.h>` for interactive mode pauses, can be adapted for Linux by substituting `_getch()`).
- Compiler: Visual Studio (MSVC) or standard `g++` compiler.
- Minimum C++ Standard: C++11 (uses `std::vector` and lambda expressions).

### Building with Visual Studio
1. Open `RestaurantSimulation.sln` with Microsoft Visual Studio.
2. Build the Solution (Ctrl+Shift+B).
3. Ensure `Input.txt` is located in the working directory (where the `.vcxproj` is).
4. Run the simulation (F5).

### Building with g++ (MinGW on Windows)
If using `g++` in a terminal:
```bash
g++ Main.cpp Resturant.cpp Chef.cpp Order.cpp -o Simulation
./Simulation
```

## How to use

1. Modify `Input.txt` to reflect your desired simulation scenario (e.g., number of chefs, order flow).
2. Launch the application.
3. You will be prompted:
   ```text
   ================== Welcome The Resturant Simulation ==================
   Choose one of the following modes: 
   (1) Silent Mode
   (2) Interactive Mode
   Your choice: 
   ```
4. Enter `1` or `2`.
   - If `1`, check `Output.txt` upon completion.
   - If `2`, observe the console and press any key continuously to advance through time steps.

## Authors / Acknowledgment
Originally named "DS Project (Resturant System)". Written by the repository author.