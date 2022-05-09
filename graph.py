#%%
import matplotlib.pyplot as plt
import numpy as np
from matplotlib import rcParams

performanceDiffernce1to10 = open("performanceDiff1to10.txt", "r")

performanceDiffernceList = np.zeros(36)
for line in performanceDiffernce1to10.readlines():
    performanceDiffernceList = [a + b for (a, b) in zip(performanceDiffernceList, [float(x) for x in line.strip().split(" ")])]

performanceDiffernceList = [value / 50 for value in performanceDiffernceList]

performanceDiffernce1to10.close()
    
perforamnceInputSize = [pow((3 + i), 2) + 1 for i in range(0, len(performanceDiffernceList))]  
    
rcParams['figure.figsize'] = 12,10

plt.plot(perforamnceInputSize, performanceDiffernceList, marker='o', label="Size vs Performance")

plt.legend(loc="best")
plt.title('Input Size vs Performance')
plt.xlabel('Input Size')
plt.ylabel('Performance')
plt.show()
# %%
import matplotlib.pyplot as plt
from matplotlib import rcParams

performanceDiffernceFile1to100 = open("performanceDiff1to100.txt", "r")

performanceDiffernceList = np.zeros(36)
for line in performanceDiffernceFile1to100.readlines():
    performanceDiffernceList = [a + b for (a, b) in zip(performanceDiffernceList, [float(x) for x in line.strip().split(" ")])]

performanceDiffernceList = [value / 50 for value in performanceDiffernceList]

performanceDiffernceFile1to100.close()
    
perforamnceInputSize = [pow((3 + i), 2) + 1 for i in range(0, len(performanceDiffernceList))]  
    
rcParams['figure.figsize'] = 12,10

plt.plot(perforamnceInputSize, performanceDiffernceList, marker='o', label="Size vs Performance")

plt.legend(loc="best")
plt.title('Input Size vs Performance')
plt.xlabel('Input Size')
plt.ylabel('Performance')
plt.show()

# %%