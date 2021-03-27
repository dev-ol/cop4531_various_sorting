# cop4531_various_sorting

Testing different Sorting Algorithms

Implementation of different sorting algorthims:

- insertion sort
- merge sort
- heap sort
- quicksort
- counting sort
- radix sort
- bucket sort

Length of Random numbers to test is stored in file : array_length_tests.txt

Graphing is created by the sorting_graph.py. Inorder to run, install the libraries that is in the requirement.txt file.

## Run

To run each sorting algorithm you compile each file using the command g++ {file}. Afterwards you call the ./a.out or the name of the executable. After running each executable, there will be a file created in the results folder with corresponding x and y values.

To graph each result, you run the <b> sorting_graph.py</b> python file which will create images of each sorting algorithm results from the results folder. Before running the python script, I advise using a virtual environment; download the Matplotlib library which is used to for graphing. Other modules that are need is located in the requirement.txt file.

To change the lenghts of array/random numbers to sort, change or add the amount in the <b>array_length_tests.txt</b> file.

## Create a virtual environment

https://docs.python.org/3/tutorial/venv.html
