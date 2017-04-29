import random
import matplotlib.pyplot as plt
import numpy as np
import scipy.integrate as integrate

N_iter = 1000000
#width = 10
#radius = width / 2

#CENTER = [width / 2, width / 2]
rangey = 5*(5**4)-8.7*(5**3)+33*(5**2)+21*5+10.8
actual_area = integrate.quad(lambda x: 5*(x**4)-8.7*(x**3)+33*(x**2)+21*x+10.8, 1, 5)
#print(actual_area)
areaVal = actual_area[0]
print("Actual Area: ", areaVal)


def under_curve(point):
    x = point[0]
    y = point[1]
    #center_x = CENTER[0]
    #center_y = CENTER[1]
    return y < (5*x**4)-(8.7*x**3)+(33*x**2)+(21*x)+10.8


points_under_curve = []
points_out_curve = []

count = count_in = 0

for i in range(N_iter):

    point = [5 * random.random(), rangey * random.random()]

    if under_curve(point):
        points_under_curve.append(point)
        count_in += 1
    else:
        points_out_curve.append(point)

    count += 1

bounds_area = 5*rangey
area = (count_in/count)*bounds_area

print("Area: ", area)

np_under_curve = np.array(points_under_curve)
np_out_curve = np.array(points_out_curve)

plt.figure()
plt.scatter(np_under_curve[:, 0], np_under_curve[:, 1], c='b')
plt.scatter(np_out_curve[:, 0], np_out_curve[:, 1], c='r')
plt.show()


area_bins = []
actual_area_arr = []
area_values = []
x = 10000
step = 10000

N_iters = []

while x <= 1000000:
    N_iters.append(x)
    print(x)
    count = count_in = 0

    for i in range(x):

        point = [5 * random.random(), rangey * random.random()]

        if under_curve(point):
            count_in += 1

        count += 1

    bounds_area = 5 * rangey
    area = (count_in / count) * bounds_area
    area_bins.append([x])
    actual_area_arr.append(areaVal)
    area_values.append(area)

    x = x+step


plt.figure()
plt.plot(area_bins,actual_area_arr, '-r')
plt.plot(N_iters, area_values, '-bx')
plt.xlabel("Number of iterations")
plt.ylabel("Area")
plt.show()