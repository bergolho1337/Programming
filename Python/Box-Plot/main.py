import numpy as np
import matplotlib.pyplot as plt

# Create some data
value1 = [82,76,24,40,67,62,75,78,71,32,98,89,78,67,72,82,87,66,56,52]
value2=[62,5,91,25,36,32,96,95,3,90,95,32,27,55,100,15,71,11,37,21]
value3=[23,89,12,78,72,89,25,69,68,86,19,49,15,16,16,75,65,31,25,52]
value4=[59,73,70,16,81,61,88,98,10,87,29,72,16,23,72,88,78,99,75,30]
 
# Put all the data inside a list 
box_plot_data=[value1,value2,value3,value4]

# Call the Matplotlib function
plt.boxplot(box_plot_data)
plt.title("Boxplot example")
plt.ylabel("Data value")
plt.xlabel("Data class")
plt.xticks([1,2,3,4],["A","B","C","D"])
plt.show()