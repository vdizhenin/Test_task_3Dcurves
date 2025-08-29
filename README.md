# 3D Curves Hierarchy in C++

## Task Description

Design a small program in C++ that implements support for a hierarchy of 3D curves.

### Functional Requirements
1. Support a few types of 3D geometric curves:
   - **Circle**
   - **Ellipse**
   - **3D Helix**

2. Each curve must be able to:
   - Return a 3D point `C(t)` at a given parameter `t`
   - Return a first derivative vector `C'(t)` at a given parameter `t`

3. Populate a container (`std::vector` or `std::list`) with objects of these types,
   created in a random manner with random parameters.

4. Print coordinates of points and derivatives of all curves in the container at `t = π/4`.

5. Populate a **second container** that contains **only circles** from the first container.
   - Ensure the second container **shares** (does not clone) circles from the first one (via pointers).

6. Sort the second container in ascending order of circle radii.
   - The first element must have the **smallest radius**,
   - The last element must have the **largest radius**.

7. Compute the **total sum of radii** of all circles in the second container.

---

### Optional Requirements ⭐
7. Split the implementation into:
   - A **library** (`.dll` or `.so`) containing the curves hierarchy
   - An **executable** which uses the library API

8. Implement computation of the total sum of radii using **parallel computations**
   (e.g., OpenMP or Intel TBB library).

---

### Implementation Requirements
- Must use **virtual methods**.
- No explicit memory deallocation, no memory leaks.
- Curves must be **physically correct** (e.g., radii must be positive).
- Containers and sorting must be implemented using **STL**.
- May use constructs of **C++11 or higher**.
- The code must compile with **any standard compiler** (gcc, Clang, MSVC).

---

## Build

```bash
# 1. Clone repository
git clone https://github.com/<your-username>/3d-curves.git
cd 3d-curves

# 2. Create build directory
mkdir build && cd build

# 3. Generate project files
cmake -DCMAKE_BUILD_TYPE=Release ..

# 4. Build
cmake --build .
```
---

## Run
```bash
./app/curves_app
```
