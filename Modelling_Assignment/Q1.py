import math
import random
import matplotlib.pyplot as plt
from scipy.stats import lognorm
import numpy as np

#sigma and mu of the log-normal distribtion:
sig = 0.75
mu = 0

#limits of t:
a = 0
b = 5

#from the plot of y(t), M was taken to be 1
M = 1

PI = math.pi
binRange = 5

rand_lognormal = np.zeros(100)

# Create an array of 100 bins from 0 to binRange
bins = np.linspace(0,binRange,100)

#save accepted random numbers:
generated_random_numbers = []

# Generate some uniform random numbers and convert them to a log-normal distribution using the accept reject method
for i in range(0, 10000):

    u = a + (b-a)*random.random() #uniform
    v = M*random.random() #h(t)


    f = (1/(u*sig*math.sqrt(2*PI))*math.exp((-(math.log(u-mu))**2)/(2*(sig**2))))


    if v < f:
        for j in range(0, len(bins)):
        
            if u < bins[j]:
            	generated_random_numbers.append(rand_lognormal[j])
            	rand_lognormal[j] += 1
            	break




#show random numbers
plt.figure()
plt.plot(generated_random_numbers, 'x')
plt.title('Generated Random Numbers')
plt.show()


curve = np.linspace(0,binRange,100)
toPlot = lognorm.pdf(curve, sig)

#calculate area:
area = 0
for i in range(1, len(rand_lognormal)):
    area += (bins[i]-bins[i-1]) * rand_lognormal[i]

new_lognormal = [i/area for i in rand_lognormal]


plt.figure()
plt.plot(bins, new_lognormal, 'bx') #rand_lognormal was divided by area to turn into a pdf.
plt.plot(curve,toPlot, 'r-')
plt.ylabel('Number of counts')
plt.xlabel('X, the log-normally distributed random variable')
plt.show()