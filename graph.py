#%%
import matplotlib.pyplot as plt
from matplotlib import rcParams

performanceDiffernceFile = open("performanceDiff.txt", "r")

performanceDiffernceList = []
for line in performanceDiffernceFile.readlines():
    performanceDiffernceList.append(float(line.strip()))

performanceDiffernceFile.close()
    
perforamnceInputSize = [pow((3 + i), 2) + 1 for i in range(0, len(performanceDiffernceList))]  
    
rcParams['figure.figsize'] = 12,10

plt.plot(perforamnceInputSize, performanceDiffernceList, marker='o', label="Size vs Performance")

plt.legend(loc="best")
plt.title('Input Size vs Performance')
plt.xlabel('Input Size')
plt.ylabel('Performance')
plt.show()
# %%

# %%