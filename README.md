# Parallel Merge Sort using OpenMP in C

## Overview

This project demonstrates an advanced implementation of the Merge Sort algorithm using parallel processing with OpenMP in C. Merge Sort is a classic divide-and-conquer algorithm that efficiently sorts an array by recursively splitting it into halves and then merging the sorted halves. This implementation takes advantage of modern multi-core processors by parallelizing the sorting process, resulting in significant performance improvements on large datasets.

## Features

- **Parallelized Merge Sort**: Utilizes OpenMP to parallelize the sorting process, making it faster on multi-core systems.
- **Dynamic Depth Control**: Adjusts the level of parallelism based on the available hardware threads, ensuring optimal performance.
- **Scalable**: Capable of handling large arrays with hundreds of thousands of elements efficiently.

## Getting Started

### Prerequisites

To compile and run this code, you will need:

- A C compiler with OpenMP support (e.g., GCC)
- A Linux, macOS, or Windows environment with a compatible compiler installed

### Installation

1. Clone this repository to your local machine:
    ```bash
    git clone https://github.com/yourusername/parallel-merge-sort.git
    ```
2. Navigate to the project directory:
    ```bash
    cd parallel-merge-sort
    ```

### Compilation

To compile the program, use the following command:

```bash
gcc -fopenmp -o parallel_merge_sort parallel_merge_sort.c

Running the Program
Once compiled, you can run the program with:

bash
Copy code
./parallel_merge_sort
The program will generate a large array of random integers, sort it using the parallel merge sort algorithm, and output the time taken for the sorting process.

Customization
You can adjust the size of the array by modifying the n variable in the main function:

c
Copy code
int n = 100000;  // Array size
For demonstration purposes, you can also print the sorted array by uncommenting the print loop in the main function.

Performance
This implementation is designed to take advantage of multi-core systems. The depth of parallelism is dynamically determined based on the number of available threads. The time taken for sorting is displayed at the end of the program execution.

Example Output
bash
Copy code
Time taken: 0.123456 seconds
Contributing
Contributions are welcome! If you find a bug or have an idea for an enhancement, feel free to open an issue or submit a pull request.

License
This project is licensed under the MIT License. See the LICENSE file for details.

Acknowledgments
This project was developed as part of a final-year university course focused on advanced data structures and parallel computing.
Special thanks to the OpenMP community for providing robust tools for parallel programming in C.


### Key Sections:
- **Overview**: Gives a brief description of the project and its purpose.
- **Features**: Highlights the key features of the implementation.
- **Getting Started**: Provides instructions on how to set up and run the project.
- **Performance**: Discusses the performance benefits of using parallel processing.
- **Contributing and License**: Encourages contributions and mentions the licensing terms.

This `README.md` provides a comprehensive guide to understanding, setting up, and running your parallel merge sort project.
