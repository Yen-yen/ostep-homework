#! /usr/bin/env python3

import random

import matplotlib.pyplot as plt
import numpy as np

uList = [0] * 100

for i in range(30):
    random.seed(i)

    for quantum in range(1, 101):
        tickTotal = 200
        runTotal = 200
        jobs = 2
        joblist = [[0, 100, 100], [1, 100, 100]]

        clock = 0
        finishTime = []
        # run jobs
        clock = 0

        for i in range(runTotal):
            r = int(random.random() * 1000001)
            winner = int(r % tickTotal)

            current = 0
            for (job, runtime, tickets) in joblist:
                current += tickets
                if current > winner:
                    (wjob, wrun, wtix) = (job, runtime, tickets)
                    break

            # now do the accounting
            if wrun >= quantum:
                wrun -= quantum
            else:
                wrun = 0

            clock += quantum

            # job completed!
            if wrun == 0:
                tickTotal -= wtix
                wtix = 0
                jobs -= 1
                finishTime.append(clock)

            # update job list
            joblist[wjob] = (wjob, wrun, wtix)

            if jobs == 0:
                break


        u = finishTime[0] / finishTime[1]
        uList[quantum - 1] += u

fig = plt.figure()
x = np.linspace(1, 100, 100)
plt.plot(x, [u / 30 for u in uList], color='orange')
plt.ylim(0, 1)
plt.margins(0)
plt.xlabel('Quantum Size')
plt.ylabel('fairness (Average)')
plt.title('Lottery Fairness Study')
plt.savefig('quantum.png', dpi=227)
plt.show()