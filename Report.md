# Project 3 Report

Answer the following questions directly in this file:
* You will have a different grader again, so make sure your report includes information about your dataset.
  
This dataset is about one thousand asteroids observed by the Jet Propulsion Laboratory of California Institute of Technology. The data includes the asteroids Full Name, Shortened Name, ID, SPK-ID, Magnitude, Diameter, if it’s a near earth object (NEO) and if it is a potential hazard (PHA).


* How do the depths of the random-ordered integers compare to the depths of the ordered integers for each tree? Why?
  
The random ordered integers and the ordered integers have the same depths in my output. It is very likely that this is not supposed to happen. The depths for the random ordered integers should be larger as the randomization would cause a less efficient outcome that needs to be sorted more, especially with the splay and AVL trees. 

  
* How do the depths of each custom-data-type tree compare to each other?
  
The custom data type trees are the same for splay.


* Why do the depths of the second custom-data-type Splay Tree make sense?

* Graph the Binary Search Tree, AVL Tree, and Splay Tree depths for the custom data type trees. Do not use C++ to graph, you can use whatever spreadsheet application or graphical programming language you prefer. You can use whatever graph is most readable to you (e.g. scatter plot, histogram, etc.).
  * Your graphs should have clear labels for both x and y axes.
  * Save your graph files in the graphs folder.
  * You do not need to graph the depths of the integer type trees or the Splay Tree that finds each object 5 times in a row, but you can if you feel it helps you analyze the data.
  * An example graph spreadsheet and an example graph image have been included in the starter code.
  * Here is how you include an image in your Report.md file: ![example graph](graphs/example-graph.png)
* Compare and contrast the graphs and explain the differences based on what you know about the structure and behavior of the trees. Justify the time complexity of searching the trees based on the results.

The BST is simply a linear graph as the value being measured increments by one each time. The AVL depth follows a small exponential curve that starts a one value being depth = two, then two values being depth = 3, four values being depth = 4, eight being 5, 16 being 6, and so on until depth = 10, where the graph flattens. The splay looks like a negative version of the AVL, where it starts at roughly 500 and gets divided by two each iteration until it flattens out between four and ten. The time complexity for the BST is linear (O(N)), as when the data set size doubles, the depth doubles. The time complexity for the AVL is exponential (O(x^2)), as when the data set size doubles, the number of items at depth n+1 doubles. The time complexity for Splay is logarithmic (O(Log(N)) as when the data set is doubled in size, the number of items at depth n+1 halves.


**Note: Any code that was not authored by yourself or the instructor must be cited in your report. This includes the use of concepts not taught in lecture.**

How to shuffle:
(2023). Cplusplus.com. https://cplusplus.com/reference/algorithm/shuffle/ 
