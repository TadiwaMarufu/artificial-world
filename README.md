# Artificial World

**A long-term C++ learning project in artificial life, ecosystem simulation, physics, AI, and machine learning.**

Artificial World is an evolving artificial-life simulation built in C++. It begins as a small terminal program and gradually grows into a world populated by autonomous organisms that consume resources, move, reproduce, compete, adapt, and respond to their environment.

The goal is to build **one substantial project**, not a series of disconnected exercises. Every milestone extends the same codebase, allowing C++ concepts to be learned in context and revisited as the simulation becomes more sophisticated.

> **Current status:** Planning / initial prototype not yet implemented.

---

## Contents

- [Project vision](#project-vision)
- [Goals](#goals)
- [Core principles](#core-principles)
- [The world we are building](#the-world-we-are-building)
- [Roadmap](#roadmap)
- [Architecture](#architecture)
- [Learning workflow](#learning-workflow)
- [Development environment](#development-environment)
- [Quality checklist](#quality-checklist)
- [First implementation checklist](#first-implementation-checklist)
- [Definition of success](#definition-of-success)

## Project vision

The recommended direction is a **hybrid artificial ecosystem**: a natural-style world with room for unusual artificial organisms, experimental traits, and learning-based behaviour.

The world will grow in capability over time. Early organisms will follow simple, explicitly programmed rules. Later, organisms will sense their surroundings, make decisions, inherit traits, evolve across generations, and potentially learn behaviours through machine learning.

The simulation should remain useful as a terminal application even if graphical development is delayed by device or dependency constraints.

## Goals

- Build strong, practical C++ foundations through a substantial project.
- Learn data structures, algorithms, software design, debugging, testing, and performance analysis.
- Implement resources, survival, reproduction, death, and population dynamics.
- Add spatial mathematics and physics: movement, velocity, forces, and collisions.
- Build increasingly capable decision-making systems.
- Explore evolution and machine learning as related but distinct approaches.
- Eventually visualize the simulation and run controlled experiments on its behaviour.

## Core principles

1. **Build the smallest working version first.** Start with a terminal simulation. Correct behaviour matters more than graphics.
2. **One project, steadily improved.** Keep a single codebase and add features in stages.
3. **Understand before expanding.** Learn the C++ concepts needed for the next milestone, implement them, debug them, and review the design.
4. **Prefer safe, modern C++.** Use standard-library containers and RAII where appropriate. Raw pointers are important to understand, but should not be used everywhere by default.
5. **Make experiments measurable.** Track population, food, births, deaths, and other metrics so changes can be evaluated.
6. **Respect the development environment.** Start in Termux with the existing `cpp` compile-and-run helper. Add external libraries only when needed and practical.
7. **Keep the architecture proportional.** Do not build a large architecture before the first simulation works.

## The world we are building

### Version 0.1 — The foundation

The first version will contain:

- A `World` that manages the simulation state.
- An `Organism` type representing an individual creature.
- A population of organisms.
- A simulation loop that advances the world one step at a time.
- A readable report showing simulation time, population, and basic organism state.

Example of the *intended kind* of terminal output (illustrative only):

```text
========== ARTIFICIAL WORLD ==========

Day: 1
Population: 3
Food available: 25

Organisms:
Creature #1 | Energy: 80 | Age: 1
Creature #2 | Energy: 65 | Age: 1
Creature #3 | Energy: 92 | Age: 1

=====================================
```

Do not add predators, reproduction, physics, or machine learning in v0.1. First establish a clean, understandable foundation. The example output is a design sketch, not implemented functionality.

## Roadmap

Each stage extends the same codebase. The stages are a learning sequence, not fixed deadlines; move forward when the current milestone works and its core ideas are understood.

| Stage | World milestone | C++ and technical topics |
|---|---|---|
| **1 — The Foundation** | World state, organisms, simulation steps, terminal reports | Variables, types, functions, structs, classes, loops, conditionals, basic input/output |
| **2 — Living Organisms** | Energy, health, age, lifespan, simple survival rules | Constructors, encapsulation, member functions, references, `const` correctness, `std::vector` |
| **3 — Memory and Ownership** | Safe object lifetimes and clear ownership of world data | Stack vs heap, pointers, dynamic allocation, RAII, destructors, smart pointers, copying and moving |
| **4 — Ecosystem Dynamics** | Food sources, eating, energy loss, reproduction, death, population limits | Algorithms, iterators, container operations, removal during iteration, random number generation, invariants |
| **5 — Spatial World and Physics** | Coordinates, movement, velocity, acceleration, forces, boundaries, collisions | 2D vector math, operator functions, units, time steps, numerical integration, basic physics |
| **6 — Sensing and Behaviour** | Organisms sense nearby resources and threats, then choose actions | State machines, modular design, interfaces, spatial queries, decision systems |
| **7 — Evolution** | Traits are inherited with variation; generations respond to environmental pressures | Probability, statistics, distributions, mutation, selection, experimental design |
| **8 — Advanced AI** | Navigation, planning, competing behaviours, more complex agents | Graphs, pathfinding, search, behaviour trees, utility-based decisions, performance trade-offs |
| **9 — Machine Learning** | Train and evaluate models for selected organism behaviours | Datasets, features, objectives/loss, training vs evaluation, baselines, model integration and limitations |
| **10 — Visualization** | Render the world and inspect organisms and population trends | Graphics loop, rendering, input handling, separating simulation from presentation, library integration |
| **11 — Research and Optimization** | Run repeatable experiments and compare ecosystem configurations | Unit/integration tests, profiling, logging, serialization, statistical summaries, reproducibility |

### Evolution is not the same as machine learning

Evolution can select inherited traits across generations. Machine learning trains models from data or experience. They can complement each other, but one does not automatically produce the other. The project will explore both deliberately.

## Architecture

The structure should evolve only when the code needs it. These are likely responsibilities as the project grows—not a requirement to create every file immediately.

- **`Organism`** — an individual creature's traits and state.
- **`World`** — resources, organisms, environmental rules, and simulation time.
- **`Simulation`** — advances the world in defined steps.
- **Behaviour / decision systems** — choose actions from sensed information.
- **Physics system** — updates movement and resolves relevant interactions.
- **Statistics / experiment tools** — collect results without controlling the simulation.
- **Renderer** — eventually displays the world without owning its core rules.

As the project grows, keep simulation logic separate from display code. This will make testing and future visualization easier.

## Learning workflow

For each milestone:

1. Define the next small behaviour the world must support.
2. Identify the C++ concepts needed to implement it.
3. Sketch the data and control flow before coding.
4. Implement the feature yourself, using guidance rather than copying a complete solution.
5. Compile with the existing Termux `cpp` helper and inspect compiler errors carefully.
6. Test normal cases and edge cases; investigate unexpected behaviour.
7. Review ownership, naming, responsibilities, and possible failure modes.
8. Record the milestone and extend the same codebase.

The aim is to become capable of extending, debugging, measuring, and explaining the project independently.

## Development environment

- **Language:** Modern C++.
- **Initial environment:** Android phone with Termux.
- **Build workflow:** Use the existing `cpp` helper to compile and run source files.
- **Dependencies:** Begin with the C++ standard library. Introduce external libraries only when a feature needs them.
- **Version control:** Use Git commits as milestones and recovery points.
- **Graphics:** Confirm which libraries and display options are practical on the current device before committing to a graphics stack.
- **Machine learning:** Begin after the simulation has stable behaviour and useful data to learn from.

### Initial setup

Create a project directory and a first source file. The exact file layout can remain minimal at first. Avoid setting up a complex build system before there is a reason to need one.

Once a first C++ source file exists, compile and run it using the `cpp` helper already configured in your Termux environment.

## Quality checklist

Before considering a milestone complete, ask:

- [ ] Does each simulation step leave the world in a valid state?
- [ ] Can organisms be added or removed without invalid memory access?
- [ ] Is ownership clear, with no leaks, double deletion, or dangling references?
- [ ] Can the simulation run repeatedly with a fixed random seed for debugging?
- [ ] Are key behaviours testable independently from terminal output or graphics?
- [ ] Are population and resource metrics collected consistently?
- [ ] Does each new feature have a clear purpose and a small, testable milestone?

## First implementation checklist

- [ ] Create the project directory and a single source file for the first prototype.
- [ ] Define the minimum data an `Organism` needs. Keep it small.
- [ ] Create a `World` that contains a population and tracks the current simulation step.
- [ ] Write one function that advances the simulation by one step.
- [ ] Run several steps and print a readable status report.
- [ ] Test with zero organisms, one organism, and several organisms.
- [ ] Only after this works, add energy loss and survival rules.

## Definition of success

Success is not merely a visually impressive simulation. It is a project you understand well enough to extend, debug, measure, and explain.

By the later stages, Artificial World should demonstrate practical C++, data structures, memory safety, mathematics, physics, AI, machine-learning experiments, and disciplined software engineering.

The project should remain usable as a terminal simulation even if graphical development is delayed by device limitations.

---

## Project status

- [x] Project vision and learning roadmap defined
- [ ] Initial terminal prototype
- [ ] Organism and world model
- [ ] Simulation loop and status reporting
- [ ] Ecosystem mechanics
- [ ] Physics and spatial behaviour
- [ ] AI and evolution experiments
- [ ] Machine-learning experiments
- [ ] Visualization and research tools
