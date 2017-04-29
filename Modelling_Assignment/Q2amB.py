import numpy as np
from operator import itemgetter
from scipy.stats import norm
from matplotlib import pyplot as plt

# State Variables:
Q = 0  # Number of cars
S = 0  # 0 - idle, 1 - busy
NOW = 0  # NOW
# poisslambda = 4
expBeta = 2
normMu = 9000
normSig = 60 * 60 * 0.95
# queueArray = [[Q Now]]
queueArray = []

# Initialize Event list:
eventListA = []
#eventListB = []
# Schedule an arrival event:
eventListA.append([0, 0])
#schedule a red light at 0:
eventListA.append([3, 0])
#eventListB.append([30, 0])
# Main Part:
#totalEvents = 10000
#countEvents = 0

#green = 1



def arrivalA():
    global NOW, Q, eventListA, S
    global poisslambda, queueArray
    #seconds = NOW %60
    #print(seconds)
    #if seconds > 30:
    #    green = 0
    #else:
    #    green = 1
    # generate a random number from an exponential distribution with bouds at [1,10]
    rnd_exp = 0
    while rnd_exp < 1 or rnd_exp > 10:
        rnd_exp = np.random.exponential(expBeta)

    div = norm.pdf(NOW / 3600, normMu / 3600, normSig / 3600)
    iat = rnd_exp / div
    #countEvents = countEvents + 1
    eventListA.append([0, NOW + iat])
    # print("iat")
    # print(iat)
    Q = Q + 1
    queueArray.append([Q, NOW])
    if S == 0: #and green == 1:
        eventListA.append([1, NOW])


def beginServiceA():
    global Q, S, expBeta, eventListA, NOW, queueArray
    S = 1
    st = 2
    eventListA.append([2, NOW + st])
    # print("service")
    # print(st)
    Q = Q - 1
    queueArray.append([Q, NOW])


def endServiceA():
    global S, NOW, eventListA, Q#, seconds#, green
    #seconds = NOW % 60
    #if seconds > 30:
    #    green = 0
    #else:
    #    green = 1
    S = 0
    if Q > 0:# and green == 1:
        # Schedule begin service event at time NOW
        eventListA.append([1, NOW])

def redLightA():
    global S, NOW, eventListA
    S = 1 # set server to busy
    eventListA.append([4, NOW + 30]) #schedule green light in 30s
    eventListA.append([3,NOW+60]) #schedule stop in 1 minute

def greenLightA():
    global S, NOW, eventListA
    S = 0 #set server to idle

while NOW < 14400:
    # sort list based on second column:
    eventListA.sort(key=itemgetter(1))
    firstEvent = eventListA[0]
    NOW = firstEvent[1]
    #seconds = NOW%60

    if firstEvent[0] == 0:  # if event type is arrival
        # print("arrival:")
        # print(firstEvent)
        # print(Q)
        arrivalA()
    elif firstEvent[0] == 1:  # if event type is begin service
        # print("begin:")
        # print(firstEvent)
        # print(Q)
        beginServiceA()
    elif firstEvent[0] == 2:  # event type is end Serviece
        # print("end:")
        # print(firstEvent)
        # print(Q)
        endServiceA()
    elif firstEvent[0] == 3:
        redLightA()
    elif firstEvent [0] == 4:
        greenLightA()
    # Remove first element from list
    del eventListA[0]

# print(queueArray)
npQueue = np.array(queueArray)
x = npQueue[:, 1]
y = npQueue[:, 0]
# print(x)
# print(y)
plt.figure()
plt.plot(x, y, 'x')
plt.xlabel("TIME")
plt.ylabel("Q")
plt.title("Road B, am")
plt.show()

