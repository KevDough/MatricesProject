#%%
import matplotlib.pyplot as plt
from matplotlib import rcParams
txt_file = open("performanceDiff.txt", "r")
file_content = txt_file.read()

Performance_Difference = file_content.split("\n")
for i in range(0, len(Performance_Difference)):
    Performance_Difference[i] = float(Performance_Difference[i])

txt_file.close()
#Performance_Difference = [6,2,7,5,4]
arr = Performance_Difference.copy()
Input_Size = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36]
for i in range(0, len(Performance_Difference)):
    Input_Size[i] = pow((3+i),2)+1
rcParams['figure.figsize'] = 12,10
plt.plot(Input_Size, arr)
plt.title('Input Size vs Performance')
plt.xlabel('Input Size')
plt.ylabel('Performance')
plt.show()
# %%
