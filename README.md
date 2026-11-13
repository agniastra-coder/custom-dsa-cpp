# 🧠 Custom Data Structures & Algorithms (C / C++)

From-scratch implementations of core data structures and optimal algorithmic solutions written in **C** and **C++**, built to master pointer manipulation, manual memory management, and time/space complexity trade-offs without relying exclusively on STL abstractions.

🔗 **LeetCode Profile:** [leetcode.com/u/mr-agniastra](https://leetcode.com/u/mr-agniastra) (170+ Problems Solved)

---

### 📂 Repository Structure

#### `Data-Structures/` (Built From Scratch)
* **`linked_list_queue.cpp`**: Custom pointer-based `Queue` and `QueueNode` implementation featuring `O(1)` `enqueue`/`dequeue`, size tracking, and an explicit `~Queue()` destructor to prevent memory leaks.
* **`array_queue.cpp`**: Contiguous array-backed `Queue` implementation optimized for cache locality and level-indexed BFS traversals.
* **`binary_tree_codec.cpp`**: Preorder DFS tree serialization and deserialization engine using `#` null markers and `std::stringstream` token parsing.
* **`custom_graph.cpp`**: Custom `Graph` class implementation modeling vertex/edge relationships directly in C++.

#### `Algorithms/` (Selected Solutions)
* **`101_symmetric_tree_serialization.c`**: Structural binary tree symmetry check using sentinel-encoded (`-999999`) preorder traversal and recursive subtree inversion.
* **`111_minimum_depth_binary_tree_bfs.cpp`**: Level-order BFS traversal powered by the custom linked-list `Queue` with early leaf-node termination.
* **`297_serialize_deserialize_binary_tree.cpp`**: `O(N)` time & space recursive binary tree codec.
* **`674_longest_continuous_increasing_subsequence.c`**: Single-pass `O(N)` time, `O(1)` space contiguous subarray scan.
* **`1791_find_center_of_star_graph.cpp`**: Graph center identification using custom `Graph` node/edge tracking.

---

### ⚡ How to Compile & Run
Compile any C++ or C file locally using GCC/Clang:
```bash
# For C++ files
g++ -std=c++17 -O2 Data-Structures/binary_tree_codec.cpp -o codec && ./codec

# For C files
gcc -O2 Algorithms/674_longest_continuous_increasing_subsequence.c -o lcis && ./lcis
