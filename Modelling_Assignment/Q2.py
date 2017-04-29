import numpy as np
from operator import itemgetter
from scipy.stats import norm
from matplotlib import pyplot as plt

# State Variables:
Q = 0  # Number of cars
S = 0  # 0 - idle, 1 - busy
NOW = 0  # NOW
expBeta = 2
normMu = 5400
normSig = 60 * 60
queueArray = []

# Initialize Event list:
eventList = []
#To calculate traffic intensity:
interArrivalTimes = []
serviceTimes = []
# Schedule an arrival event:
eventList.append([0, 0])
#schedule a red light at 30:
eventList.append([3, 0])


def arrival():
    global NOW, Q, eventList, S
    global poisslambda, queueArray

    # generate a random number from an exponential distribution with bounds at [1,10]
    rnd_exp = 0
    while rnd_exp < 1 or rnd_exp > 10:
        rnd_exp = np.random.exponential(expBeta)

    div = norm.pdf(NOW/3600,normMu/3600,normSig/3600)
    iat = rnd_exp / div

    interArrivalTimes.append(iat) #for traffic intensities

    eventList.append([0, NOW + iat])
    Q = Q + 1
    queueArray.append([Q, NOW])
    if S == 0:
        eventList.append([1, NOW])


def beginervice():
    global Q, S, expBeta, eventList, NOW, queueArray
    S = 1
    st = 2
    serviceTimes.append(st) # for traffic intensities
    eventList.append([2, NOW + st])
    Q = Q - 1
    queueArray.append([Q, NOW])


def endService():
    global S, NOW, eventList, Q
    S = 0
    if Q > 0:
        # Schedule begin service event at time NOW
        eventList.append([1, NOW])

def redLight():
    global S, NOW, eventList
    S = 1 # set server to busy
    eventList.append([4, NOW + 30]) #schedule green light in 30s
    eventList.append([3,NOW+60]) #schedule stop in 1 minute

def greenLight():
    global S, NOW, eventList
    S = 0 #set server to idle

while NOW < 14400:
    # sort list based on second column:
    eventList.sort(key=itemgetter(1))
    firstEvent = eventList[0]
    NOW = firstEvent[1]

    if firstEvent[0] == 0:  # if event type is arrival
        arrival()
    elif firstEvent[0] == 1:  # if event type is begin service
        beginervice()
    elif firstEvent[0] == 2:  # event type is end Serviece
        endService()
    elif firstEvent[0] == 3:
        redLight()
    elif firstEvent [0] == 4:
        greenLight()
    # Remove first element from list
    del eventList[0]


npQueue = np.array(queueArray)
x = npQueue[:, 1]
y = npQueue[:, 0]

plt.figure()
plt.plot(x, y, 'x')
plt.xlabel("TIME")
plt.ylabel("Q")
plt.title("Road B, pm")
plt.show()


#Traffic Intensity:
avg_iat = sum(interArrivalTimes)/len(interArrivalTimes)
avg_st = sum(serviceTimes)/len(serviceTimes)

trafficIntensity = avg_st/avg_iat
print("Traffic Intensity: ", trafficIntensity)
